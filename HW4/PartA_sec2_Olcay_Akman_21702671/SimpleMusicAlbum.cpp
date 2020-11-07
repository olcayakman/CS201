#include <string>
using namespace std;
#include "SimpleMusicAlbum.h"

MusicAlbum::MusicAlbum(const string maArtist = "", 
                       const string maTitle = "", 
                       const int maYear = 0)
{
    artist = maArtist;
    title = maTitle;
    year = maYear;
}
MusicAlbum::~MusicAlbum() 
{ 
    /*do  have to write sth here??*/ 
}
MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy)
{
    artist = maToCopy.artist;
    title = maToCopy.title;
    year = maToCopy.year;
}
void MusicAlbum::operator = (const MusicAlbum &right)
{
    if ( this != &right )
    {
        this->artist = right.artist;
        this->title = right.title;
        this->year = right.year;
    }
}
string MusicAlbum::getMusicAlbumArtist()
{
    return artist;
}
string MusicAlbum::getMusicAlbumTitle()
{
    return title;
}
int MusicAlbum::getMusicAlbumYear()
{
    return year;
}
