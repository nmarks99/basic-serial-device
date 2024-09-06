#include <Arduino.h>

constexpr int MAX_MSG_LENGTH = 10;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.begin(9600);
}

int count = 0;
char data[100];
void loop() {
    if (Serial.available() > 0) {
        int len = Serial.readBytesUntil('\n', data, MAX_MSG_LENGTH);
        data[len] = '\0';
        if (strcmp(data, "?") == 0) {
            Serial.println(digitalRead(LED_BUILTIN));
        } else if (strcmp(data, "1") == 0) {
            digitalWrite(LED_BUILTIN, HIGH);
        } else if (strcmp(data, "0") == 0) {
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}
