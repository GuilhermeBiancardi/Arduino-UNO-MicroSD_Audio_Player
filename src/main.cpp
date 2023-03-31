/**
 * MicroSD 5v
 */

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include "TMRpcm.h"

#define pinCS 10
#define pinSCK 13
#define pinMOSI 11
#define pinMISO 12
#define pinAutoFalante 9

TMRpcm tmrpcm;

void setup() {
    
    Serial.begin(9600);
    // Serial.begin(115200);

    if(!SD.begin(pinCS)) {
        Serial.println("Falha na inicialização do SD Card.");
        return;
    }

    // Play WAV files
    tmrpcm.speakerPin = pinAutoFalante;
    tmrpcm.setVolume(6);
    tmrpcm.quality(1);
    tmrpcm.play("teste.wav");

}

void loop() {}