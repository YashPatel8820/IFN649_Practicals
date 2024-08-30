#define LEDPIN 11
void setup() {
// Setup serial for monitor and Setup Serial1 for BlueTooth
    Serial.begin(9600);
    Serial1.begin(9600);
    pinMode(11, OUTPUT);
}

void loop() {
// Process commands from bluetooth first.
    if(Serial1.available() > 0){
        String str = Serial1.readString().substring(0);
        Serial.println(str);
        if(str == "LED_ON"){
            digitalWrite(11, HIGH);
            Serial.println("LED ON");
        } else if(str == "LED_OFF"){
            digitalWrite(11, LOW);
            Serial.println("LED OFF");
        }
    }
}