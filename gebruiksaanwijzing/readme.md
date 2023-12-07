# Gebruiksaanwijzing

### opladen / vervangen batterijen
De batterijen die gebruikt worden zijn 2 18650 li-ion batterijen. Deze worden opgeladen met een geschikte oplader. Om de batterijen te vervangen moet eerst de PCB van de auto worden verwijderd. Hierna kunnen de batterijen uit de houder worden gehaald en opgeladen. 

### draadloze communicatie
#### verbinding maken
Voor de draadloze communicatie wordt er gebruik gemaakt van een HC-05 bluetooth module. Op de smartphone wordt de app "Serial Bluetooth Terminal" gebruikt om verbinding te maken met de module. Hiermee kunnen de commando's worden doorgestuurd naar de arduino. 

#### commando's
debug [on/off] => Opvragen van de ingestelde parrameters. 

run  => Starten van de LineFollower. 

stop => Stoppen van de LineFollower.  

set cycle [µs]  => Instellen van de cycle time. Deze is ongeveer het dubbele van de calculation time.

set power [0..255]  => Instellen van de power van de motoren. 

set diff [0..1]  => Door de diff aan te passen zal de auto vertragen of versnellen in de bochten. Hoe hoger diff hoe meer de auto versnelt in de bochten.

set kp [0..] => Dit is de corrigatie van de fout. Hoe hoger kp hoe sterker de auto zich corrigeert om de zwarte lijn in het midden van de sensor te hebben. Als deze te hoog is zal de auto schoken van links naar rechts over de lijn.

set ki [0..] => Hoe langer de error duurt hoe sterker de linfollower zal bijsturen. 

set kd [0..] => Dit is de foutverandering. Deze kijkt naar de fout uit de vorige cyclus en gaat dan de fout bijregelen. Was deze fout groot dan wordt er meer gecorigeerd.

calibrate black => Hierdoor worden de zwarte waarden van de sensor gecalibreert.  

calibrate white => Hierdoor worden de witte waarden van de sensor gecalibreert. 

### kalibratie
Het kalibreren van de senor gebeurd met de commando's "calibrate black" en "calibrate white". Om de zwarte waarden te kalibreren moet de sensor boven een zwart oppervlak staan en dan het commando ingeven. Om de witte waarden te kalibreren gebeurd het zelfde maar op een wit oppervlak. 

### settings
De robot rijdt stabiel met volgende parameters:  

### start/stop button
Er is een start/stop button voorzien op de robot. Deze bevindt zich op de PCB, de knop is aangesloten op een intterupt pin (pin2). Deze werkt met een intterupt functie en een debounce. 
