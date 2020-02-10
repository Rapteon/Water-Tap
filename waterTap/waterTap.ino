//Global variables.
int runState;
int water_sensor_reading1;  // holds the first value
int water_sensor_reading2;  // holds the second value
int water_sensor_reading3;  // holds the third value
int averageReading;

//Pins
const int buttonPin = 4;
const int sensorPin = A5;
const int builtInLEDpin = 13;
const int relayPin = 6;

//Motor Driver pin initialization.
const int dirPin = 2;
const int stepPin = 3;

//To store the read and store the state of the button in it.
int buttonState = 0;
//Setting the high water level as a constant value.
const int highWaterLevel = 75;
//The number of steps required for a revolution.
const int stepsPerRevolution = 200;

void setup(){
  //Setup pins for I/O
  pinMode(buttonPin,INPUT); //For reading button-press.
  pinMode(builtInLEDpin,OUTPUT);  //For lighting up on button-press.
  pinMode(stepPin, OUTPUT); //Motor driver pin
  pinMode(dirPin, OUTPUT);  //Motor driver pin
  pinMode(relayPin,OUTPUT);
  
  runState = 0;
  averageReading = 0;
  
  //Terminal initialized
  Serial.begin(9600);

  //Reading water level sensor readings every half second.
  water_sensor_reading1 = analogRead(sensorPin); //Read data from analog pin and store it to resval variable
  delay(500);
  water_sensor_reading2 = analogRead(sensorPin);
  delay(500);
  water_sensor_reading3 = analogRead(sensorPin);
  averageReading = (water_sensor_reading1+water_sensor_reading2+water_sensor_reading3)/3;
  Serial.print("High Water Level: ");
  Serial.println(highWaterLevel);
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    runState = 1;
    digitalWrite(builtInLEDpin,HIGH); //This is to verify that the button was pressed.
    Serial.println("Button Pressed"); //Button-press displayed on the terminal.
    digitalWrite(builtInLEDpin,LOW);
    
    //Reading the level of water.
    water_sensor_reading1 = analogRead(sensorPin); //Read data from analog pin and store it to resval variable
    delay(500);
    water_sensor_reading2 = analogRead(sensorPin);
    delay(500);
    water_sensor_reading3 = analogRead(sensorPin);
    averageReading = (water_sensor_reading1+water_sensor_reading2+water_sensor_reading3)/3;
    Serial.print("High Water Level: ");
    Serial.println(highWaterLevel);
  }//if ends
  
  if(runState == 1){
    //Code to run motor and open tap.
    Serial.println("Open tap here.");
    while(averageReading < highWaterLevel){
      water_sensor_reading1 = analogRead(sensorPin); //Read data from analog pin and store it to resval variable
      delay(500);
      water_sensor_reading2 = analogRead(sensorPin);
      delay(500);
      water_sensor_reading3 = analogRead(sensorPin);
      averageReading = (water_sensor_reading1+water_sensor_reading2+water_sensor_reading3)/3;
      Serial.print("Average Water Level: ");
      Serial.println(averageReading);
    }
    
    runState = 0; //'runState' needs to be set to '0' since it is a global variable;
    //Code to run the motor and close the tap.
    Serial.println("Close tap here.");
  }//if ends
  Serial.println("Tap is closed.");
  buttonState = digitalRead(buttonPin);
}
