/*Created by Jidilev Vladislav*/



#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Contact {
protected:
    string name;
    string phoneNumber;
    string address;
    string email;

public:
    Contact(const string& n, const string& ph, const string& add, const string& e)
        : name(n), phoneNumber(ph), address(add), email(e) {}

    virtual void display1() const {
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
    }

    string getName() const { 
        return name; 
    }
    string getPhoneNumber() const { 
        return phoneNumber; 
    }
    string getAddress() const {
        return address; 
    }
    string getEmail()const { 
        return email; 
    }
};

class PersonalContact : public Contact {
public:
    PersonalContact(const string& n, const string& ph, const string& add, const string& e)
        : Contact(n, ph, add, e) {}

    void display1() const override {
        cout << "Personal Contact Details:" << endl;
        Contact::display1();
    }
};

class ProfessionalContact : public Contact {
private:
    string job;

public:
    ProfessionalContact(const string& n, const string& ph, const string& add, const string& e, const string& j)
        : Contact(n, ph, add, e), job(j) {}

    void display1() const override {
        cout << "Professional Contact Details:" << endl;
        Contact::display1();
        cout << "Job: " << job << endl;
    }
};

class FriendContact : public PersonalContact {
private:
    string relationship;

public:
    FriendContact(const string& n, const string& ph, const string& add, const string& e, const string& rel)
        : PersonalContact(n, ph, add, e), relationship(rel) {}

    void display1() const override {
        cout << "Friend Contact Details:" << endl;
        PersonalContact::display1();
        cout << "Relationship: " << relationship << endl;
    }
};

class FamilyContact : public PersonalContact {
private:
    string relationship;

public:
    FamilyContact(const string& n, const string& ph, const string& add, const string& e, const string& rel)
        : PersonalContact(n, ph, add, e), relationship(rel) {}

    void display1() const override {
        cout << "Family Contact Details:" << endl;
        PersonalContact::display1();
        cout << "Relationship: " << relationship << endl;
    }

    void setRelationship(const string& rel) {
        relationship = rel;
    }

};
