#pragma once

class Component;
class Song;
class Album;

class Visitor
{
private:
    int _duration_general;
    int _count;

public:
    Visitor() : _duration_general(0), _count(0) {}

    int GetTotalDuration() const
    {
        return _duration_general;
    }

    int GetTotalTracks() const
    {
        return _count;
    }

    void VisitSong(const Song& song);
    void VisitAlbum(const Album& album);
};

class Component
{
public:
    virtual ~Component() {}
    virtual void Accept(Visitor* visitor) const = 0;
};

class Song : public Component
{
private:
    string _title;
    int _duration;

public:
    Song(string title, int duration)
    {
        this->_title = title;
        this->_duration = duration;
    }

    const int GetDuration() const
    {
        return _duration;
    }

    void Accept(Visitor* visitor) const
    {
        visitor->VisitSong(*this);
    }
};

class Album : public Component
{
private:
    vector<Song> album;

public:
    void AddSong(const Song& song)
    {
        album.push_back(song);
    }

    const vector<Song>& GetAlbum() const
    {
        return album;
    }

    void Accept(Visitor* visitor) const
    {
        visitor->VisitAlbum(*this);
    }
};

void Visitor::VisitSong(const Song& song)
{
    _duration_general += song.GetDuration();
}

void Visitor::VisitAlbum(const Album& album)
{
    const vector<Song>& songs = album.GetAlbum();
    for (const Song& i : songs)
    {
        i.Accept(this);
        _count++;
    }
}