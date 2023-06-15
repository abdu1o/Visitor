#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Components.h"

int main()
{
    Song song1("qwe", 120), song2("zxc", 360);

    Album album;
    album.AddSong(song1);
    album.AddSong(song2);

    Visitor visitor;
    album.Accept(&visitor);

    cout << "Total tracks: " << visitor.GetTotalTracks() << endl;
    cout << "Total duration: " << visitor.GetTotalDuration() << endl;
}
