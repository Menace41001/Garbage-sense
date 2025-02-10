#define TRIG_PIN 10  
#define ECHO_PIN 11  

void setup() {
    Serial.begin(9600);   // Start Serial Monitor
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    return (duration * 0.0343) / 2; // Convert to cm
}

void loop() {
    float distance = getDistance();

    Serial.print("Measured Distance: ");
    Serial.print(distance);
    Serial.print(" cm -> ");

    // Determine the garbage level based on distance
    if (distance > 16) {
        Serial.println("Garbage Level: 0% (Empty)");
    } else if (distance > 11) {
        Serial.println("Garbage Level: 25% Full");
    } else if (distance > 6) {
        Serial.println("Garbage Level: 50% Full");
    } else if (distance > 3) {
        Serial.println("Garbage Level: 75% Full");
    } else {
        Serial.println("🚨 Garbage Level: 100% FULL! Please Empty the Bin 🚨");
    }

    delay(2000); // Increased delay for better readings
}

