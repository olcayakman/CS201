// #include <iostream>
// #include <string>
// #include "SimpleMAC.h"
// #include "SimpleMusicAlbum.h"

// using namespace std;


// int main()
// {

//     cout<<"im creating some msuic albums now.. kinda unecessary."<<endl;
//     cout<<"=========="<<endl;

//     MusicAlbum *album1 = new MusicAlbum("State Champs", "Living Proof", 2018);
//     MusicAlbum *album2 = new MusicAlbum("Jack & Jack", "Gone", 2017);
//     MusicAlbum *album3 = new MusicAlbum("Cody Simpson", "Wave Two", 2018);

//     cout<<" "<<endl;
//     cout<<"now creating the MAC and then adding three albums in"<<endl;

//     MAC *albumCollection = new MAC();

//     cout<<"got the albumCollection object.. we good??"<<endl;
//     albumCollection->addMusicAlbum("State Champs", "Living Proof", 2018);
//     cout<<"so tell me baby, do we have our first album in?"<<endl;
//     albumCollection->addMusicAlbum("Jack & Jack", "Gone", 2017);
//     cout<<"second album in.."<<endl;
//     albumCollection->addMusicAlbum("Cody Simpson", "Wave Two", 2018);
//     cout<<"third album put in already!"<<endl;

//     cout<<" "<<endl;

//     cout<<"imma display em now here we goo"<<endl;
//     cout<<" "<<endl;

//     MusicAlbum *allAlbums;
//     int x = albumCollection->getMusicAlbums(allAlbums);
//     cout<<"albumCollection->getMusicAlbums(allAlbums);"<<x<<endl;
//     cout<<"all albums!!! "<<endl;
//     for (int i = 0; i < x; i++)
//     {
//         cout<<"Album no "<<i + 1<<": "<<allAlbums[i].getMusicAlbumTitle()<<endl;
//     }

//     cout<<" "<<endl;
//     cout<<"========="<<endl;
//     cout<<"soo... did we do any good?"<<endl;

//     //===========================================

//     cout<<"yeap. im proud:)"<<endl;
//     cout<<"==============="<<endl;
//     cout<<""<<endl;

//     cout<<"so now i'll delete some stuff from this MAC."<<endl;
//     cout<<"k i'll delete the album by Jack & Jack "<<endl;

//     albumCollection->removeMusicAlbum("Jack & Jack", "Gone");

//     cout<<"deleted it already... now let's see if we can display it"<<endl;

//     x = albumCollection->getMusicAlbums(allAlbums);
//     for (int i = 0; i < x; i++)
//     {
//         cout<<"Album no "<<i + 1<<": "<<allAlbums[i].getMusicAlbumTitle()<<endl;
//     }
//     cout<<"are we still alive at this point??";

//     cout<<""<<endl;
//     cout<<"============="<<endl;
//     cout<<""<<endl;

//     cout<<"now the final touch... lets see our copy const!"<<endl;
//     cout<<""<<endl;

//     MAC *myMAC = new MAC();
//     myMAC = new MAC(*albumCollection);

//     cout<<"print out the albums of myMAC copy of albumCollection"
//         <<" copied by using the copy const "<<endl;

//     x = myMAC->getMusicAlbums(allAlbums);
//     for (int i = 0; i < x; i++)
//     {
//         cout<<"Album no "<<i + 1<<": "<<allAlbums[i].getMusicAlbumTitle()<<endl;
//     }
//     cout<<""<<endl;
//     cout<<"soo... i guess we're done?"<<endl;



//     // cout<<"les see da copy const"<<endl;
//     // cout<<" "<<endl;

//     // MusicAlbum *myAlbum = new MusicAlbum("Cody Simpson", "Free", 2015);
//     // MusicAlbum *copiedAlbum = new MusicAlbum(*myAlbum);
//     // cout<<"myAlbum->getMusicAlbumArtist() "<<myAlbum->getMusicAlbumArtist()<<endl;
//     // cout<<"myAlbum->getMusicAlbumTitle() "<<myAlbum->getMusicAlbumTitle()<<endl;
//     // cout<<"myAlbum->getMusicAlbumYear() "<<myAlbum->getMusicAlbumYear()<<endl;

//     // cout<<" "<<endl;
//     // cout<<"and the copied one..."<<endl;
//     // cout<<" "<<endl;

//     // cout<<"copiedAlbum->getMusicAlbumArtist() "<<copiedAlbum->getMusicAlbumArtist()<<endl;
//     // cout<<"copiedAlbum->getMusicAlbumTitle() "<<copiedAlbum->getMusicAlbumTitle()<<endl;
//     // cout<<"copiedAlbum->getMusicAlbumYear() "<<copiedAlbum->getMusicAlbumYear()<<endl;

//     // cout<<"========================="<<endl;

//     // cout<<" "<<endl;
//     // cout<<"now lets see the assignmet (=) operator overload..."<<endl;
//     // cout<<" "<<endl;

//     // MusicAlbum *album1 = new MusicAlbum("Selena Gomez", "When The Sun Goes Down", 2015);
//     // MusicAlbum *album2 = new MusicAlbum("Justin Bieber", "Believe", 2017);
//     // cout<<"album1: "<<album1->getMusicAlbumArtist()<<" "<<album1->getMusicAlbumTitle()<<" "<<album1->getMusicAlbumYear()<<endl;
//     // cout<<"album2: "<<album2->getMusicAlbumArtist()<<" "<<album2->getMusicAlbumTitle()<<" "<<album2->getMusicAlbumYear()<<endl;
//     // *album1 = *album2;
//     // cout<<"after assigning album2 to album1 we get: "<<endl;
//     // cout<<"album1: "<<album1->getMusicAlbumArtist()<<" "<<album1->getMusicAlbumTitle()<<" "<<album1->getMusicAlbumYear()<<endl;
//     // cout<<"album2: "<<album2->getMusicAlbumArtist()<<" "<<album2->getMusicAlbumTitle()<<" "<<album2->getMusicAlbumYear()<<endl;

//     return 0;
// }


#include <iostream>
using namespace std;
#include "SimpleMusicAlbum.h"
#include "SimpleMAC.h"

void displayAllMusicAlbums(MAC mac)
{
    cout<<"fnc checkpoint0"<<endl;
    MusicAlbum *allMusicAlbums;
    int noOfMusicAlbums = mac.getMusicAlbums(allMusicAlbums);
    cout<<"fnc checkpoint1"<<endl;
    cout <<"No of music albums: "<< noOfMusicAlbums << endl;
    for (int i = 0; i < noOfMusicAlbums; i++){
        cout << allMusicAlbums[i].getMusicAlbumArtist() <<", "
             << allMusicAlbums[i].getMusicAlbumTitle() <<" ("
             << allMusicAlbums[i].getMusicAlbumYear() <<")"
             << endl;
    }
    cout<<"fnc checkpoint2"<<endl;
    if (allMusicAlbums != NULL)
        delete [] allMusicAlbums;
    cout<<"fnc checkpount3"<<endl;
}

int main()
{
    cout<<"i cry w my little eye"<<endl;
    MAC m;
    m.addMusicAlbum("John Coltrane", "My Favorite Things", 1961);
    if (m.addMusicAlbum("John Coltrane", "A Love Supreme", 1965))
        cout << "Successful insertion of John Coltrane, "
             << "A Love Supreme (1965)" << endl;
    else
        cout << "Unsuccessful insertion of John Coltrane, "
             << "A Love Supreme (1965)" << endl;
    m.addMusicAlbum("Jethro Tull", "Thick As A Brick", 1972);
    cout<<"ekledikmi1"<<endl;
    m.addMusicAlbum("Mike Oldfield", "Tubular Bells", 1973);
    cout<<"ekledikmi2"<<endl;
    m.addMusicAlbum("Pink Floyd", "The Dark Side of the Moon", 1973);
    cout<<"ekledikmi3"<<endl;
    cout<<"test"<<endl;
    MusicAlbum *allAlbums;
    int x = m.getMusicAlbums(allAlbums);
    for (int i = 0; i < x; i++)
    {
        cout<<allAlbums[i].getMusicAlbumTitle()<<endl;
    }
    displayAllMusicAlbums(m);
    cout<<"test2"<<endl;
    if (m.removeMusicAlbum("John Coltrane", "Giant Steps"))
        cout << "Successful deletion of John Coltrane, "
             << "Giant Steps" << endl;
    else
        cout << "Unsuccessful deletion of John Coltrane, "
             << "Giant Steps" << endl;
    if(allAlbums) delete[] allAlbums;
    return 0;
}