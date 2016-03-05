/*
   Arduino Bluetooth HC-05 Invio di dati Analogici
   Semplice programmino per vedere come Arduino scambia dati prelevati da un sensore analogico e li invia tramite il modulo bluetooth HC-05

   Autore  : Andrea Lombardo
   Web     : http://www.lombardoandrea.com
   Post    : http://adf.ly/12267939/arduino-hc-05-invio-dati-sensore
   Git     : https://github.com/AndreaLombardo/Arduino-HC-05_Invio_Analog_Data
*/

//Includo libreria SoftwareSerial
#include <SoftwareSerial.h>

//definisco pin RX e TX da Arduino verso modulo BT
#define BT_TX_PIN 12
#define BT_RX_PIN 11
//definisco il pin del sensore analogico
#define PIN_SENSORE A0

//istanzio oggetto SoftwareSerial (il nostro futuro bluetooth)
SoftwareSerial bt =  SoftwareSerial(BT_RX_PIN, BT_TX_PIN);

int ultimaRilevazione = -1;

void setup() {

  //definisco modalità pin
  pinMode(BT_RX_PIN, INPUT);
  pinMode(BT_TX_PIN, OUTPUT);
  pinMode(PIN_SENSORE, INPUT);

  //inizializzo comunicazione Bluetooth
  bt.begin(9600);

}

void loop() {
  
  //leggo il dato dal sensore, e se diverso dall'ultima lettura lo invio al Bluetooth
  int dato = analogRead(PIN_SENSORE);
  
  if (dato != ultimaRilevazione) {
    //store dell'ultima rilevazione
    ultimaRilevazione = dato;
    bt.println(dato);
  }

  //ricontrollo ogni 1 secondo
  delay(1000);
}
