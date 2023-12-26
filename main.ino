// Pin definitions
#define FrontTrigPin 2
#define FrontEchoPin 3
#define LeftTrigPin 4
#define LeftEchoPin 5
#define RightTrigPin 6
#define RightEchoPin 7
#define IRpin A0
#define MotorA1Pin 8
#define MotorA2Pin 9
#define MotorB1Pin 10
#define MotorB2Pin 11
#define ESCpin 12
#define PotPin A1
#define btRX 13
#define btTX 14

// Variables
int speed = 100; // an average speed was used so as not to make the robot move too fast
int distance_front, distance_left, distance_right;
int ir_value;

unsigned long previous_time_front = 0;
unsigned long previous_time_obstacle = 0;
unsigned long previous_time_step = 0;

const int interval_front = 100;
const int interval_obstacle = 500;
const int interval_step = 500;

void setup() {
  pinMode(FrontTrigPin, OUTPUT);
  pinMode(FrontEchoPin, INPUT);
  pinMode(LeftTrigPin, OUTPUT);
  pinMode(LeftEchoPin, INPUT);
  pinMode(RightTrigPin, OUTPUT); 
  pinMode(RightEchoPin, INPUT);
  pinMode(IRpin, INPUT);
  pinMode(MotorA1Pin, OUTPUT);
  pinMode(MotorA2Pin, OUTPUT);
  pinMode(MotorB1Pin, OUTPUT);
  pinMode(MotorB2Pin, OUTPUT);
  pinMode(ESCpin, OUTPUT);
  pinMode(PotPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Check for Bluetooth commands
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch(command) {
      case 'F':
        motor_control(speed, speed);
        break;
      case 'L':
        motor_control(-speed, speed);
        break;
      case 'R':
        motor_control(speed, -speed);
        break;
      case 'B':
        motor_control(-speed, -speed);
        break;
      default:
        motor_control(0, 0);
        break;
    }
  } else {
    // Navigating
    if (millis() - previous_time_front >= interval_front) {
      previous_time_front = millis();
      distance_front = ultrasonic_sensor(FrontTrigPin, FrontEchoPin);
      if (distance_front > 20) {
        motor_control(speed, speed);
      } else {
        if (distance_left > distance_right) {
          motor_control(-speed, speed);
        } else {
          motor_control(speed, -speed);
        }
      }
    }

    // Checking for obstacles
    if (distance_left < 15 || distance_right < 15) {
      if (millis() - previous_time_obstacle >= interval_obstacle) {
        previous_time_obstacle = millis();
        motor_control(-speed, -speed);
        delay(500);
        motor_control(-speed, speed);
      }
    }

    // Checking for steps
    if (ir_sensor()) {
      if (millis() - previous_time_step >= interval_step) {
        previous_time_step = millis();
        motor_control(-speed, -speed);
        delay(500);
        motor_control(speed, -speed);
      }
    }

    // Control vacuum motor 
    int pot_value = analogRead(PotPin);
    int mapped_value = map(pot_value, 0, 1023, 0, 255);
    analogWrite(ESCpin, mapped_value);
  }
}


    
