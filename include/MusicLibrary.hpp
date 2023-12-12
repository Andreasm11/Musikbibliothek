#pragma once


#include <string>
#include <vector>


class MusicLibrary
{
    public:
        struct Song
            {
                std::string title;
                std::string artist;
                std::string album;
                int year;
                std::string feature;
                std::string genre;
            };

        void initializeLibrary();
        void addSong();
        void editSong();
        void deleteSong();
        void searchLibrary();
        void saveLibrary();
        void displayLibrary();
    
    private:
        std::vector<Song> songs; 
};

