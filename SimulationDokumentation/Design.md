# Lieferumfang 

Der Lieferumfang besteht aus 

 * einem ausführbaren Programm und 
 * einer Dokumentation
 
## Installable Piece of Software ##

An installable piece of software is a work product containing work products. The number of containing work Products is a poisson distributed random number. The mean value is defined in an   

@startuml
object Product {
<<component>>
size = 10
completed = 0%
difficulty = 5
}
object Component01{
<<component>>
size = 10
completed = 0%
difficulty = 5
}
object Component02{
<<component>>
size = 10
completed = 0%
difficulty = 5
}
object Function01{
<<component>>
size = 10
completed = 0%
difficulty = 5
}
object Function02{
<<component>>
size = 10
completed = 0%
difficulty = 5
}
object Function03{
<<component>>
size = 10
completed = 0%
difficulty = 5
}
object Modul01{
<<unit>>
size = 10
completed = 0%
difficulty = 5
}
object Modul02{
<<unit>>
size = 10
completed = 0%
difficulty = 5
}
object Modul03{
<<unit>>
size = 10
completed = 0%
difficulty = 5
}

Product *-- Component01  
Product *-- Component02
Component01 *-- Function01 
Component01 *-- Function02 
Component01 *-- Function03
Function01 *-- Modul01 
Function01 *-- Modul02 
Function01 *-- Modul03 
@enduml

# Erstellen der 

Deliverable are implemented in several steps. 
Each step uses work products as an input and produces or modifies  
to work products. These work products are then input to the next step.

a work product has a set of properties. Those properties are together 
with the properties of the engineer and the work environment input of 
the processing step.

@startuml
object WorkProduct{
<<unit>>
size = 10
completed = 0%
difficulty = 5
}
Task *-- WorkProduct 
WorkProduct *-- Properties
@enduml

## 

## Modules

Requirement Specification

Concept description

Module Design

 # Basisablauf
Der Basisablauf beschreibt den Ablauf einer Simulation

![Alt text](..\Images\648DE01D-AC49-49cc-83D5-D502CEF07034.png "Optional title")

__Beginn der Simulation__

Die erste Nachricht initialisiert die Simulation. Informationen in der Nachricht enthalten die 
Basisinformationen die den Ablauf der Simulation einrichten.    

__Berichte Zwischenstand__

Während der Simulation schickt die Simulation immer am Ende eines Tages eine Nachricht an das 
Kontrolelement, dass damit dem Spieler den Fortschritt anzeigt in dem eine Nachricht an die 
GUI geschickt.  
Falls mehrere Simulationen parallel laufen wartet _Controle_ bis alle simulierten Organisationen 
einen Zwischenstand liefern. 

__Darstellen Ergebnisse__

Am Ende eines Durchgangs schickt jede simulierte Organisation die Information das sie fertig 
ist und einen Datensatz mit den Basisergebnissen. Nachdem alle Daten angekommen wird, wird 
das konsolidierte Ergebnis an die Oberfläche geschickt, die es darstellt und auf die Eingaben 
des Spielers wartet. 

# Bestellungen bearbeiten

Der Kunde löst eine Bestellung aus, die dann von der Entwicklung bearbeitet wird und dann 
dann, nach dem Bearbeiten, als Lieferung an den Kunden geschickt wird. 

Eine Bestellung setzt sich zusammen aus  
 1. dem weiter zu entwicklenden Produkten zusammen und 
 2. den neu hinzuzufügenden Funktionen.

Die Entwicklung setzt die Funktiionen um und erstellt daraus die Lieferung. 

Die Lieferung setzt sich zusammen aus 
 1. dem überarbeiteten Produkt und 
 2. der Fehlerliste. 

