// 1a. Competicao de Aerobarcos - 2s2018
// Escola de Engenharia de Piracicaba - EEP
// Programa : NRF24L01 Receptor - Embarcacao
// Versao 1.0

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Servo.h> 

char recebidos[10];

int pinservo = 8;
int pininb = 5;
int pinina = 6;

RF24 radio(9,10);
Servo myservo;

// Essa chave deve ser diferente para cada equipe participante, porém igual em ambos os programas da mesma equipe.
const uint64_t pipe = 0xE13CBAF433LL;

void setup() {

  Serial.begin(9600);
  
  radio.begin();
  radio.setChannel(100);
  radio.openReadingPipe(1,pipe);
  radio.startListening();

  myservo.attach(pinservo);  

  pinMode(pininb,OUTPUT);
  pinMode(pinina,OUTPUT);
  
  Serial.println("Aguardando dados...");
  
}

void loop() {

  digitalWrite(pininb,HIGH);
  digitalWrite(pinina,LOW);

  if (radio.available()) {
    
       radio.read(recebidos, sizeof(recebidos));
       //Serial.write(recebidos);
       Serial.print(atoi(recebidos),DEC);
       Serial.println(""); 

       myservo.write(atoi(recebidos));       
  } 
   
  delay(100);
}

