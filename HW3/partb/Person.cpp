#include "Phone.h"
#include "Person.h"
#include <iostream>

using namespace std;

Person::Person( string name )
{
    this->name = name;
}

Person::~Person()
{
    //todo
}

void Person::operator=( const Person &rigth )
{
    if ( right.head == NULL )
    {
        this->head = NULL;
    } else 
    {
        this->head = right.head;
        PhoneNode *newPtr = right.head;
        for ( PhoneNode *origPtr = right.head->next;
              origPtr != NULL;
              origPtr = origPtr->next )
        {
            newPtr->next = new PhoneNode;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
    }
}

string Person::getName()
{
    return name;
}

bool Person::addPhone(const int areaCode, const int number )
{
    PhoneNode *tail = this->head;
    if ( head == NULL )
    {
        head = new PhoneNode;
        head->next = new PhoneNode;
        tail = head->next;
        tail->next =  NULL;
        Phone *p = new Phone(areaCode, number);
        tail->p = *p;
        return true;
    }
    while ( tail->next != NULL ) 
    {
        tail = tail->next;
        if ( tail->p.getNumber() == number && tail->p.getAreaCode() == areaCode )
            return false;
    }
    tail->next = new PhoneNode;
    Phone *p = new Phone(areaCode, number);
    (tail->next)->p = *p;
    tail = tail->next;
    tail->next = NULL;
    return true;
}

bool Person::removePhone( const int areaCode, const int number)
{
    if ( this->head != NULL )
    {
        PhoneNode *prev;
        prev = head->next;
        while ( prev->next != NULL )
        {
            if ( prev->p.getNumber() == number && prev->p.getAreaCode() == areaCode )
            {
                PhoneNode *tmp;
                tmp = prev->next;
                prev->next = prev->next->next;
                delete tmp;
                return true;
            }
            prev = prev->next;
        }
        if ( prev->p.getNumber() == number && prev->p.getAreaCode() == areaCode )
        {
            delete prev;
            return true;
        }
    }
    return false;
}

void Person::displayPhoneNumbers()
{
    if ( head == NULL || head->next == NULL)
    {
        cout<<"--EMPTY--"<<endl;
        return;
    }
    PhoneNode *tmp;
    int i = 1;
    cout<<"Phone Numbers of "<<this->getName()<<": "<<endl;
    for ( tmp = head->next;
          tmp != NULL;
          tmp = tmp->next)
    {
        cout<<"Phone Number "<<i<<". "<<tmp->p.getAreaCode()<<tmp->p.getNumber()<<endl;
        i++;
    }
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

// PhoneNode* Person::findPhone( const int areaCode, const int number )
// {
//     //todo
// }