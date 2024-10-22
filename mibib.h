
#include <ESP8266WiFi.h>
#include <strings_en.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <Ticker.h>
#define pin_ledWifi D4

Ticker ticker;
void parpadeoLedWifi(){
byte estado = digitalRead(pin_ledWifi);
digitalWrite(pin_ledWifi, !estado);
}

void conectaWifi(){
 Serial.begin(115200);
 pinMode(pin_ledWifi, OUTPUT);              //para que el led D4 parapadee cuando se conecta
 ticker.attach(0.2,parpadeoLedWifi);         

 WiFiManager wifiManager;  //creamos el objeto

 //descomentar para resetear configuracion
 //wifiManager.resetSettings();

 if(!wifiManager.autoConnect("ESP8266Temp", "12345678")){
 Serial.println("Falló la conexión");
 ESP.reset();
 delay(1000);
 }

 Serial.println("Ya esta conectado");
 //eliminemos el temporizador
 ticker.detach();
 
 //Apagamos LED
 digitalWrite(pin_ledWifi, HIGH);

}