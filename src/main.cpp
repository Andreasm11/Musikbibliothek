#include "UserInterface.hpp"
#include "MusicLibrary.hpp"

int main()
{
    MusicLibrary library;
    UserInterface ui;

    library.initializeLibrary();

    ui.start(library);

    return 0;
}