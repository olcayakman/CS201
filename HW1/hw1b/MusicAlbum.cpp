#include <string>
using namespace std;
#include "MusicAlbum.h"
#include "Song.h"

MusicAlbum::MusicAlbum(const string maArtist = "", 
                       const string maTitle = "", 
                       const int maYear = 0)
{
    artist = maArtist;
    title = maTitle;
    year = maYear;
    songs = NULL;
    noSongs = 0;
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
int MusicAlbum::getNoSongs()
{
    return noSongs;
}
void MusicAlbum::calculateMusicAlbumLength(int &mins, int &secs)
{
    mins = 0;
    secs = 0;
    if (noSongs != 0)
    {
        for (int i = 0; i < noSongs; i++)
        {
            mins = songs[i].getSongMins() + mins;
            secs = songs[i].getSongSecs() + secs;
        }
        mins += (secs / 60);
        secs = secs % 60;
    }
}
bool MusicAlbum::addSong(Song songToAdd)
{
    if ( songs )
    {
        if ( noSongs == 0 )
        {
            songs = new Song[1];
            songs[0] = songToAdd;
            return true;
        }
        else if (noSongs > 0)
        {
            int index = -1;
            for ( int i = 0; i < noSongs; i++ )
            {
                if ( songs[i].getSongName() == songToAdd.getSongName() )
                    index = i;
            }
            if ( index != -1 )
            {
                Song *updatedSongs = new Song[noSongs + 1];
                for ( int i = 0; i < noSongs; i ++)
                {
                    updatedSongs[i] = songs[i];
                } 
                noSongs++;
                updatedSongs[noSongs] = Song(songToAdd);
                delete [] songs;
                songs = new Song[noSongs];
                //songs = updatedSongs;
                for ( int i = 0; i < noSongs; i++ )
                {
                    songs[i] = updatedSongs[i];
                }
                return true;
            } 
            else
            {
                return false;
            }
        }
    }
    else 
    {
        return false;
    }
}
bool MusicAlbum::removeSong(Song songToRemove)
{
    if ( songs )
    {
        if ( noSongs == 1 )
        {
            delete [] songs;
            noSongs = 0;
            return true;
        }
        else if ( noSongs > 1 )
        {
            int index = -1;
            for ( int i = 0; i < noSongs; i++)
            {
                if ( songs[i].getSongName() == songToRemove.getSongName())
                    index = i;
            }
            if ( index != -1 )
            {
                Song *updatedSongs = new Song[noSongs + 1];
                for ( int i = 0; i < index; i++)
                {
                    updatedSongs[i] = songs[i];
                }
                for ( int i = index; i < noSongs - 1; i++ )
                {
                    updatedSongs[i] = songs[i + 1];
                }
                noSongs--;
                delete [] songs;
                songs = updatedSongs;
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
    return false;
}
bool MusicAlbum::removeAllSongs()
{
    if ( songs )
    {
        if ( noSongs > 0 )
        {
            delete [] songs;
            songs = NULL;
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

//         string artist;
//         string title;
//         int year;
//         Song *songs;
//         int noSongs;
