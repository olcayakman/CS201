#include <iostream>
#include "PhoneBook.h"
#include "Person.h"
#include "Phone.h"

using namespace std;

PhoneBook::PhoneBook()
{
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook()
{
    while( head != NULL )
    {
        Node *tmp;
        tmp = head;
        delete head;
        head = tmp->next;
    }
}

PhoneBook::PhoneBook( const PhoneBook& systemToCopy )
{
    if ( systemToCopy.head == NULL )
    {
        this->head = NULL;
        numberOfPeople = 0;
    } 
    else 
    {
        this->head = systemToCopy.head;
        Node *newPtr = this->head;
        for ( Node *origPtr = systemToCopy.head->next;
              origPtr != NULL;
              origPtr = origPtr->next )
        {
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
    }
}

void PhoneBook::operator=( const PhoneBook &right )
{
    if ( right.head == NULL )
    {
        this->head = NULL;
        this->numberOfPeople = 0;
    } else 
    {
        numberOfPeople = right.numberOfPeople;
        this->head = right.head;
        Node *newPtr = right.head;
        for ( Node *origPtr = right.head->next;
              origPtr != NULL;
              origPtr = origPtr->next )
        {
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
    }
}

bool PhoneBook::addPerson( string name)
{
    Node *tail = this->head;
    if ( head == NULL )
    {
        head = new Node;
        head->next = new Node;
        tail = head->next;
        tail->next =  NULL;
        Person *p = new Person(name);
        tail->t = *p;
        return true;
    }
    while ( tail->next != NULL ) 
    {
        tail = tail->next;
        if ( (tail->t).iequals(name) )
            return false;
    }
    tail->next = new Node;
    Person *p = new Person(name);
    (tail->next)->t = *p;
    tail = tail->next;
    tail->next = NULL;
    return true;
}

bool PhoneBook::removePerson( string name )
{
    if ( this->head != NULL && numberOfPeople != 0 )
    {
        Node *prev;
        prev = head->next;
        while ( prev->next != NULL )
        {
            if ( (prev->next)->t.iequals(name) )
            {
                Node *tmp;
                tmp = prev->next;
                prev->next = prev->next->next;
                delete tmp;
                numberOfPeople--;
                return true;
            }
            prev = prev->next;
        }
        if ( prev->t.iequals(name) )
        {
            delete prev;
            numberOfPeople--;
            return true;
        }
    }
    return false;
}

bool PhoneBook::addPhone( string personName, int areaCode, int number )
{
    if ( this->head != NULL && numberOfPeople != 0 )
    {
        Node *tmp;
        tmp = head->next;
        while ( tmp->next != NULL )
        {
            if ( (tmp->next)->t.iequals(personName) )
            {
                //todo
                tmp = tmp->next;
                tmp->t.addPhone(areaCode, number);
                return true;
            }
            tmp = tmp->next;
        }
        if ( tmp->t.iequals(personName) )
        {
            tmp->t.addPhone(areaCode, number);
            return true;
        }
    }
    return false;
}

bool PhoneBook::removePhone(string personName, int areaCode, int number )
{
    if ( this->head != NULL && numberOfPeople != 0 )
    {
        Node *tmp;
        tmp = head->next;
        while ( tmp->next != NULL )
        {
            if ( (tmp->next)->t.iequals(personName) )
            {
                //todo
                tmp = tmp->next;
                tmp->t.removePhone(areaCode, number);
                return true;
            }
            tmp = tmp->next;
        }
        if ( tmp->t.iequals(personName) )
        {
            tmp->t.removePhone(areaCode, number);
            return true;
        }
    }
    return false;
}

void PhoneBook::displayPerson( string name )
{
    if ( this->head != NULL && numberOfPeople != 0 )
    {
        Node *tmp;
        tmp = head->next;
        while ( tmp->next != NULL )
        {
            if ( (tmp->next)->t.iequals(name) )
            {
                //toodo
                tmp->t.displayPhoneNumbers();
            }
            tmp = tmp->next;
        }
        if ( tmp->t.iequals(name) )
        {
            //toodo
            tmp->t.displayPhoneNumbers();
        }
    }
}

void PhoneBook::displayAreaCode( int areaCode )
{
    //todo
}

void PhoneBook::displayPeople()
{
    //toodo
}