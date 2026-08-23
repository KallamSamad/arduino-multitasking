#define LED_PIN_1 9
#define LED_PIN_2 10
#define LED_PIN_3 11
#define POTENTIOMETER_PIN A2
#define BUTTON_PIN 2


unsigned long startTime=millis(); 
unsigned long blinkDelay = 500;
int LEDState2 = LOW;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(BUTTON_PIN,INPUT);
  
}

void loop() {
  unsigned long loopTime=millis();
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if ((data >= 100) && (data <= 4000)) {
      blinkDelay = data;
    }
  }

  if(loopTime-startTime>blinkDelay){

  if (LEDState2 == LOW) {
    LEDState2 = HIGH;
  }
  else {
    LEDState2 = LOW;
  }
  digitalWrite(LED_PIN_2, LEDState2);
  startTime+=blinkDelay;
}

int resistance=analogRead(POTENTIOMETER_PIN);
int convertedResistance=resistance/4;
analogWrite(LED_PIN_1,convertedResistance);

if(digitalRead(BUTTON_PIN)==HIGH){
  digitalWrite(LED_PIN_3,HIGH);
}else{
  digitalWrite(LED_PIN_3, LOW);
}
}
