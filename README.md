# Address Book Management System in C

A menu-driven Address Book Management System developed in **C** to manage contact information using structures, modular programming, and file handling.

## Features

* **Create Contacts** – Add a contact with a name, phone number, and email address.
* **Search Contacts** – Find contacts using their name, phone number, or email address.
* **Edit Contacts** – Search for an existing contact and update its details.
* **Delete Contacts** – Remove contacts from the address book.
* **List Contacts** – Display all saved contacts in alphabetical order by name.
* **File Handling** – Save contacts to a text file and load them when the application starts.
* **Input Validation** – Includes basic checks for phone number length and the presence of `@` in email addresses.
* **Fixed Capacity** – Supports up to 100 contacts.

## Technologies Used

* C Programming
* Structures
* Functions and modular programming
* Arrays and strings
* File handling
* Standard C libraries

## Project Structure

```text
Address-Book/
├── main.c        # Main function and menu-driven interface
├── contact.c     # Contact creation, search, edit, delete and listing
├── contact.h     # Contact structures and function declarations
├── file.c        # Loading and saving contacts
├── file.h        # File-handling function declarations
├── populate.c    # Predefined sample contact data
├── populate.h    # Sample data population function declaration
├── contacts.txt  # File used to store contact information
└── .gitignore    # Files excluded from version control
```

## Getting Started

### Prerequisites

* GCC compiler
* Linux, WSL, or another environment with a C compiler
* Terminal or command-line interface

### Compilation

Clone the repository:

```bash
git clone https://github.com/aswinrajendrann/Address-Book.git
cd Address-Book
```

Compile the source files:

```bash
gcc main.c contact.c file.c populate.c -o addressbook
```

### Run the Application

```bash
./addressbook
```

## Menu Options

When the application starts, the following menu is displayed:

```text
Addressbook Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contact
6. Save contact
7. Exit
```

Enter the corresponding number to perform an operation.

## Data Storage

Contacts are stored in `contacts.txt`. The file contains the total number of contacts followed by each contact's name, phone number, and email address, separated by the `|` character.

The application loads the saved contacts during initialization. Use the **Save contact** menu option to save the current contact list.

## Concepts Demonstrated

This project demonstrates the practical use of:

* Structures for organizing contact information
* Functions for separating application responsibilities
* Arrays for storing multiple contacts
* String operations for searching and sorting
* File handling for persistent storage
* Header files for organizing declarations across multiple source files

## Author

**Aswin Rajendran**

GitHub: [aswinrajendrann](https://github.com/aswinrajendrann)

---

*This project was developed to practise C programming concepts through a practical, menu-driven application.*
