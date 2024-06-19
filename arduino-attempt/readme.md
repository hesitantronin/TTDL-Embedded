# TTDL-Embedded

## Samenvatting

Dit deel van het project moet draaien op de ESP32. Het meet momenteel de waarde van de sensor en print deze naar de seriële uitgang. Dit moet worden uitgebreid met KPN Lora-integratie, waarvoor je de sleutels kunt krijgen van Campus Gouda.
Hoe te gebruiken

Om dit uit te voeren, doe je het volgende:

- Sluit de sensor aan op GPIO 35 en GND
- Verbind de ESP32 met je computer via USB
- Open arduino-attempt.ino in de Arduino IDE
- Selecteer de poort waarop de ESP32 is aangesloten en selecteer het juiste board om verbinding te maken
- Start het project

## Nog toe te voegen

Dit project is nog niet af en moet nog de volgende verbeteringen krijgen:

- Verbinding maken met KPN Lora en de gemeten waarden daarheen sturen
- Een systeem maken om deze berichten op ingestelde tijden te verzenden, zodat je bijvoorbeeld 's nachts geen berichten hoeft te verzenden
- Het registreert nog niet of iemand met zijn rug tegen de stoel zit, wat nuttig kan zijn voor medische professionals
