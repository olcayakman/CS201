#include <string>
using namespace std;
#include "SimpleMusicAlbum.h"
#include "SimpleMAC.h"

MAC::MAC()
{
    musicAlbums = NULL;
    noOfMusicAlbums = 0;
}
MAC::~MAC(){ }
MAC::MAC(const MAC &macToCopy)
{
    noOfMusicAlbums = macToCopy.noOfMusicAlbums;
    musicAlbums = new *MusicAlbum[noOfMusicAlbums];
    for (int i = 0; i < noOfMusicAlbums; i++ )
        musicAlbums[i] = MusicAlbum(macToCopy.musicAlbums[i]);
}
void MAC::operator=(const MAC &right)
{
    noOfMusicAlbums = right.noOfMusicAlbums;
    for ( int i = 0; i < noOfMusicAlbums; i++ )
    {
        musicAlbums[i] = MusicAlbum( (right.getMusicAlbums())[i] ); //wut am i doin anyway
    }
}
bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear)
{
    if ( musicAlbum == NULL )
        return false;
    else
    {
        for ( int x = 0; x < noOfAlbums; x++ )
        {
            if ( musicAlbums[i].artist == maArtist && musicAlbums[i].title == maTitle)
            {
                return false;
            }
            else
            {
                ++noOfMusicAlbums;
                MusicAlbum newMusicAlbums[noOfMusicAlbums];
                for ( int i = 0; i < noOfMusicAlbums - 1; i++ )
                {
                    newMusicAlbums[i].artist = musicAlbums[i].artist;
                    newMusicAlbums[i].title = musicAlbums[i].title;
                    newMusicAlbums[i].year = musicAlbums[i].year;
                }
                newMusicAlbums[noOfMusicAlbums].artist = maArtist;
                newMusicAlbums[noOfMusicAlbums].title = maTitle;
                newMusicAlbums[noOfMusicAlbums].year = maYear;
                delete [] musicAlbums;
                musicAlbums = newMusicAlbums;
                return true;
            }
        }
    }
}
bool MAC::removeMusicAlbum(const string maArtist, const string maTitle)
{
    if ( musicAlbum == NULL )
        return false;
    else
    {
        --noOfMusicALbums;
        MusicAlbum newMusicAlbums[noOfMusicAlbums];
        for ( int i = 0; i < noOfMusicAlbums + 1; i++ )
        {
            newMusicAlbums[i].artist = musicAlbums[i].artist;
            newMusicAlbums[i].title = musicAlbums[i].title;
            newMusicAlbums[i].year = musicAlbums[i].year;
        }
        delete [] musicAlbums;
        musicAlbums = newMusicAlbums;
        return true;
    }
}
int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums)
{
    //TODO
    return 0;
}

      //  MusicAlbum *musicAlbums;
      //  int noOfMusicAlbums;
