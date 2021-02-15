#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial sfserial;

void setup()
{
    Serial.begin(9600);

    sfserial.begin(9600, SWSERIAL_8N1, D5, D6, false, 95, 11);
    
    Serial.println(PSTR("\nSoftware serial test started"));

    for (char ch = ' '; ch <= 'z'; ch++)
    {
        sfserial.write(ch);
    }
    sfserial.println();
}

void loop()
{
    while (sfserial.available() > 0)
    {
        Serial.write(sfserial.read());
        yield();
    }
    while (Serial.available() > 0)
    {
        sfserial.write(Serial.read());
        yield();
    }
}