#pragma once


#include <string>
#include <vector>
#include <nlohmann/json.hpp>

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
        void addSong();
        void editSong();
        void deleteSong();
        void searchLibrary();
        void saveLibrary();

    
    private:
        std::vector<Song> library;
        std::string filename;

        void initializeLibrary();
        void displayLibrary();

};

