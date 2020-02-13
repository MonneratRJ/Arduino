// defines pins numbers
const int trigPin=10, echoPin=11;
const int led6=4,led5=5,led4=6,led3=7,led2=8,led1=9;

// defines variables
long duration; int distance;

void clearLights() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
}

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  //Serial.begin(9600); // Starts the serial communication
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
  // Set the LED to warn Distance
  clearLights();
  if(distance<56){
    digitalWrite(led6, HIGH);
  } else if(distance >= 56 && distance < 112) {
    digitalWrite(led6, HIGH);
    digitalWrite(led5, HIGH);
  } else if(distance >= 112 && distance < 168) {
    digitalWrite(led6, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led4, HIGH);
  } else if(distance >= 168 && distance < 224) {
    digitalWrite(led6, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
  } else if(distance >= 224 && distance < 280) {
    digitalWrite(led6, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led6, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
  }
  // Prints the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.println(distance);
}