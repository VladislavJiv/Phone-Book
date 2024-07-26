/* Created by Jidilev Vladislav*/

#include "phoneHEAD.h"
class PhoneBook {
private:
    vector<Contact*> contacts;

public:
    ~PhoneBook() {
        for (auto contact : contacts) {
            delete contact;
        }
    }

    void addContact(Contact* contact) {
        contacts.push_back(contact);
        cout << "Contact added successfully!" << endl;
    }

    void searchByName(const string& name) const {
        bool found = false;
        for (auto contact : contacts) {
            if (contact->getName() == name) {
                contact->display1();
                found = true;
            }
        }
        if (!found) {
            cout << "Contact with name '" << name << "' not found." << endl;
        }
    }

    void searchByNumber(const string& phoneNumber) const {
        bool found = false;
        for (auto contact : contacts) {
            if (contact->getPhoneNumber() == phoneNumber) {
                contact->display1();
                found = true;
            }
        }
        if (!found) {
            cout << "Contact with phone number '" << phoneNumber << "' not found." << endl;
        }
    }

    void exportToTextFile() const {
        ofstream outputFile("phonebook.txt");
        if (!outputFile.is_open()) {
            cout << "Unable to open file for writing." << endl;
            return;
        }

        for (auto contact : contacts) {
            outputFile << "Contact Details:" << endl;
            outputFile << "----------------" << endl;
            outputFile << "Name: " << contact->getName() << endl;
            outputFile << "Phone Number: " << contact->getPhoneNumber() << endl;
            outputFile << "Address: " << contact->getAddress() << endl;
            outputFile << "Email: " << contact->getEmail() << endl;
            outputFile << endl;
        }

        outputFile.close();
        cout << "Phone book exported to 'phonebook.txt'." << endl;
    }
};


int main() {
    PhoneBook phoneBook;
    int q;
    cout << "#####  ##  ##  ####  ##  ## ##### #####   ####   ####  ##  ##" << endl;
    cout << "##  ## ##  ## ##  ## ### ## ##    ##  ## ##  ## ##  ## ## ## " << endl;
    cout << "#####  ###### ##  ## ## ### ####  #####  ##  ## ##  ## ####  " << endl;
    cout << "##     ##  ## ##  ## ##  ## ##    ##  ## ##  ## ##  ## ## ## " << endl;
    cout << "##     ##  ##  ####  ##  ## ##### #####   ####   ####  ##  ##" << endl;
    
    do {
        cout << endl << "Menu:" << endl;
        cout << "1. Add Personal Contact" << endl;
        cout << "2. Add Professional Contact" << endl;
        cout << "3. Add Friend Contact" << endl;
        cout << "4. Add Family Contact" << endl;
        cout << "5. Search by Name" << endl;
        cout << "6. Search by Phone Number" << endl;
        cout << "7. Export to Text File" << endl;
        cout << "Enter your choice: ";
        cin >> q;

        switch (q) {
        case 1: {
            string name, phoneNumber, address, email;
            cout << endl;
            cout <<"Enter Personal Contact Details:"<< endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Phone Number: ";
            getline(cin, phoneNumber);
            cout << "Address: ";
            getline(cin, address);
            cout << "Email: ";
            getline(cin, email);
            phoneBook.addContact(new PersonalContact(name, phoneNumber, address, email));
            break;
        }
        case 2: {
            string name, phoneNumber, address, email, job;
            cout << endl;
            cout << "Enter Professional Contact Details:"<< endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Phone Number: ";
            getline(cin, phoneNumber);
            cout << "Address: ";
            getline(cin, address);
            cout << "Email: ";
            getline(cin, email);
            cout << "Job: ";
            getline(cin, job);
            phoneBook.addContact(new ProfessionalContact(name, phoneNumber, address, email, job));
            break;
        }
        case 3: {
            string name, phoneNumber, address, email, relationship;
            cout << endl;
            cout << "Enter Friend Contact Details:"<< endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Phone Number: ";
            getline(cin, phoneNumber);
            cout << "Address: ";
            getline(cin, address);
            cout << "Email: ";
            getline(cin, email);
            cout << "Relationship: ";
            getline(cin, relationship);
            phoneBook.addContact(new FriendContact(name, phoneNumber, address, email, relationship));
            break;
        }
        case 4: {
            string name, phoneNumber, address, email, relationship;
            cout << endl;
            cout << "Enter Family Contact Details:"<< endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Phone Number: ";
            getline(cin, phoneNumber);
            cout << "Address: ";
            getline(cin, address);
            cout << "Email: ";
            getline(cin, email);
            cout << "*******************************" << endl;
            cout << "Select Relationship:" << endl;
            cout << "1. Mom" << endl << "2. Dad" << endl << "3. Brother" << endl << "4. Sister" << endl << "5. Son" << endl << "6. Daughter" << endl;
                cout<< "Enter your choice: ";
            int rel;
            cin >> rel;
            switch (rel) {
            case 1:
                relationship = "Mom";
                break;
            case 2:
                relationship = "Dad";
                break;
            case 3:
                relationship = "Brother";
                break;
            case 4:
                relationship = "Sister";
                break;
            case 5:
                relationship = "Son";
                break;
            case 6:
                relationship = "Daughter";
                break;
            default:
                cout << "Invalid choice. Setting relationship to 'Unknown'." << endl;
                relationship = "Unknown";
            }
            FamilyContact* newContact = new FamilyContact(name, phoneNumber, address, email, relationship);
            newContact->setRelationship(relationship);
            phoneBook.addContact(newContact);
            break;
        }
        case 5: {
            string name;
            cout << "--------------------------------" << endl;
            cout << "Enter Name to Search: ";
            cin.ignore();
            getline(cin, name);
            phoneBook.searchByName(name);
            break;
        }
        case 6: {
            string phoneNumber;
            cout << "--------------------------------" << endl;
            cout << "Enter Number to Search: ";
            cin.ignore();
            getline(cin, phoneNumber);
            phoneBook.searchByNumber(phoneNumber);
            break;
        }
        case 7:
            phoneBook.exportToTextFile();
            break;
        
        default:
            cout << "Invalid choice" << endl;
        }
    } while (q != 7);

    return 0;
}