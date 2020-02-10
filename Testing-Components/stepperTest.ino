    // Define stepper motor connections and steps per revolution:
    #define dirPin 2
    #define stepPin 3
    #define stepsPerRevolution 200
    //Relay Pin macro; will be used for the first relay.
    #define RELAY1 6

    //Global Variables
    int water_sensor_reading1 = 0;  // holds the value
    int water_sensor_reading2 = 0;
    int water_sensor_reading3 = 0;
    int realReading = 0;
    int sensor_pin = A5; // sensor pin used
    
    void setup() {
      // Declare pins as output:
      pinMode(stepPin, OUTPUT);
      pinMode(dirPin, OUTPUT);
      pinMode(RELAY1,OUTPUT);
      Serial.begin(9600);
    }
    void loop() {
      //Activating the relay to supply 12V to stepper driver.
      digitalWrite(RELAY1,LOW);  //The INT1 input on the relay is Active Low Input, hence setting to LOW for Activation

      //Water Level Sensor reading status of water level
      water_sensor_reading1 = analogRead(sensor_pin); //Read data from analog pin and store it to resval variable
      delay(500);
      water_sensor_reading2 = analogRead(sensor_pin);
      delay(500);
      water_sensor_reading3 = analogRead(sensor_pin);
      realReading = (water_sensor_reading1+water_sensor_reading2+water_sensor_reading3)/3;

      //Printing the average water level reading.
      Serial.println(realReading);

       if(realReading<75){ 
        Serial.println("Water Level: Continue..."); 
      }
      else if(realReading>=75){
        Serial.println("Water Level: Stop the tap.");
      }
      // Set the spinning direction clockwise:
      digitalWrite(dirPin, HIGH);
      
      // Spin the stepper motor 1 revolution slowly:
      for (int i = 0; i < stepsPerRevolution; i++) {
        // These four lines result in 1 step:
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(2000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(2000);
      }
      delay(1000);
      // Set the spinning direction counterclockwise:
      digitalWrite(dirPin, LOW);
      // Spin the stepper motor 1 revolution quickly:
      for (int i = 0; i < stepsPerRevolution; i++) {
        // These four lines result in 1 step:
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
      }
      delay(1000);
      // Set the spinning direction clockwise:
      digitalWrite(dirPin, HIGH);
      // Spin the stepper motor 5 revolutions fast:
      for (int i = 0; i < 5 * stepsPerRevolution; i++) {
        // These four lines result in 1 step:
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
      }
      delay(1000);
      // Set the spinning direction counterclockwise:
      digitalWrite(dirPin, LOW);
      //Spin the stepper motor 5 revolutions fast:
      for (int i = 0; i < 5 * stepsPerRevolution; i++) {
        // These four lines result in 1 step:
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
      }
      delay(1000);
    }
