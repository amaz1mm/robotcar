#define RIGHT_MOTOR_A 9
#define RIGHT_MOTOR_B 6

#define LEFT_MOTOR_A 10
#define LEFT_MOTOR_B 5

#define SPEED 1

void setup(){
    Serial.begin(9600);

    pinMode(LEFT_MOTOR_A, OUTPUT);
    pinMode(LEFT_MOTOR_B, OUTPUT);
    pinMode(RIGHT_MOTOR_A, OUTPUT);
    pinMode(RIGHT_MOTOR_B, OUTPUT);
}

void loop(){
    static long prev_time = 0;

    if(Serial.available()){
        char command = Serial.read();
        switch(command){
            case 'f':
                forward();
                break;

            case 'b':
                reverse();
                break;

            case 'l':
                left();
                break;

            case 'r':
                right();
                break;    
        }

        prev_time = millis();
    }

    if(millis() - prev_time > 500)
        stop();
}

void reverse(){
    digitalWrite(LEFT_MOTOR_A, HIGH); 
    analogWrite(LEFT_MOTOR_B, 150);

    digitalWrite(RIGHT_MOTOR_A, HIGH); 
    analogWrite(RIGHT_MOTOR_B, 150);
}


void forward(){
    digitalWrite(LEFT_MOTOR_A, LOW); 
    analogWrite(LEFT_MOTOR_B, 105);

    digitalWrite(RIGHT_MOTOR_A, LOW); 
    analogWrite(RIGHT_MOTOR_B, 105);
}

void left(){
    digitalWrite(LEFT_MOTOR_A, HIGH); 
    analogWrite(LEFT_MOTOR_B, 150);

    digitalWrite(RIGHT_MOTOR_A, LOW); 
    analogWrite(RIGHT_MOTOR_B, 105);
}

void right(){
    digitalWrite(LEFT_MOTOR_A, LOW); 
    analogWrite(LEFT_MOTOR_B, 105);

    digitalWrite(RIGHT_MOTOR_A, HIGH); 
    analogWrite(RIGHT_MOTOR_B, 150);
}

void stop(){
    digitalWrite(LEFT_MOTOR_A, LOW); 
    analogWrite(LEFT_MOTOR_B, 0);

    digitalWrite(RIGHT_MOTOR_A, LOW); 
    analogWrite(RIGHT_MOTOR_B, 0);
}