#include "MusicLibrary.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void MusicLibrary::initializeLibrary()
{
    std::ifstream file("library.json");

    if (file.is_open())
    {
        json libraryJson;
        file >> libraryJson;

        for (const auto& songJson : libraryJson)
        {
            Song song;
            song.title = songJson["title"];
            song.artist = songJson["artist"];
            song.album = songJson["album"];
            song.year = songJson["year"];
            if (songJson.contains("feature"))
            {
                song.feature = songJson["feature"];
            }
            song.genre = songJson["genre"];
                                                                        //erweitern
            songs.push_back(song);
        }
        std::cout << "Bibliothek wurde aus 'library.json' initalisiert.\n";
    }
    else                                            
    {
        std::cout << "Datei 'library.json' nicht gefunden. Neue Bibliothek wird erstellt. \n";
    }
}

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
    std::cout << "---------------Bibliothek----------------\n\n\n";
    for (const auto& song : songs)
    {
        std::cout << "Titel: " << song.title << "\n";
        std::cout << "Künstler: " << song.artist << "\n";
        std::cout << "Album: " << song.album << "\n";
        std::cout << "Erscheinungsjahr: " << song.year << "\n";
        std::cout << "Feature: " << song.feature << "\n";
        std::cout << "Genre: " << song.genre << "\n";

        std::cout << "-------------------------------------------\n"; 
    }
}


void MusicLibrary::saveLibrary()
{
    json libraryJson;
    for (const auto& song : songs)
    {
        json songJson;
        songJson["title"] = song.title;
        songJson["artist"] = song.artist;
        songJson["album"] = song.album;
        songJson["year"] = song.year;
        songJson["feature"] = song.feature;
        songJson["genre"] = song.genre;

        libraryJson.push_back(songJson);
    }

    std::ofstream file("library.json");
    file << libraryJson.dump(2);
    std::cout << "Bibliothek wurde erfolgreich gespeichert. \n";
}

