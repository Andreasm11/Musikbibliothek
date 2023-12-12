#include "MusicLibrary.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


void MusicLibrary::addSong()
{
    std::cout << "Songs hinzufügen ";
}

void MusicLibrary::editSong()
{
    std::cout << "Songs bearbeiten ";
}

void MusicLibrary::deleteSong()
{
    std::cout << "Songs löschen ";
}

void MusicLibrary::searchLibrary()
{
    std::cout << "Bibliothek durchsuchen ";
}

void MusicLibrary::displayLibrary()
{
    std::cout << "Bibliothek anzeigen ";
}

void MusicLibrary::initializeLibrary()
{
    std::cout << "Bibliothek initialisieren ";
}

void MusicLibrary::saveLibrary()
{
    std::cout << "Bibliothek speichern ";
}
