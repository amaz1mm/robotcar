#include "UCMotor.h"

#define MAX_SPEED 255

UC_DCMotor leftMotor1(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor1(4, MOTOR34_64KHZ);
UC_DCMotor leftMotor2(1, MOTOR34_64KHZ);
UC_DCMotor rightMotor2(2, MOTOR34_64KHZ);

String received_string = "";
long prev_sensor_time=0;
int prev_sensor_value=-1;

void setup()
{
    Serial.begin(9600);
    leftMotor1.setSpeed(MAX_SPEED);
    rightMotor1.setSpeed(MAX_SPEED);
    leftMotor2.setSpeed(MAX_SPEED);
    rightMotor2.setSpeed(MAX_SPEED);
    pinMode(13, OUTPUT);
    stop();
}

void loop(){
    static long prev_time = 0;
    while(Serial.available()){
        char temp_char = Serial.read(); // receive a character from BT port
        received_string.concat(temp_char); // add the received character to buffer 'received_string'
        if(temp_char == '#'){
            if(received_string == "m_f#")
                moveForward();            

            else if(received_string == "m_b#")
                moveBackward();
            
            else if(received_string == "t_l#")
                turnLeft();
            
            else if(received_string == "t_r#")
                turnRight();
            
            Serial.println(received_string);
            received_string = "";
        }
        
        prev_time = millis();
    }

    if(millis() - prev_time > 500)
        stop();
    
    // Check sensor value every 200ms and sends only when it is different
    if(millis() - prev_sensor_time > 200){
        int sensor_value = analogRead(A1);
        if (sensor_value != prev_sensor_value){
          String message = "s_A1=";
          message += sensor_value;
          SendMessage(message);
          prev_sensor_value = sensor_value;
        }
        prev_sensor_time = millis();
    }
}

void SendMessage(String data) {
  Serial.println(data);
}

void moveForward()
{
    leftMotor1.run(FORWARD);
    rightMotor1.run(FORWARD);
    leftMotor2.run(FORWARD);
    rightMotor2.run(FORWARD);
}

void moveBackward()
{
  leftMotor1.run(BACKWARD);
  rightMotor1.run(BACKWARD);
  leftMotor2.run(BACKWARD);
  rightMotor2.run(BACKWARD);   
}

void turnRight()
{
  leftMotor1.run(FORWARD);
  rightMotor1.run(BACKWARD);
  leftMotor2.run(FORWARD);
  rightMotor2.run(BACKWARD);
}

void turnLeft()
{
  leftMotor1.run(BACKWARD);
  rightMotor1.run(FORWARD);
  leftMotor2.run(BACKWARD);
  rightMotor2.run(FORWARD);
}

void stop()
{
  leftMotor1.run(5); rightMotor1.run(5);
  leftMotor2.run(5); rightMotor2.run(5);
}