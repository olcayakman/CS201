#include <iostream>
#include "SimplePerson.h"
using namespace std;

Person::Person( string name )
{
    this->name = name;
}

Person::~Person() { }

Person::Person( const Person &personToCopy )
{
    name = personToCopy.name;
}

void Person::operator=( const Person &right )
{
    this->name = right.name;
}

string Person::getName()
{
    return name;
}

bool Person::iequals(const string& a)
{
    unsigned int sz = a.size();
    if ((this->name).size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
    {
        if (tolower(a[i]) != tolower((this->name)[i]))
            return false;
    }
    return true;
}