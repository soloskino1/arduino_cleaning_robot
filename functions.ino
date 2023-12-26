
// Function to control motor
void motor_control(int left_speed, int right_speed) {
if (left_speed > 0) {
  digitalWrite(MotorA1Pin, HIGH);
  digitalWrite(MotorA2Pin, LOW);
  analogWrite(MotorB1Pin, left_speed);
} 
else if (left_speed < 0) {
  digitalWrite(MotorA1Pin, LOW);
  digitalWrite(MotorA2Pin, HIGH);
  analogWrite(MotorB1Pin, abs(left_speed));
}
else {
  digitalWrite(MotorA1Pin, LOW);
  digitalWrite(MotorA2Pin, LOW);
  analogWrite(MotorB1Pin, 0);
}

if (right_speed > 0) {
  digitalWrite(MotorB2Pin, HIGH);
  digitalWrite(MotorB1Pin, LOW);
  analogWrite(MotorA1Pin, right_speed);
} else if (right_speed < 0) {
  digitalWrite(MotorB2Pin, LOW);
  digitalWrite(MotorB1Pin, HIGH);
  analogWrite(MotorA1Pin, abs(right_speed));
} else {
  digitalWrite(MotorB2Pin, LOW);
  digitalWrite(MotorB1Pin, LOW);
  analogWrite(MotorA1Pin, 0);
}
}

// Function to read ultrasonic sensor
int ultrasonic_sensor(int trig_pin, int echo_pin) {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}    


// IR sensor function
bool ir_sensor() {
  ir_value = analogRead(IRpin);
  if (ir_value > 0) {
    return false;
  } else {
    return true;
  }
}
