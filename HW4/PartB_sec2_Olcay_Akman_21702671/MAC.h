#ifndef __SIMPLE_MAC_H
#define __SIMPLE_MAC_H

#include <string>
using namespace std;
#include "MusicAlbum.h"
#include "Song.h"

class MAC
{
    public:
        MAC();
        ~MAC();
        MAC(const MAC &macToCopy);
        void operator=(const MAC &right);
        bool addMusicAlbum(const string maArtist, const string maTitle, const int maYear);
        bool removeMusicAlbum(const string maArtist, const string maTitle);
        int getMusicAlbums(MusicAlbum *&allMusicAlbums);
        bool addSong(const string maArtist, const string maTitle, const string sName, const int sMins, const int sSecs);
        bool removeSongs(const string maArtist, const string maTitle);
        void calculateAvgMusicAlbumLength(int &minutes, int &seconds);
    private:
        MusicAlbum *musicAlbums;
        int noOfMusicAlbums;
};
#endif
