#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "a2_nodes.h"
#include "a2_functions.h"

#define MAX_USERNAME_LEN 100
#define MAX_PASSWORD_LEN 16
#define MAX_POST_LEN 250
#define MAX_FRIEND_NAME_LEN 100

void display_banner();
void handle_user_creation(user_t **users);
void handle_login(user_t *users);
void manage_user_session(user_t *current_user, user_t *users);

int main() {
    display_banner();
    FILE *csv_file = fopen("user_details.csv", "r");
    if (!csv_file) {
        perror("Error opening the CSV file");
        return EXIT_FAILURE;
    }
    user_t *users = read_CSV_and_create_users(csv_file, 50);
    fclose(csv_file);

    printf("\nWelcome to Text-Based Facebook!\n");

    while (true) {
        printf("\nMain Menu:\n1. Create a new user\n2. Log in\n3. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handle_user_creation(&users);
                break;
            case 2:
                handle_login(users);
                break;
            case 3:
                printf("Goodbye!\n");
                teardown(users);
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void display_banner() {
    printf(" **********************\n");
    printf("********        ********\n");
    printf("*******   **************\n");
    printf("*******   **************\n");
    printf("***             ********\n");
    printf("*******   **************\n");
    printf("*******   **************\n");
    printf("*******   **************\n");
    printf("*******   **************\n");
    printf(" ******   *************\n");
}

void handle_user_creation(user_t **users) {
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    printf("\nEnter a username: ");
    scanf("%s", username);
    
    if (find_user(*users, username)) {
        printf("Username already exists. Choose another.\n");
        return;
    }
    
    do {
        printf("Enter a password (8-15 characters): ");
        scanf("%s", password);
    } while (strlen(password) < 8 || strlen(password) > 15);
    
    *users = add_user(*users, username, password);
    assert(*users != NULL);
    printf("User created successfully!\n");
}

void handle_login(user_t *users) {
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    printf("\nUsername: ");
    scanf("%s", username);
    
    user_t *current_user = find_user(users, username);
    if (!current_user) {
        printf("User not found. Try again.\n");
        return;
    }
    
    printf("Password: ");
    scanf("%s", password);
    
    if (strcmp(password, current_user->password) != 0) {
        printf("Incorrect password. Returning to main menu.\n");
        return;
    }
    
    printf("\nWelcome back, %s!\n", username);
    manage_user_session(current_user, users);
}

void manage_user_session(user_t *current_user, user_t *users) {
    while (true) {
        print_menu();
        printf("Enter your choice (1-6): ");
        int choice = get_input_usi();

        switch (choice) {
            case 1:
                printf("Logging out.\n");
                return;
            case 2:
                printf("Enter current password: ");
                char password[MAX_PASSWORD_LEN];
                scanf("%s", password);
                if (strcmp(current_user->password, password) == 0) {
                    printf("Enter new password: ");
                    scanf("%s", current_user->password);
                    printf("Password updated successfully.\n");
                } else {
                    printf("Incorrect password.\n");
                }
                break;
            case 3:
                printf("Enter post content: ");
                char post_content[MAX_POST_LEN];
                scanf(" %[^\n]s", post_content);
                add_post(current_user, post_content);
                break;
            case 4:
                printf("Enter friend's username: ");
                char friend_name[MAX_FRIEND_NAME_LEN];
                scanf("%s", friend_name);
                if (find_user(users, friend_name)) {
                    add_friend(current_user, friend_name);
                    printf("Friend added successfully!\n");
                } else {
                    printf("User not found.\n");
                }
                break;
            case 5:
                display_all_user_posts(current_user);
                break;
            case 6:
                printf("Returning to main menu.\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

