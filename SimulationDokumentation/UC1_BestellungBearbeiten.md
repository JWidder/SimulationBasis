# Use Case: Bearbeiten einer Bestellung.
Eine Bestellung wird in der Entwicklung bearbeitet. Sie l�st verschiedene 
Aktivit�ten aus, die alle abgeschlossen werden m�ssen bis die Bestellung 
fertig ist und eine Lieferung an den Kunden geschickt werden kann.    
Die von einer Bestellung ausgel�ste Entwicklung von Produkten orientiert 
sich am typischen Ablauf der Softwareentwicklung.

# Ablauf der bearbeiteung einer Bestellung

1.	Am Anfang steht die Bestellung eines Kunden, der ein neues Produkt 
	m�chte oder eine �nderung an einem Produkt. Die Bestellung wird nun 
	an die Entwicklungsabteilung �bergeben, die das Produkt erstellt 
	oder die bestellte �nderung am Produkt bearbeitet.  
	Dazu muss f�r eine Neubestellung ein vom Verkauf ein leeres Produkt 
	an die Bestellung angeh�ngt werden. Bei der Bestellung einer 
	Weiterentwicklung wird vom Kunden das Produkt mitgeschickt, welches 
	bearbeitet werden soll.
2.	Zuerst nimmt der Architekt die Bestellung entgegen und zerlegt die 
	Entwicklungsschritte in einzelne Teilschritte, die dann als Aufgaben 
	an das Produkt angeh�ngt werden. Es werden mehrere Aufgaben angeh�ngt, 
	damit mehrere Mitarbeiter parallel an der Bearbeitung der Bestellung 
	mitwirken k�nnen.
3.	Die Bearbeitung der Aufgaben erfolgt in Teilschritten, die als 
	Zustandsbaum abgebildet werden k�nnen. Durch diesen Baum sind mehrere 
	Wege m�glich, weil einzelne Teilschritte, wie auch in der realen 
	Entwicklung �blich, ausgelassen werden k�nnen. Werden Teilschritte 
	ausgelassen, hat dies negative Auswirkungen auf die Eigenschaften 
	des Produktes.
4.	Jeder Aufgabe ist in einem Zustand. W�hrend sie in Bearbeitung ist, 
	ist der Zustand nach au�en nicht sichtbar. Nachdem die Aufgabe erledigt 
	ist und der Mitarbeiter die Aufgabe zur�ckgibt, hat sie entweder noch 
	denselben Zustand, weil sie nicht fertig wurde, oder sie ist in einem 
	neuen Zustand.
5.	Wie intensiv die Aufgabe bearbeitet wird, h�ngt von den Eigenschaften des 
	Mitarbeiters, der Schwere der Aufgabe, der Situation der Entwicklung und 
	der Situation des Projektes ab.
6.	Sobald alle Teilschritte erledigt wurden, ist die Aufgabe im Zustand 
	fertig. Sobald alle Aufgaben, die zu einem Schritt mit in der Entwicklung 
	des Produktes geh�ren die im Zustand �Fertig� sind, ist das Produkt fertig 
	gestellt und kann vom Verkauf an den Kunden geliefert werden.
	