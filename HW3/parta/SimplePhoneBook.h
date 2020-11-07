#ifndef __SIMPLE_PHONEBOOK_H
#define __SIMPLE_PHONEBOOK_H
#include <string>
#include "SimplePerson.h"

using namespace std;

class PhoneBook{
public:
    PhoneBook();
    ~PhoneBook();
    PhoneBook (const PhoneBook& phoneBookToCopy);
    void operator=(const PhoneBook& right);
    bool addPerson(const string name);
    bool removePerson(const string name);
    void displayPeople();
private:
    struct PersonNode {
        Person t;
        PersonNode* next;
    };
    PersonNode *head;
    int numberOfPeople;
    PersonNode* findPerson(string name);
};
#endif