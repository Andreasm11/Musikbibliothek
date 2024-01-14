# Musikbibliothek

Die Musikbibliothek ist ein C++-Projekt, das es dem Benutzer ermöglicht, seine persönliche Musikbibliothek zu erstellen und verwalten.

## Features
- Hinzufügen von bestehenden Bibliotheken
- Erstellen einer Bibliothek
- Titel hinzufügen
- Meta-Daten ändern
- Titel löschen
- nach Titeln oder Meta-Daten suchen

## Benutzerführung

- Wenn Bibliothek übergeben werden soll muss diese benannt sein "library.json" und folgenden Aufbau haben:
    [
    {
        "title": "Songname",
        "album": "Albumname",
        "artist": "Künstlername",
        "year": Erscheinungsjahr
        "feature" : "Kollaborationspartner",
        "genre" : "Genre des Songs"
    },
    ]

## Projektstruktur

```text
Fahrtenbuch/
|-- bin/
|   |-- my_app (oder my_app.exe für Windows)
|   `-- test_app (oder test_app.exe für Windows)
|
|-- include/
    |-- json.hpp
|   |-- MusicLoibrary.hpp
|   `-- UserInterface.hpp
|
|-- obj/
|
|-- src/
|   |-- main.cpp
|   |-- MusicLibrary.cpp
|   `-- UserInterface.cpp
|
|-- test/
|   |-- catch.cpp
|   `-- Tests.cpp

|-- Makefile
`-- README.md
```

## Übersetzung und Ausführung

### Manuelle Übersetzung der Anwendung

Für die manuelle Übersetzung verwenden Sie folgende Kommandos:

```text
g++ -std=c++17 -Wall -Iinclude -c src/Logbook.cpp -o obj/Logbook.o
g++ -std=c++17 -Wall -Iinclude -c src/Trip.cpp -o obj/Trip.o
g++ -std=c++17 -Wall -Iinclude -c src/UserInterface.cpp -o obj/UserInterface.o
g++ -std=c++17 -Wall -Iinclude -c src/main.cpp -o obj/main.o
g++ -std=c++17 -Wall -o bin/my_app obj/Logbook.o obj/Trip.o obj/UserInterface.o obj/main.o
```

### Manuelle Übersetzung der Tests

```text
g++ -std=c++17 -Wall -Iinclude -c test/logbook_test.cpp -o obj/logbook_test.o
g++ -std=c++17 -Wall -Iinclude -c test/trip_test.cpp -o obj/trip_test.o
g++ -std=c++17 -Wall -o bin/test_app obj/Logbook.o obj/Trip.o obj/UserInterface.o obj/logbook_test.o obj/trip_test.o 
```

## Übersetzung und Ausführung
    make all
    make test
### Starten der Anwendung
    bin/my_app

### Starten der Testdurchläufe
    bin/test_app