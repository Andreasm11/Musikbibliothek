#pragma once
#include "MusicLibrary.hpp"

class UserInterface
{
    public:
        void start(MusicLibrary& library);
        void displayMenu();  
    private:
        MusicLibrary musicLibrary;
};