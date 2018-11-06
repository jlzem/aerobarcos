// 1a. Competicao de Aerobarcos - 2s2018
// Escola de Engenharia de Piracicaba - EEP
// Programa : NRF24L01 Transmissor - Controlador
// Versao 1.0

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

char buffer[10];

int pin_POT = A0;
int graus = 0;

RF24 radio(9,10);

// Essa chave deve ser diferente para cada equipe participante, porém igual em ambos os programas da mesma equipe.
const uint64_t pipe = 0xE13CBAF433LL;

void setup() {

  Serial.begin(9600);
  radio.begin();
  radio.setChannel(100);
  radio.openWritingPipe(pipe);
  
}

void loop() {
    
    graus = analogRead(pin_POT);
    graus = map(graus,0,1023,180,0);

    sprintf(buffer,"%d",graus);
    Serial.write(buffer);
    Serial.write("\n");   
    radio.write(buffer, sizeof(buffer));

    delay(500);
}

