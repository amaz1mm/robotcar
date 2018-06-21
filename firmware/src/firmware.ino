
#define MOTOR1EN 10
#define MOTOR1INA 12
#define MOTOR1INB 13

#define MOTOR2EN 9
#define MOTOR2INA 8
#define MOTOR2INB 11

#define MAX_SPEED 120

String received_string = "";
long prev_sensor_time=0;
int prev_sensor_value=-1;

void setup()
{
    pinMode(MOTOR1EN, OUTPUT);
    pinMode(MOTOR1INA, OUTPUT);
    pinMode(MOTOR1INB, OUTPUT);

    pinMode(MOTOR2EN, OUTPUT);
    pinMode(MOTOR2INA, OUTPUT);
    pinMode(MOTOR2INB, OUTPUT);

    Serial.begin(9600);
    stop();
}

void loop(){
    // moveForward();
    // moveBackward();
    // turnLeft();
    // turnRight();

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
    digitalWrite(MOTOR1INA, LOW);
    digitalWrite(MOTOR1INB, HIGH);
    analogWrite(MOTOR1EN, 255);


    digitalWrite(MOTOR2INA, HIGH);
    digitalWrite(MOTOR2INB, LOW);
    analogWrite(MOTOR2EN, 255);
}

void moveBackward()
{
    digitalWrite(MOTOR1INA, HIGH);
    digitalWrite(MOTOR1INB, LOW);
    analogWrite(MOTOR1EN, 255);


    digitalWrite(MOTOR2INA, LOW);
    digitalWrite(MOTOR2INB, HIGH);
    analogWrite(MOTOR2EN, 255);
}

void turnRight()
{
    digitalWrite(MOTOR1INA, HIGH);
    digitalWrite(MOTOR1INB, LOW);
    analogWrite(MOTOR1EN, 255);


    digitalWrite(MOTOR2INA, HIGH);
    digitalWrite(MOTOR2INB, LOW);
    analogWrite(MOTOR2EN, 255);
}

void turnLeft()
{
    digitalWrite(MOTOR1INA, LOW);
    digitalWrite(MOTOR1INB, HIGH);
    analogWrite(MOTOR1EN, 255);

    digitalWrite(MOTOR2INA, LOW);
    digitalWrite(MOTOR2INB, HIGH);
    analogWrite(MOTOR2EN, 255);
}

void stop()
{
    analogWrite(MOTOR1EN, 0);
    analogWrite(MOTOR2EN, 0);
}