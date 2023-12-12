#pragma once

#include <string>
#include <vector>

struct Song
{
    std::string title;
    std::string artist;
    std::string album;
    int year;
    std::string feature;
    std::string genre;
};

class MusicLibrary
{
    public:
        void loadLibrary();
        void saveLibrary();
        void displayLibrary();
        void addSong();
        void editSong();
        void deleteSong();
        void searchLibrary();
    
    private:
};