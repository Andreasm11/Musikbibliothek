#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MusicLibrary.hpp"
#include <iostream>
#include <sstream>



class CinRedirect                           //ChatGPT für Funktion der automatischen Eingabe
{
    public:
        CinRedirect(std::istringstream& input) : oldCin(std::cin.rdbuf(input.rdbuf())) {}
        ~CinRedirect() 
        {
            std::cin.rdbuf(oldCin);
        }

    private:
        std::streambuf* oldCin;
};

TEST_CASE("AddSong Funktion", "[addSong]")
{
    MusicLibrary library;

    
    SECTION("Einzelner Song hinzufügen")
    {
        std::istringstream input("Test Titel\nTest Künstler\nTest Album\n2023\nTest Featuring\nTest Genre\n");
        CinRedirect redirect(input);

        library.addSong();


        REQUIRE(library.songs.size() == 1);
        REQUIRE(library.songs[0].title == "Test Titel");
        REQUIRE(library.songs[0].artist == "Test Künstler");
        REQUIRE(library.songs[0].album == "Test Album");
        REQUIRE(library.songs[0].year == 2023);
        REQUIRE(library.songs[0].feature == "Test Featuring");
        REQUIRE(library.songs[0].genre == "Test Genre");
    }
}

TEST_CASE("EditSong Funktion", "[editSong]")
{
    MusicLibrary library;
    library.songs.push_back({"Song1", "Artist1", "Album1", 2021, "Feature1", "Genre1"});

    SECTION("Song bearbeiten")
    {
        std::istringstream input(" Song1\n1\nNewArtist\n");
        CinRedirect redirect(input);

        library.editSong();

        REQUIRE(library.songs[0].artist == "NewArtist");
        REQUIRE(library.songs[0].title == "Song1");

    }
}

TEST_CASE("DeleteSong Funktion", "[deleteSong]")
{
    MusicLibrary library;
    library.songs.push_back({"Song1", "Artist1", "Album1", 2021, "Feature1", "Genre1"});

    SECTION("Song löschen")
    {
        std::istringstream input(" Song1\n");
        CinRedirect redirect(input);

        library.deleteSong();

        REQUIRE(library.songs.size() == 0);
    }
}

TEST_CASE("SearchLibrary Funktion", "[searchLibrary]")
{
    MusicLibrary library;
    

    SECTION("Suche nach Titel")
    {
        library.songs.push_back({"Song1", "Artist1", "Album1", 2021, "Feature1", "Genre1"});
        library.songs.push_back({"Song2", "Artist2", "Album2", 2022, "Feature2", "Genre2"});
        library.songs.push_back({"Song3", "Artist3", "Album3", 2023, "Feature3", "Genre3"});
        
        std::istringstream input("Song2\n");
        CinRedirect redirect(input);

        std::stringstream output;
        std::streambuf* oldCout =std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        library.searchLibrary();

        std::cout.rdbuf(oldCout);

        REQUIRE(output.str().find("Song1") == std::string::npos);
        REQUIRE(output.str().find("Song2") != std::string::npos);
    } 
}

TEST_CASE("Library initalisieren aus Testdatei", "[initializeLibrary]")
{
    MusicLibrary library;
    library.initializeLibrary();

    REQUIRE_FALSE(library.songs.empty());

    REQUIRE(library.songs.size() >= 1);
}







