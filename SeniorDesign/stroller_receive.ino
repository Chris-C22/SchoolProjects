// libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

// globals
Servo brakeServos;  // declare servo motors
byte character = 0; // Raspberry Pi communication

// DC motors
int E1 = 5; // enables
int E2 = 6;
int M1 = 4; // motors
int M2 = 2;

const int pressureThreshold = 100; // smallest threshold for human touch
const int servoSpeed = 2; // smaller = slower
bool initialPos = false; // check if servo is back in initial position

// radio module
RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001"; // radio channel

// structure for sensor data
struct sensorData{
  int fsrValue;
  int potValue;
};

// receiving data
sensorData receivedValue;

// setup
void setup() {
  Serial.begin(9600);
  brakeServos.attach(10); // Attach servo to pin 10
  radio.begin();  // radio communication
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(M1, OUTPUT);  // set M1 to output
  pinMode(M2, OUTPUT);  // set M2 to output
}

void loop() {
  if (Serial.available()) {
    character = Serial.read();
  	
	  if (character == 'T'){
		  motors();
    }
  }
}

void motors(){
  if (radio.available()) {

    radio.read(&receivedValue, sizeof(receivedValue));

    // threshold checks
    if (receivedValue.fsrValue >= pressureThreshold){
      if (initialPos){
        brakeServos.write(90);
        initialPos = false;
      }
      else{
        brakeServos.write(90);
      }
      DC_motor();
    }
    else if (!initialPos){
      initialPos = true;
      for (int pos = brakeServos.read(); pos >= 0; pos -= servoSpeed){
        brakeServos.write(pos); 
        delay(15);
        radio.read(&receivedValue.fsrValue, sizeof(receivedValue.fsrValue));
        if (receivedValue.fsrValue >= pressureThreshold){
          brakeServos.write(90);
          initialPos = false;
          break;
        }
      }
    }
/*
    // Print the received FSR and potentiometer values to the Serial monitor
    Serial.print("Received FSR Value: ");
    Serial.println(receivedValue.fsrValue);
    Serial.print("Received Potentiometer Value: ");
    Serial.println(potValue);
    delay(500);
*/
  }

}

void DC_motor() {
      // Read the potentiometer value
    int potValue = receivedValue.potValue;

    // Map the potentiometer value to the range of motor speeds (0-255)
    int motorSpeed = map(potValue, 0, 1023, 0, 255);

    // Set the motor speed
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, motorSpeed);
    analogWrite(E2, motorSpeed); // Assuming the DC motor is connected to pin 4
    delay(30);
} 

/*
#Arduino code
byte character = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()) {
  character = Serial.read();
  	
	if character = F:
		*Standby*
	if character = T:
		*Motor Code*

}
}
*/
