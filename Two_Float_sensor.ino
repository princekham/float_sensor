/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/
//GPIO4 is Relay output
//Sensor switch are GPIO 14 and 16 (input pullup)
// For input pullup, see https://www.arduino.cc/en/Tutorial/BuiltInExamples/InputPullupSerial

const unsigned long eventInterval=900000; // every 15 minutes
unsigned long previousTime = 0;

// constants won't change. They're used here to set pin numbers:
const int TopButton = 10;     // W/Blue - Black; the number of the top reed button
const int BotButton = 11;    // Blue - Red; the number of the bottom reed button
const int Relay  =  4;      // the number of the LED pin

// variables will change:
int TopButState = 1;         // variable for reading the Top reed status
int BotButState = 1;         // variable for reading the Buttom reed stat
boolean TopButTrip = 0;
boolean BotButTrip = 0; // Assume that there is no water in the bottom tank
//boolean Run= 0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(Relay, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(TopButton, INPUT_PULLUP);
  pinMode(BotButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
    

      // read the state of the pushbutton value:
  TopButState = digitalRead(TopButton); //
  BotButState = digitalRead (BotButton); // Bot must be taken as reverse
  
if (TopButState == 1){
  BotButTrip=0;
}
if(BotButState == 1){
  BotButTrip=1;
}

if (BotButTrip==0  ){ // When the water level is high, turn on the motor
  digitalWrite(Relay, HIGH); 
  Serial.println("Motor Running!");
}else if (BotButTrip==1){ //else if the water level is low, turn off the motor
  digitalWrite(Relay, LOW); 
  Serial.println("Motor Not Running!");
}
}
