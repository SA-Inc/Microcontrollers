int temperature; // C

void turnOnLED(int pin) {
  digitalWrite(pin, HIGH);
}

void turnOffLED(int pin) {
  digitalWrite(pin, LOW);
}

void turnOnAllLEDs() {
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
}

void turnOffAllLEDs() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
}

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT); // Temperature
  
  pinMode(13, OUTPUT); // WHITE
  pinMode(12, OUTPUT); // BLUE
  pinMode(11, OUTPUT); // GREEN
  pinMode(10, OUTPUT); // YELLOW
  pinMode(9, OUTPUT); // RED
  
  turnOnAllLEDs();
  delay(1000);
  turnOffAllLEDs();
  turnOnLED(13);
}

void loop()
{
  temperature = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.print("Temperature: ");
  Serial.println(temperature);
    
  if (temperature < 15) {
  	turnOnLED(12);
    turnOffLED(11);
    turnOffLED(10);
    turnOffLED(9);
  } else if (temperature >= 15 && temperature < 20) {
  	turnOnLED(11);
    turnOffLED(12);
    turnOffLED(10);
    turnOffLED(9);
  } else if (temperature >= 20 && temperature < 30) {
  	turnOnLED(10);
    turnOffLED(11);
    turnOffLED(12);
    turnOffLED(9);
  } else if (temperature >= 30) {
  	turnOnLED(9);
    turnOffLED(11);
    turnOffLED(10);
    turnOffLED(12);
  }
  
  delay(1000);
}
