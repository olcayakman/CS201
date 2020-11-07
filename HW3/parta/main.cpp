#include <iostream>
#include "SimplePerson.h"
#include "SimplePhoneBook.h"

using namespace std;

// int  main()
// {
    
//     //todo
//     cout<<"entonces, segimos"<<endl;
//     PhoneBook *pb = new PhoneBook;
//     cout<<"checkpoint1"<<endl;
//     pb->addPerson("Olcay");
//     cout<<"checkpoint2"<<endl;
//     pb->displayPeople();
//     cout<<"checkpoint3"<<endl;
//     pb->removePerson("Olcay");
//     pb->displayPeople();

//     cout<<""<<endl;
//     cout<<"***********"<<endl;
//     cout<<""<<endl;

//     pb->addPerson("Olcay");
//     pb->addPerson("Hande");
//     pb->addPerson("Nisa");
//     pb->addPerson("Eda");
//     pb->addPerson("Ece");
//     pb->addPerson("Nidal");
//     pb->displayPeople();
    
//     return 0;
// }

int main()
{
    cout<<"entonces, segimos"<<endl;
    PhoneBook book;
    PhoneBook face;

    face.addPerson("Ayşe");
    face.addPerson("Mehmet");
    face.addPerson("Mehmet");
    face.displayPeople();
    
    cout<<"checkpoint1"<<endl;

    face.removePerson("Mehmet");
    face.removePerson("Ayşe");  

    face.addPerson("Duck");
    
    cout<<"checkpoint2"<<endl;

    book.addPerson("Bombar");
    book.addPerson("Bombar2");
    book.addPerson("Bombar1");
    book.addPerson("Bombar2");
    book.addPerson("Hamza");
    book.addPerson("Merve");
    book.addPerson("Hüseyin");
    book.addPerson("Hilal");

    cout<<"checkpoint3"<<endl;

    PhoneBook facebook = book;

    cout<<"checkpoint4"<<endl;

    book.displayPeople();

    face.displayPeople();

    facebook.displayPeople();

    facebook = face;

    facebook.displayPeople();

    cout << "END OF TEST" << endl;

    return 0;
}
