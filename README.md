# float_sensor
// The program checks the float switch every 15 minutes
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
const int TopButton = 10;     // Blue - Black; the number of the top reed button
const int BotButton = 11;    // White/Blue - Red; the number of the bottom reed button
const int Relay  =  4;      // the number of the LED pin

// variables will change:
int TopButState = 0;         // variable for reading the Top reed status
int BotButState = 0;         // variable for reading the Buttom reed stat
boolean TopSt = 0;
boolean BotSt = 0;
boolean Run= 0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(Relay, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(TopButton, INPUT_PULLUP);
  pinMode(BotButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
    unsigned long currentTime = millis();

      // read the state of the pushbutton value:
  TopButState = digitalRead(TopButton); //
  BotButState = digitalRead (BotButton); // Bot must be taken as reverse
  
//  if(TopButState == HIGH ){
//    Run =1;
//    Serial.println("TOP - HIGH");
//    }
//    
//  if(BotButState == LOW){
//    Run=1;
//    Serial.println("Bot - HIGH");
//  } else if(BotButState==HIGH){
//    Run=0;
//    Serial.println("Bot - LOW");
//  }

  if(currentTime-previousTime >= eventInterval){

  if(TopButState == HIGH){
    Run=1;
    Serial.println("Top - HIGH");
  } else if(TopButState==LOW){
    Run=0;
    Serial.println("Top - LOW");
  }

     previousTime = currentTime;
  }  




if (Run==1&&TopButState==HIGH){
  digitalWrite(Relay, HIGH); 
 // Serial.println("Motor Running!");
}else if (TopButState==LOW){
  digitalWrite(Relay, LOW); 
//  Serial.println("Motor Not Running!");
}
}
