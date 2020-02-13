int ledPin = 2;
int led2Pin = 6;
int inPin = 7;
unsigned long timer = 0;
unsigned long blink = 0;

void setTimer(int duration) {
  digitalWrite(ledPin, HIGH);
  timer = millis();
  timer += duration;
}

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop()
{
  // SET TIMER E APAGA O LED APOS O TEMPO
  if (!digitalRead(inPin)) {
    setTimer(1000);
  }
  if (timer < millis()) {
  	digitalWrite(ledPin, LOW);
  }
  
  // CRIA UM BLINK DE 1 SEGUNDO NO LED ONBOARD 13
  if(blink < millis()){
    if(digitalRead(led2Pin)){
      digitalWrite(led2Pin, LOW);
    } else {
      digitalWrite(led2Pin, HIGH);
    }
    blink += 1000;
  }
}