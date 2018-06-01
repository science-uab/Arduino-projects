RUSUA MARIUS ANUL 1 MASTER PABD
Proiect arduino
Pentru acest proiect am folosit:
-Placa de dezvoltare UNO R3 compatibil Arduino -1 bucata
-LCD Display 1602 albastru + adaptor i2c   - 1 bucata
-Modul senzor culoare TCS230     -1 bucata
-banda leduri RGB 10 leduri albe
-Buton MARE - Push Button 1 bucata
-Cablu alimentare (usb)
-Set de cartonase cu culorile:albastru, rosu, galben, verde, violet

Pebtru implementarea acestui proiect am folosit componenrele de amai sus.
Pentru codul-sursa am folosit urmatoarele biblioteci:
   # <LiquidCrystal_I2C.h>//biblioteca display LiquidCrystal_I2C lcd(0x27,20,4); 
   # <Adafruit_NeoPixel.h>  //biblioteca leduri pentru definirea benzii de leduri
Cum functioneaza?
-la alimentarea placii(proiectului) la o sursa de curent(fie ea de la usb-ul lapropului
sau a alimentatotului,  se face verificarea functionalitatii echipamentelor prin 
aprinderea ledurilor albe de la stanga la dreapta si de la dreapta la stanga, o singura data.
-pe ecranul proiectului se va afisa un mesaj: "WELCOME"
-din acest moment putem apasa butonul "verde", care are un rol de a pornii aplicatia.
-va aparea mesajul "APROPIE CULOAREA!"
-din setul de cartonase alegem o coloare la intamplare, apropiem culaoarea in zona de 
detectie a senzorilor, se apleleaza functia de citire a culorilor, apoi pe display apare
urmatorul mesaj:"culoarea este...."
-dupa ce mesajul a fost afisat se aprinde un led de pe banda de leduri cu culoarea detectata.

Reluam pasii de mai sus pentru fiecare culoare.Se vor aprinde treptat fiecare led cu culoarea identificata de senzori
pana la ledul cu nr10(inclusiv), dupa care daca continuam cu scanarea colorilor banda de leduri se reseteaza si 
se va afisa culoarea curenta.
In cazul in care timp de 8secunde nu avem nici o activitate asupra senzorilor, pe display apare mesajul
"WELCOME".
Din acest moment putem relua actiunea prin apasarea butonului "verde"

Va multumesc 
