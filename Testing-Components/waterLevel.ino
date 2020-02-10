//Global Variables
int water_sensor_reading1 = 0;  // holds the value
int water_sensor_reading2 = 0;
int water_sensor_reading3 = 0;
int realReading = 0;
int sensor_pin = A5; // sensor pin used
  
void setup() { 
  // start the serial console
  Serial.begin(9600);
}  
void loop() {   
  water_sensor_reading1 = analogRead(sensor_pin); //Read data from analog pin and store it to resval variable
  delay(500);
  water_sensor_reading2 = analogRead(sensor_pin);
  delay(500);
  water_sensor_reading3 = analogRead(sensor_pin);
  realReading = (water_sensor_reading1+water_sensor_reading2+water_sensor_reading3)/3;
  Serial.println(realReading);
  if (realReading<75){ 
    Serial.println("Water Level: Continue..."); 
  }
  else if(realReading>=75){
    Serial.println("Water Level: Stop the tap.");
  }
//  }
//  else if(water_sensor_reading>250 && water_sensor_reading<=300){
//    Serial.println("Water Level: Medium");
//  }
//  else if(water_sensor_reading>300){ 
//    Serial.println("Water Level: High"); 
//  }
}
