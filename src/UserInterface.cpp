#include "UserInterface.hpp"
#include "MusicLibrary.hpp"
#include <iostream>

void UserInterface::start()
{
    int choice = 0;
    while (choice != 6)
    {
        displayMenu();
        std::cout << "Bitte wählen Sie eine Option (1-6):";
        std::cin >> choice;
 
              
        switch (choice)
        {
            case 1:
                musicLibrary.displayLibrary();
                break;
            
            case 2:
                musicLibrary.addSong();
                break;
            
            case 3:
                musicLibrary.editSong();
                break;
            
            case 4:
                musicLibrary.deleteSong();
                break;
            
            case 5:
                musicLibrary.searchLibrary();
                break;

            case 6:
                std::cout << "Programm wird beendet.\n";
                break;
            
            default:
                std::cout << "Ungültige Option, bitte nochmal versuchen. \n" << std::endl;
        }
    }
}

void UserInterface::displayMenu()
{
    std::cout << "============Musikbibliothek============\n";
    std::cout << "1. Bibliothek anzeigen\n";
    std::cout << "2. Titel hinzufügen\n";
    std::cout << "3. Meta-Daten ändern\n";
    std::cout << "4. Titel löschen\n";
    std::cout << "5. Nach Titeln oder Meta-Daten suchen\n";
    std::cout << "6. Speichern und Programm beenden\n";
    std::cout << "=======================================\n";
}