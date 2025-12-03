Project

📚 Project Overview
This repository contains a simple console-based Library Management System written in C++, designed to demonstrate core Object-Oriented Programming concepts such as abstraction, inheritance, polymorphism, encapsulation, and pointer-to-object usage.​

The system allows users to manage different types of library items (Books, DVDs, Magazines), perform basic operations via a menu-driven interface, and handle items using an array of base-class pointers.​

✨ Features
🧩 Abstract base class LibraryItem with pure virtual functions

📖 Derived classes: Book, DVD, Magazine

🧠 Polymorphism using LibraryItem* pointers and virtual methods

🔐 Encapsulated data members with controlled access

📋 Menu-driven console interface for user interaction

➕ Add items (Book/DVD/Magazine) up to a fixed limit

✅ Check-out and return items using their ID

👀 Display all items with their availability status

🏗️ OOP Concepts Used
Abstraction:

LibraryItem is an abstract base class with pure virtual methods checkOut(), returnItem(), and displayDetails().​

Inheritance:

Book, DVD, and Magazine publicly inherit from LibraryItem.​

Polymorphism:

Array LibraryItem* items[MAX_ITEMS]; stores pointers to different derived types and calls virtual functions through the base pointer.​

Encapsulation:

Core item details (id, title, author, isAvailable) are kept inside classes with controlled access through member functions.​

Pointer Objects:

Objects are created dynamically using new and managed via base-class pointers, with cleanup in the Library destructor.​

▶️ How to Run
Clone the repository:

git clone https://github.com/<your-username>/cpp-library-management.git

Navigate into the project folder:

cd cpp-library-management

Compile the program (examples):

g++ main.cpp -o library

Run:

./library (Linux/macOS)

library.exe (Windows)

Use the on-screen menu to:

1️⃣ Add Book

2️⃣ Add DVD

3️⃣ Add Magazine

4️⃣ Display all items

5️⃣ Check out item by ID

6️⃣ Return item by ID

7️⃣ Exit

📂 File Structure (Suggested)
main.cpp – Full source code for the Library Management System

README.md – Project documentation

LICENSE (optional) – License information for the project

🤝 Contribution & Future Improvements
Possible improvements:

💾 Save and load data from files

🔍 Search by title/author

🕒 Due dates and fines

✅ Better input validation and error messages

Contributions, issues, and suggestions are welcome. Feel free to fork the repo, open pull requests, or create issues to enhance the project.​

📛 Author
Created by a C++ and full‑stack development learner, focusing on building strong fundamentals in OOP and clean console applications.​

Rel
