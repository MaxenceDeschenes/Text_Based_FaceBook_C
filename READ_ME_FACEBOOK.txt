Facebook-Inspired Text-Based Social Network

Overview
This project is a text-based social networking application that simulates a simplified version of Facebook. Users can create accounts, log in, manage their profiles, add friends, and create or delete posts. The system maintains user data using a linked list structure and loads existing user details from a CSV file. The application ensures secure user authentication and organizes posts in a stack-like manner.

How It Works
- Users can register with a unique username and password.
- Login allows users to manage their profile.
- Users can add and remove friends.
- Users can create and delete posts.
- Posts from other users can be viewed.

Modules and Components
User Management:
- Register and log in using a username and password.
- Passwords must be between 8-15 characters.
- User data is stored in a linked list.

Friends System:
- Users can add or remove friends.
- Friends are stored in a sorted linked list.

Post System:
- Posts are stored in a stack-based structure.
- Users can create and delete posts.

CSV-Based User Data Storage:
- Users and their data are loaded from a CSV file.
- Changes are dynamically updated in memory.

System Behavior
1. Users start by registering or logging in.
2. Once logged in, they can:
   - Manage posts.
   - Add or remove friends.
   - Update their password.
   - Log out when done.
3. Posts and friend lists update dynamically.

Requirements
- Programming Language: C
- Development Tools: GCC, Clang, or any C compiler
- Libraries Used: stdio.h, stdlib.h, string.h, stdbool.h

Installation & Execution
1. Clone the Repository:
   git clone https://github.com/your-repo/facebook-text-based.git
   cd facebook-text-based

2. Compile the Code:
   gcc main.c a2_functions.c -o facebook

3. Run the Program:
   ./facebook



