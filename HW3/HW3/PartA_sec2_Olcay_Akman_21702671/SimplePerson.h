#ifndef __SIMPLE_PERSON_H
#define __SIMPLE_PERSON_H
#include <string>

using namespace std;

class Person {
public:
    Person( const string name = "" );
    ~Person();
    Person ( const Person &personToCopy );
    void operator=( const Person &right );
    string getName();
    bool iequals(const string& a);
private:
    string name;
};
#endif