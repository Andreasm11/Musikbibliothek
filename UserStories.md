# User Stories für Musikbibliothek-Anwendung

## User Story 1: Bibliothek initialisieren

**Als** Nutzer
**möchte ich** eine Bibliothek auslesen bzw. initalisieren,
**damit** ich alle bereits bestehenden Daten in die Bibliothek übertragen oder eine neue Bibliothek erstellen kann

### Akzeptanzkriterien US1

- [x] Die eingelesene Bibliothek soll eine konsistente Datenstruktur verwenden, die Titel, Künstler, Album und Jahr für jeden Song speichert
- [x] wenn keine vorhandene Bibliotheksdatei vorhanden ist, soll eine leere Bibliothek erstellt werden
- [x] wenn die Anwendung gestartet wird, soll die vorhandene Bibliotheksdatei eingelesen werden

## User Story 2: Song hinzufügen

**Als** Nutzer
**möchte ich** einen neuen Titel zur Bibliothek hinzufügen
**damit** ich meine Musikbibliothek erweitern kann

### Akzeptanzkriterien US2

- [x] Der Benutzer soll in der Lage sein, über den CLI einen neuen Titel zur Bibliothek hinzuzufügen
- [x] neue Titel sollen die gleiche konsistente Datenstruktur verwenden, die Titel, Künstler, Album und Jahr speichert
- [x] Benutzeroberfläche sollte eine Hilfe geben zum einfach hinzufügen von Songs (Step-by-Step)

## User Story 3: Meta-Daten ändern

**Als** Nutzer
**möchte ich** die Meta-Daten eines ausgewählten Titels ändern
**damit** ich Fehler korrigieren oder Informationen nachtragen kann. (z.B. Titel, Künstler, Album und Erscheinungsjahr)

### Akzeptanzkriterien US3
- [x] Der Benutzer sollte in der Lage sein, über den CLI die Meta-Daten eines existierenden Titels zu änder
- [x] Nach der Änderung sollten die aktualisierten Meta-Daten des Songs in der Bibliothek angezeigt werden
- [x] Es sollte sichergestellt werden, dass der Titel existiert, bevor die Meta-Daten geändert werden können 
- [ ] Fehlerhafte Eingaben sollten abgefangen werden und eine erneute Eingabe sollte möglich sein (z.B. Worte bei Erscheinungsjahr)
- [x] CLI sollte durch den Prozess leiten 
- [x] mehrere Sachen sollten im selben Prozess bearbeitbar sein
- [x] Ausgabe nach erfolgreicher Änderung

## User Story 4: Titel aus Bibliothek entfernen

**Als**  Nutzer
**möchte ich** Titel aus der Bibliothek löschen
**damit** ich den Titel (inkl. Meta-Daten) dauerhaft löschen kann

### Akzeptanzkriterien US4

- [x] ein existierender Titel sollte vom Benutzer aus der Bibliothek gelöscht werden können
- [x] es sollte sichergestellt werden, dass der Benutzer einen existierenden Titel ausgewählt hat
- [ ] Es sollte eine Sicherheitsabfrage gestellt werden, ob der Titel wirklich inkl. Meta-Daten gelöscht werden soll
- [x] Es sollte eine Bestätigungsmeldung angezeigt werden, wenn der Löschvorgang erfolgreich war
- [x] Es soll eine Fehlermeldung generiert werden, wenn die Bibliothek leer ist.

## User Story 5: Suche von Titels mit Meta-Daten

**Als** Nutzer
**möchte ich** nach Titel oder Meta-Daten in der Bibliothek suchen
**damit** ich den gewünschten Song schnell und einfach finden kann

### Akzeptanzkriterien US5

- [x] Der Benutzer sollte in der Lage sein, über den CLI nach einem spezifischen Titel, Künstler, Album oder Erscheinungsjahr zu suchen
- [x] Die CLI sollte dann alle Songs anzeigen, welche den Suchbegriff enthalten
- [ ] Es sollte eine kombinierte Suche ermöglicht werden, indem man mehrere Suchkriterien gleichzeitig angibt
- [x] wenn keine Übereinstimmung gefunden wird, sollte die CLI dem Benutzer mitteilen, dass keine Ergbenisse für die Suchkriterien vorliegen und fragen ob eine erneute Suche durchgeführt werden soll.

## User Story 6: Benutzerführung

**Als** Nutzer
**möchte ich** klare Anweisungen und Hinweise erhalten, wenn ich das CLI-Interface verwende,
**damit** ich einfach und intuitiv mit der Musikbibliothek interagieren kann.

### Akzeptanzkriterien US6

- [x] Bei jedem Schritt gibt das Interface klare Anweisungen zur verfügbaren Aktion oder erwarteten Eingabe
- [x] Fehlermeldungen sind hilfreich und geben mir eine klare Richtung, was zu tun ist, um den Fehler zu beheben


## User Story 7: Bibliothek anzeigen

**Als** Nutzer
**möchte ich** mir die vorhandene Bibliothek anzeigen lassen
**damit** ich vorhandene Daten einsehen kann

### Akzeptanzkriterien US7

- [x] Die eingelesene Bibliothek soll angezeigt werden, mit allen Metadaten.
- [x] Wenn die Bibliothek keine Elemente enthält, soll dies so kommuniziert werden

## User Story 8: Bibliothek speichern 

**Als** Nutzer
**möchte ich** die Bibliothek mitsamt meiner Änderungen speichern
**damit** ich auch in Zukunft auf die aktualisierte Bibliothek zugreifen kann

### Akzeptanzkriterien US8

- [x] Songs sollen mitsamt ihrer Metadaten im richtigen Format gespeichert werden
- [x] Wenn dies erfolgreich war, soll eine Meldung ausgegeben werden
- [x] Soll formatiert gespeichert werden, um Rohdaten sauber anzeigen zu können
