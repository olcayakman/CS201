#include <iostream>
#include <string>

#include "Song.h"

Song::Song(const string sName = "", 
           const int sMins = 0, 
           const int sSecs = 0 )
{
    name = sName;
    mins = sMins;
    secs = sSecs;
}

Song::~Song()
{
    //wut do we write here
}

Song::Song(const Song &songToCopy)
{
    
    name = songToCopy.name;
    mins = songToCopy.mins;
    secs = songToCopy.secs;
}

void Song::operator=(const Song &right)
{
    if ( this != &right )
    {
        name = right.name;
        mins = right.mins;
        secs = right.secs;
    }
}

string Song::getSongName()
{
    return name;
}

int Song::getSongMins()
{
    return mins;
}

int Song::getSongSecs()
{
    return secs;
}