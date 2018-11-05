#include <Stepper.h> // Include the header file

// change this to the number of steps on your motor
#define STEPS 64

// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);

int Pval = 0;
int potVal = 0;
int btnDebut = 2;
int btnFin = 3;
int ledDebut = 5;
int ledFin = 6;
int buttonStateD = 0;
int buttonStateF = 0;
int debut = 0;
int fin = 0;

void setup() {
  pinMode(btnDebut, INPUT);
  pinMode(btnFin, INPUT);
  pinMode(ledDebut, OUTPUT);
  pinMode(ledFin, OUTPUT);
  Serial.begin(9600);
  stepper.setSpeed(50);
}

void loop() {
 buttonStateD = digitalRead(btnDebut);
 buttonStateF = digitalRead(btnFin);
 

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateD == HIGH) {
    // turn LED on:
    digitalWrite(ledDebut, HIGH);
    debut = potVal;
    Serial.println(debut);
    
  }
 else if (buttonStateF == HIGH) {
  digitalWrite(ledFin, HIGH);
  fin = potVal;
  Serial.println(fin);
 }
  else {
    // turn LED off:
    digitalWrite(ledDebut, LOW);
    digitalWrite(ledFin, LOW);
    
  }

potVal = map(analogRead(A0),0, 1048 ,0,500);
if (potVal>Pval)
  stepper.step(5);
if (potVal<Pval)
  stepper.step(-5);

Pval = potVal;

Serial.println(Pval); //for debugging
}






