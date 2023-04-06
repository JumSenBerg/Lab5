#include <Servo.h>

#define trigPin 2
#define echoPin 3
#define servoPin 9

Servo myservo;
int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance < 10) {
    for (pos = 0; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
}

