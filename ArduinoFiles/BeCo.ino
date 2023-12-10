// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;
int speed;
int control;

void setup() {

  Serial.begin(9600);
  delay(500);

	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  stop();
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void loop() {
  
  if (Serial.available()){
    
    control = Serial.read();
    delay(10);
  }
    if (control == 65 ){
      accelerate();
    }
    else if (control == 66){
      back();
    }
    else if (control == 82){
      right();
    }
    else if (control == 76){
      left();
    }
    else if (control == 83){
      stop();
    }
    else{
      speed = control;
      analogWrite(enA, speed);
      analogWrite(enB, speed);
    }
  delay(100); 
}

// This function lets you control spinning direction of motors
void accelerate() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void back() {

	// Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {

	// Turn on motors
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}

void right() {

	// Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop(){
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}






