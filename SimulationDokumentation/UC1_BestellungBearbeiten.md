# Use Case: Bearbeiten einer Bestellung.
Eine Bestellung wird in der Entwicklung bearbeitet. Sie löst verschiedene 
Aktivitäten aus, die alle abgeschlossen werden müssen bis die Bestellung 
fertig ist und eine Lieferung an den Kunden geschickt werden kann.    
Die von einer Bestellung ausgelöste Entwicklung von Produkten orientiert 
sich am typischen Ablauf der Softwareentwicklung.

# Ablauf der bearbeiteung einer Bestellung

1.	Am Anfang steht die Bestellung eines Kunden, der ein neues Produkt 
	möchte oder eine Änderung an einem Produkt. Die Bestellung wird nun 
	an die Entwicklungsabteilung übergeben, die das Produkt erstellt 
	oder die bestellte Änderung am Produkt bearbeitet.  
	Dazu muss für eine Neubestellung ein vom Verkauf ein leeres Produkt 
	an die Bestellung angehängt werden. Bei der Bestellung einer 
	Weiterentwicklung wird vom Kunden das Produkt mitgeschickt, welches 
	bearbeitet werden soll.
2.	Zuerst nimmt der Architekt die Bestellung entgegen und zerlegt die 
	Entwicklungsschritte in einzelne Teilschritte, die dann als Aufgaben 
	an das Produkt angehängt werden. Es werden mehrere Aufgaben angehängt, 
	damit mehrere Mitarbeiter parallel an der Bearbeitung der Bestellung 
	mitwirken können.
3.	Die Bearbeitung der Aufgaben erfolgt in Teilschritten, die als 
	Zustandsbaum abgebildet werden können. Durch diesen Baum sind mehrere 
	Wege möglich, weil einzelne Teilschritte, wie auch in der realen 
	Entwicklung üblich, ausgelassen werden können. Werden Teilschritte 
	ausgelassen, hat dies negative Auswirkungen auf die Eigenschaften 
	des Produktes.
4.	Jeder Aufgabe ist in einem Zustand. Während sie in Bearbeitung ist, 
	ist der Zustand nach außen nicht sichtbar. Nachdem die Aufgabe erledigt 
	ist und der Mitarbeiter die Aufgabe zurückgibt, hat sie entweder noch 
	denselben Zustand, weil sie nicht fertig wurde, oder sie ist in einem 
	neuen Zustand.
5.	Wie intensiv die Aufgabe bearbeitet wird, hängt von den Eigenschaften des 
	Mitarbeiters, der Schwere der Aufgabe, der Situation der Entwicklung und 
	der Situation des Projektes ab.
6.	Sobald alle Teilschritte erledigt wurden, ist die Aufgabe im Zustand 
	fertig. Sobald alle Aufgaben, die zu einem Schritt mit in der Entwicklung 
	des Produktes gehören die im Zustand „Fertig“ sind, ist das Produkt fertig 
	gestellt und kann vom Verkauf an den Kunden geliefert werden.
	