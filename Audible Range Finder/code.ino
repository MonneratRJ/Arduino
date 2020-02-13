// defines pins numbers
#define trigPin 3
#define echoPin 4
#define buzzer 9

// defines variables
long duration; int distance, frequency;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  // Debug Reasons.
  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.035/2;
  //Serial.print("Distance in cm: ");Serial.println(distance);
  
  // Set the SOUND to warn Distance, higher pitch = closer
  // map(value, fromLow, fromHigh, toLow, toHigh)
  frequency = map(distance, 2, 336, 494, 262);
  Serial.print("Frequency in Hz: ");Serial.println(frequency);
  
  // Play sound
  noTone(buzzer);
  tone(buzzer, frequency);
}