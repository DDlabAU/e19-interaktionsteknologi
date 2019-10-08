# Connected Devices

## Overblik   
For at kunne bruge det nye wifi-board, er vi nødt til at gøre følgende:
1. Downloade board-information
2. Installere et mqtt-bibliotek
3. Installere drivere

### 1: Download board-information  
Åben indstillingerne i Arduino IDE'et ved at trykke ```File``` -> ```Preferences```. Indtast dette url: ```http://arduino.esp8266.com/stable/package_esp8266com_index.json``` i feltet ved navn "Aditional Boards Manager URLs" og tryk "OK".

Åben så Boards Manager ved at klikke ```Tools``` -> ```Board:...``` -> ```Boards Manager```. Søg på "esp" og installer pakken ved navn esp8266 by ESP8266 Community".


### 2: Installer MQTT Bibliotek
Gå ind i ```Sketch``` -> ```Include Library``` -> ```Manage Libraries```, søg på "mqtt" og installer biblioteket ved navn "MQTT by Joel Gaehwiler".


### 3: Installer drivere  
Tjek først om der er brug for at installere en driver. Nyere versioner af styresystemet på macbooks skulle efter sigende ikke have brug for at installere drivere.

Du finder ud af om det er nødvendigt således: Vælg først det korrekte board ```WeMos D1 R1``` under ```Tools``` -> ```Board:...```. Hvis der kommer en port frem under ```Tools``` -> ```Port``` når du tilslutter boardet har du ikke brug for at installere en driver. Hvis der ikke kommer en port frem, skal du følge trinnene nedenfor.

Download og installer driveren fra følgende link: [http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx](http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx)
Husk at genstarte din computer inden du tester om det virker.

Hvis du bruger en macbook og ovenstående link ikke virker, så prøv dette link: [https://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html#high-sierra](https://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html#high-sierra)  
Husk igen at genstarte inden du tester om det virker.
