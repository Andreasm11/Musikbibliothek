#pragma once
#include "MusicLibrary.hpp"

class UserInterface
{
    public:
        void start();
        void displayMenu();  
    private:
        MusicLibrary musicLibrary;
};