#include <string>
using namespace std;
#include "SimpleMusicAlbum.h"
#include "SimpleMAC.h"

MAC::MAC()
{
    noOfMusicAlbums = 0;
    musicAlbums = NULL;
}
MAC::~MAC()
{
    if(musicAlbums)
    {
        delete [] musicAlbums;
    }
}
MAC::MAC(const MAC &macToCopy) 
{
    noOfMusicAlbums = macToCopy.noOfMusicAlbums;
    if (noOfMusicAlbums > 0) 
    {
        musicAlbums = new MusicAlbum[noOfMusicAlbums];
        for ( int i = 0; i < noOfMusicAlbums; i++)
        {
            musicAlbums[i] = macToCopy.musicAlbums[i];
        }
    }
    else
    {
        musicAlbums = NULL;
    }
}
void MAC::operator = (const MAC &right) 
{
    if ( this != &right )
    {
        noOfMusicAlbums = right.noOfMusicAlbums;
        if ( musicAlbums )
            delete [] musicAlbums;
        musicAlbums = new MusicAlbum[noOfMusicAlbums];
        for (int i = 0; i < noOfMusicAlbums; i++ )
        {
            musicAlbums[i] = right.musicAlbums[i];
        }
    }
}
bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear)
{
    if ( musicAlbums != NULL )
    {
        for (int i = 0; i < noOfMusicAlbums; i++)
        {
            if (musicAlbums[i].getMusicAlbumTitle() == maTitle && musicAlbums[i].getMusicAlbumArtist() == maArtist)
                return false;
        }
        noOfMusicAlbums++;
        MusicAlbum *updatedMusicAlbums = new MusicAlbum[noOfMusicAlbums];
        for (int i = 0; i< noOfMusicAlbums - 1; i++)
        {
            updatedMusicAlbums[i] = musicAlbums[i];
        }
        delete [] musicAlbums;
        musicAlbums = updatedMusicAlbums;
    } 
    else 
    { 
        noOfMusicAlbums = 1;
        musicAlbums = new MusicAlbum[noOfMusicAlbums];
    }
    
    musicAlbums[noOfMusicAlbums - 1] = MusicAlbum(maArtist, maTitle, maYear);
    return true;
}
bool MAC::removeMusicAlbum(const string maArtist, const string maTitle)
{
    if ( musicAlbums != NULL )
    {
        int index = -1;
        for (int i = 0; i < noOfMusicAlbums; i++)
        {
            if ( musicAlbums[i].getMusicAlbumArtist() == maArtist
                && musicAlbums[i].getMusicAlbumTitle() == maTitle)
                index = i;
        }
        if (index != -1)
        {
            noOfMusicAlbums--;
            MusicAlbum *updatedMusicAlbums = new MusicAlbum[noOfMusicAlbums];
            for ( int i = 0; i < index; i++)
            {
                updatedMusicAlbums[i] = musicAlbums[i];
            }
            for (int i = index; i < noOfMusicAlbums; i++)
            {
                updatedMusicAlbums[i] = musicAlbums[i+1];
            }
            delete [] musicAlbums;
            musicAlbums = updatedMusicAlbums;
            return true;
        }
        else 
        {
            return false;
        }
    } 
    else 
    {
        return false;
    }
}
int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums)
{
    if (musicAlbums != NULL )
    {
        allMusicAlbums = new MusicAlbum[noOfMusicAlbums];
        for ( int i = 0; i < noOfMusicAlbums; i++)
        {
            allMusicAlbums[i] = musicAlbums[i];
        }
        return noOfMusicAlbums;
    }
    else
    {
        allMusicAlbums = NULL;
        return 0;
    }
}
