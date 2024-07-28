
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    void viewContacts() const {
        if (contacts.empty()) {
            cout << "No contacts available." << endl;
            return;
        }

        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << "Contact " << i + 1 << ":" << endl;
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone: " << contacts[i].phone << endl;
            cout << "Email: " << contacts[i].email << endl;
            cout << "----------------------" << endl;
        }
    }

    void updateContact(size_t index, const Contact& contact) {
        if (index < 1 || index > contacts.size()) {
            cout << "Invalid contact index." << endl;
            return;
        }
        contacts[index - 1] = contact;
    }

    void deleteContact(size_t index) {
        if (index < 1 || index > contacts.size()) {
            cout << "Invalid contact index." << endl;
            return;
        }
        contacts.erase(contacts.begin() + index - 1);
    }
};

int main() {
    ContactManager manager;
    int choice;

    do {
        cout << "\nContact Manager System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Update Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Contact contact;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, contact.name);
                cout << "Enter phone: ";
                getline(cin, contact.phone);
                cout << "Enter email: ";
                getline(cin, contact.email);
                manager.addContact(contact);
                break;
            }
            case 2:
                manager.viewContacts();
                break;
            case 3: {
                size_t index;
                Contact contact;
                cout << "Enter contact index to update: ";
                cin >> index;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, contact.name);
                cout << "Enter new phone: ";
                getline(cin, contact.phone);
                cout << "Enter new email: ";
                getline(cin, contact.email);
                manager.updateContact(index, contact);
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter contact index to delete: ";
                cin >> index;
                manager.deleteContact(index);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
