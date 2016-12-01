#include <Servo.h>
#include <MyoController.h>


#define FIST_PIN 4
#define WAVEIN_PIN 5
#define WAVEOUT_PIN 6
#define FINGERSSPREAD_PIN 7
#define DOUBLETAP_PIN 8

MyoController myo = MyoController();
Servo serv;

void setup() {
  serv.attach(11);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(3, OUTPUT);


  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
  Serial.begin(9600);
  myo.initMyo();
  digitalWrite(3,HIGH);
  delay(300);
  digitalWrite(3,LOW);
  delay (150);
  digitalWrite(3,HIGH);
  delay(300);
  digitalWrite(3,LOW);
  delay (300);
  digitalWrite(3,HIGH);
  delay(1500);
  digitalWrite(3,LOW);
  
}

void loop(){
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      digitalWrite(FIST_PIN,LOW); 
      digitalWrite(WAVEIN_PIN,LOW);
      digitalWrite(WAVEOUT_PIN,LOW);
      digitalWrite(FINGERSSPREAD_PIN,LOW);
      digitalWrite(DOUBLETAP_PIN,LOW);
      digitalWrite(9,LOW);
      break;
    case fist:
      digitalWrite(FIST_PIN,HIGH);
      digitalWrite(9,HIGH);
      serv.write(90);
      break;
    case waveIn:
      digitalWrite(WAVEIN_PIN,HIGH);
      digitalWrite(9, HIGH);
      serv.write(180);
      break;
    case waveOut:
      digitalWrite(WAVEOUT_PIN,HIGH);
      digitalWrite(9, HIGH);
      serv.write(0);
      break;
    case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN,HIGH);
      break;
    case doubleTap:
      if (digitalRead(8) == HIGH){
        digitalWrite(8,LOW);
      }
      else{
        digitalWrite(8,HIGH);
      }
      break;
   } 
   delay(100);
}
