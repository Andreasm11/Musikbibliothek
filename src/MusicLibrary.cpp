#include "MusicLibrary.hpp"
#include <iostream>
#include <fstream>
#include <json.hpp>
#include <algorithm>

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
        std::cout << "Bibliothek wurde erfolgreich aus 'library.json' initalisiert.\n";
    }
    else                                            
    {
        std::cout << "Datei 'library.json' wurde nicht gefunden. Neue Bibliothek wird erstellt. \n";
        saveLibrary();
    }
}

void MusicLibrary::addSong()
{
    Song newSong;

    std::cout << "Bitte geben Sie die angeforderten Metadaten an!\n";

    std::cout << "Titel: ";
    std::getline (std::cin, newSong.title); 

    std::cout << "Künstler: ";
    std::getline (std::cin, newSong.artist);

    std::cout << "Album: ";
    std::getline (std::cin, newSong.album);

    std::cout << "Erscheinungsjahr: ";
    std::cin >> newSong.year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Featuring: ";
    std::getline (std::cin, newSong.feature);
    
    std::cout << "Genre: ";
    std::getline (std::cin, newSong.genre);

    songs.push_back(newSong);
    std::cout << "Song erfolgreich hinzugefügt. \n";
}

void MusicLibrary::editSong()
{
    if(songs.empty())
    {
        std::cout << "Die Bibliothek ist leer. Es sind keine Songs zum Bearbeiten existent.\n";
        return;
    }

    std::cout << "Bibliothek anzeigen vor dem Bearbeiten:\n";
    displayLibrary();

    std::string titleToEdit;
    std::cout << "Geben Sie den Titel des zu bearbeitenden Songs ein:";
    std::cin.ignore();
    std::getline(std::cin, titleToEdit);

    auto it = std::find_if(songs.begin(), songs.end(), [&titleToEdit] (const Song& song)
    {
        return song.title == titleToEdit;
    });

    if (it == songs.end())
    {
        std::cout << "Der Titel" << titleToEdit << "wurde nicht gefunden. Bearbeitung abgebrochen.";
        return;
    }

    char continueEditing;

    do
    {
        std::cout << "Wählen Sie, welche Metadata Sie bearbeiten möchten:\n";
        std::cout << "1. Titel\n";
        std::cout << "2. Künstler\n";
        std::cout << "3. Album\n";
        std::cout << "4. Erscheinungsdatum\n";
        std::cout << "5. Featuring\n";
        std::cout << "6. Genre\n";
        std::cout << "Ihre Wahl: ";

        int userChoice;
        std::cin >> userChoice;
                                                                        //while einbauen damit mehrere Metadaten geändert werden können und Feedbacknachricht einbauen
        switch (userChoice)
        {
            case 1:
                std::cout << "Neuer Titel: ";
                std::getline(std::cin, it->title);
                break;

            case 2:
                std::cout << "Neuer Künstler: ";
                std::cin.ignore();
                std::getline(std::cin, it->artist);
                break;

            case 3:
                std::cout << "Neues Album: ";
                std::cin.ignore();
                std::getline(std::cin, it->album);
                break;

            case 4:
                std::cout << "Neues Erscheinungsjahr: ";
                std::cin.ignore();
                std::cin >> it->year;
                break;

            case 5:
                std::cout << "Neues Featuring: ";
                std::cin.ignore();
                std::getline(std::cin, it->feature);
                break;

            case 6:
                std::cout << "Neues Genre: ";
                std::cin.ignore();
                std::getline(std::cin, it->genre);
                break;
                
            default:
                std::cout << "Ungültige Auswahl.";
                return;
        }

        std::cout << "Möchten Sie eine weitere Metadata bearbeiten? (j/n): ";
        std::cin >> continueEditing;

    } while (continueEditing == 'j' || continueEditing == 'J');
    
    std::cout << "Bearbeitung abgeschlossen.\n";

    
}

void MusicLibrary::deleteSong()
{
    if (songs.empty())
    {
        std::cout << "Die Bibliothek ist leer. Es können keine Songs gelöscht werden.\n";
        return;
    }

    std::string titleToDelete;
    std::cout << "Geben Sie den Titel ein, der gelöscht werden soll: ";
    std::cin.ignore();
    std::getline(std::cin, titleToDelete);

    auto it = std::remove_if(songs.begin(), songs.end(), [&titleToDelete](const Song& song)
    {
        return song.title == titleToDelete;
    });

    if (it == songs.end()) {
        std::cout << "Kein Song mit dem Titel '" << titleToDelete << "' gefunden.\n";
    } else {
        songs.erase(it, songs.end());
        std::cout << "Songs mit dem Titel '" << titleToDelete << "' wurden gelöscht.\n";
    }
}

void MusicLibrary::searchLibrary()
{
    std::string searchWord;
    std::cout << "Geben Sie Ihren Suchbegriff ein: ";
    std::cin.ignore();
    std::getline(std::cin, searchWord);

    std::vector<Song> searchResults;
    std::copy_if(songs.begin(), songs.end(), std::back_inserter(searchResults), [&searchWord](const Song& song)
    {
        std::string yearAsString = std::to_string(song.year);

        return song.title.find(searchWord) != std::string::npos ||
               song.artist.find(searchWord) != std::string::npos ||
               song.album.find(searchWord) != std::string::npos ||
               song.feature.find(searchWord) != std::string::npos ||
               song.genre.find(searchWord) != std::string::npos ||
               yearAsString.find(searchWord) != std::string::npos;     
    });

    if (searchResults.empty())
    {
        std::cout << "Keine Ergebnisse für Ihre Suche gefunden. \n";
    }
    else
    {
        std::cout << "Suchergebnisse:\n";
        std::cout << "-----------------------\n\n";
        for (size_t i = 0; i < searchResults.size(); ++i)
        {
            std::cout << i+1 << ". Ergebnis:\n" << "Titel: " << searchResults[i].title << "\n" << "Künstler: " << searchResults[i].artist << 
            "\n" << "Album: " << searchResults[i].album << "\n" << "Erscheinungsjahr: " << searchResults[i].year << "\n";
            if (!searchResults[i].feature.empty())
            {
                std::cout << "Feature: " << searchResults[i].feature << "\n";
            }
            std::cout << "Genre: " << searchResults[i].genre << "\n\n";
        }
    }
}

void MusicLibrary::displayLibrary()
{
    if (songs.empty())
    {
        std::cout << "Die Bibliothek ist leer. \n";
    }

    else
    {
        std::cout << "---------------Bibliothek----------------\n\n\n";
        for (const auto& song : songs)
        {
            std::cout << "Titel: " << song.title << "\n";
            std::cout << "Künstler: " << song.artist << "\n";
            std::cout << "Album: " << song.album << "\n";
            std::cout << "Erscheinungsjahr: " << song.year << "\n";

            if (!song.feature.empty())
            {
                std::cout << "Feature: " << song.feature << "\n";
            }

            std::cout << "Genre: " << song.genre << "\n";

            std::cout << "-------------------------------------------\n"; 
        }
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
    std::cout << "Die Bibliothek wurde erfolgreich gespeichert. \n";
}

