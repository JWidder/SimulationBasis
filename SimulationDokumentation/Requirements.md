## Goals of the Software Development Simulation

[Cust: 1] The Simulation is realized as a serious game. 
[Impl: Goal: 1]

# Non Functional Requirements

[$Cust 2]

Es können verschiedene Typen von Organisationen nachgebildet werden. 

[$Cust 3] 

Simulationen können jederzeit unterbrochen und wieder aufgenommen werden.

[Cust 4]

Die graphische Ausgabe kann ausgetausch werden. Es können zum Beispiel  
 * WebServer
 * Kommandozeilenversionen
 * GUI-Anwendung

[Cust 5]
Es können mehrere Entwicklungsorganisationen parallel simuliert werden. 

# Entwicklungsorganisation

$Cust 01:  
[[Die Entwicklungsorganisation bildet die Entwicklung von Software nach. ]] 
 
$Prod 01, $Cust01-Satisfies  
[[Die Entwicklungsorganisation besteht aus einem simulierten Kunden und einer simulierten Entwicklung.]]  

$Prod 02, $Cust01-Satisfies  
[[Ein simulierter Kunde sendet regelmäßig Bestellungen an die simulierte Firma, die diese Bestellungen bearbeitet. Die Bestellungen sollen die Firma so auslasten, dass sie im Idealzustand gerade stabil arbeiten kann.]]  

$Prod 03, $Cust01-Satisfies  
[[Die Entwicklung nimmt die Bestellung entgegen.]]   

$Prod 04, $Cust01-Satisfies  
[[Für eine Neubestellung wird ein neues Produkt entwickelt]]  

$Prod 05, $Cust01-Satisfies
[[Bestellt der Kunde eine Weiterentwicklung wird das Basisprodukt der Bestellung hinzugefügt und in der Entwicklung dann weiterentwickelt.]]  


# Customer

* Customer receives the ready developed product

* Customer tests the delivered product and uses it practically.
  This leads to finding bugs. The number of bugs the customer 
  detects depends on the quality delivered by the supplier.

* The customer integrates the error probability. When the value 
  exceeds a limit, then the customer requests a error correction. 

* The customer uses each product for one year intensively. After 
  delivery of new products the customer uses the elder products
  less intensive.  
  This means, that in case the customer can not use the product 
  delivered as an outcome of quality problems. The engineering 
  department must support elderly versions.    