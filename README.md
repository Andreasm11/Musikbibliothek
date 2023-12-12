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

## Übersetzung und Ausführung
    make all
    make test
### Starten der Anwendung
    bin/my_app

### Starten der Testdurchläufe
    bin/test_app