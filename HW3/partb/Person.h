#ifndef __PERSON_H
#define __PERSON_H

#include <string>

using namespace std;

class Person{
public:
    Person( const string name = "" );
    ~Person();
    Person( const Person& personToCopy );
    void operator=( const Person &right );
    string getName();
    bool addPhone( const int areaCode, const int number );
    bool removePhone( const int areaCode, const int number );
    void displayPhoneNumbers();
    bool iequals(const string& a);
private:
    struct PhoneNode {
        Phone p;
        PhoneNode* next;
    };
    PhoneNode *head;
    string name;
    PhoneNode* findPhone( const int areaCode, const int number );
};
#endif