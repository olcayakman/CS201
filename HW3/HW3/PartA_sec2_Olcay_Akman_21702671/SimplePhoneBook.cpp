#include <iostream>
#include "SimplePerson.h"
#include "SimplePhoneBook.h"

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
        PersonNode *tmp = head;
        delete head;
        head = tmp->next;
    }
}

PhoneBook::PhoneBook( const PhoneBook &phoneBookToCopy )
{
    if ( phoneBookToCopy.head == NULL )
    {
        this->head = NULL;
        numberOfPeople = 0;
    } 
    else 
    {
        this->head = phoneBookToCopy.head;
        PersonNode *newPtr = this->head;
        for ( PersonNode *origPtr = phoneBookToCopy.head->next;
              origPtr != NULL;
              origPtr = origPtr->next )
        {
            newPtr->next = new PersonNode;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
        numberOfPeople++;
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
        PersonNode *newPtr = right.head;
        for ( PersonNode *origPtr = right.head->next;
              origPtr != NULL;
              origPtr = origPtr->next )
        {
            newPtr->next = new PersonNode;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
    }
}

bool PhoneBook::addPerson( const string name )
{
    PersonNode *tail = this->head;
    if ( head == NULL )
    {
        head = new PersonNode;
        head->next = new PersonNode;
        tail = head->next;
        tail->next =  NULL;
        Person *p = new Person(name);
        tail->t = *p;
        return true;
    } else {
        while ( tail->next != NULL ) 
        {
            tail = tail->next;
            if ( (tail->t).iequals(name) )
                return false;
        }
        tail->next = new PersonNode;
        Person *p = new Person(name);
        (tail->next)->t = *p;
        tail = tail->next;
        tail->next = NULL;
        return true;
    }
}

bool PhoneBook::removePerson(const string name)
{
    if ( this->head != NULL && numberOfPeople != 0 )
    {
        PersonNode *prev;
        prev = head->next;
        while ( prev->next != NULL )
        {
            if ( (prev->next)->t.iequals(name) )
            {
                PersonNode *tmp;
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


void PhoneBook::displayPeople()
{
    if ( head == NULL || head->next == NULL)
    {
        cout<<"--EMPTY--"<<endl;
        return;
    }
    PersonNode *tmp;
    int i = 1;
    cout<<"Contacts: "<<endl;
    for ( tmp = head->next;
          tmp != NULL;
          tmp = tmp->next)
    {
        cout<<i<<". "<<(tmp->t).getName()<<endl;
        i++;
    }
}

// PersonNode* PhoneBook::findPerson( string name )
// {
//     PersonNode *tmp;
//     for ( tmp = head;
//           tmp->next != NULL;
//           tmp = tmp->next)
//     {
//         if ( (tmp->t)->getName() == name )
//             return tmp;
//     }
//     return NULL;
// }