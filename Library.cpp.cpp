#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

// ========== Abstract Base Class ==========
class LibraryItem {
protected:
    string id;
    string title;
    string author;
    bool   isAvailable;

public:
    LibraryItem(string i, string t, string a)
        : id(i), title(t), author(a), isAvailable(true) {}

    virtual ~LibraryItem() {}

    string getId() const { return id; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

// ========== Derived classes ==========

class Book : public LibraryItem {
    int pages;
public:
    Book(string i, string t, string a, int p)
        : LibraryItem(i, t, a), pages(p) {}

    void checkOut() {
        if (!isAvailable)
            cout << "Book already checked out.\n";
        else {
            isAvailable = false;
            cout << "Book checked out.\n";
        }
    }

    void returnItem() {
        if (isAvailable)
            cout << "Book is already in library.\n";
        else {
            isAvailable = true;
            cout << "Book returned.\n";
        }
    }

    void displayDetails() const {
        cout << "[BOOK] " << id << " | " << title
             << " | " << author
             << " | pages: " << pages
             << " | " << (isAvailable ? "Available" : "Not available")
             << endl;
    }
};

class DVD : public LibraryItem {
    int duration;
public:
    DVD(string i, string t, string a, int d)
        : LibraryItem(i, t, a), duration(d) {}

    void checkOut() {
        if (!isAvailable)
            cout << "DVD already checked out.\n";
        else {
            isAvailable = false;
            cout << "DVD checked out.\n";
        }
    }

    void returnItem() {
        if (isAvailable)
            cout << "DVD is already in library.\n";
        else {
            isAvailable = true;
            cout << "DVD returned.\n";
        }
    }

    void displayDetails() const {
        cout << "[DVD ] " << id << " | " << title
             << " | " << author
             << " | duration: " << duration << " min"
             << " | " << (isAvailable ? "Available" : "Not available")
             << endl;
    }
};

class Magazine : public LibraryItem {
    int issue;
public:
    Magazine(string i, string t, string a, int iss)
        : LibraryItem(i, t, a), issue(iss) {}

    void checkOut() {
        if (!isAvailable)
            cout << "Magazine already checked out.\n";
        else {
            isAvailable = false;
            cout << "Magazine checked out.\n";
        }
    }

    void returnItem() {
        if (isAvailable)
            cout << "Magazine is already in library.\n";
        else {
            isAvailable = true;
            cout << "Magazine returned.\n";
        }
    }

    void displayDetails() const {
        cout << "[MAG ] " << id << " | " << title
             << " | " << author
             << " | issue: " << issue
             << " | " << (isAvailable ? "Available" : "Not available")
             << endl;
    }
};

// ========== Library class using array of pointers ==========
class Library {
    LibraryItem* items[MAX_ITEMS];
    int count;

public:
    Library() : count(0) {
        for (int i = 0; i < MAX_ITEMS; ++i)
            items[i] = NULL;
    }

    ~Library() {
        for (int i = 0; i < count; ++i) {
            delete items[i];
        }
    }

    void addItem(LibraryItem* item) {
        if (count >= MAX_ITEMS) {
            cout << "Library is full, cannot add more items.\n";
            delete item; // avoid leak
            return;
        }
        items[count] = item;
        count++;
        cout << "Item added.\n";
    }

    LibraryItem* findById(const string& id) {
        for (int i = 0; i < count; ++i) {
            if (items[i]->getId() == id)
                return items[i];
        }
        return NULL;
    }

    void displayAll() const {
        if (count == 0) {
            cout << "No items in library.\n";
            return;
        }
        for (int i = 0; i < count; ++i) {
            items[i]->displayDetails();
        }
    }
};

// ========== Menu ==========

void showMenu() {
    cout << "\n===== Library Management System =====\n";
    cout << "1. Add Book\n";
    cout << "2. Add DVD\n";
    cout << "3. Add Magazine\n";
    cout << "4. Display all items\n";
    cout << "5. Check out item\n";
    cout << "6. Return item\n";
    cout << "7. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    Library lib;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n";
            continue;
        }

        if (choice == 7) {
            cout << "Exiting...\n";
            break;
        }

        string id, title, author;
        int num;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter pages: ";
            cin >> num;
            lib.addItem(new Book(id, title, author, num));
            break;

        case 2:
            cout << "Enter DVD ID: ";
            cin >> id;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Director: ";
            getline(cin, author);
            cout << "Enter duration (min): ";
            cin >> num;
            lib.addItem(new DVD(id, title, author, num));
            break;

        case 3:
            cout << "Enter Magazine ID: ";
            cin >> id;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Publisher: ";
            getline(cin, author);
            cout << "Enter issue number: ";
            cin >> num;
            lib.addItem(new Magazine(id, title, author, num));
            break;

        case 4:
            lib.displayAll();
            break;

        case 5: {
            cout << "Enter ID to check out: ";
            cin >> id;
            LibraryItem* item = lib.findById(id);
            if (item) item->checkOut();
            else cout << "Item not found.\n";
            break;
        }

        case 6: {
            cout << "Enter ID to return: ";
            cin >> id;
            LibraryItem* item = lib.findById(id);
            if (item) item->returnItem();
            else cout << "Item not found.\n";
            break;
        }

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
