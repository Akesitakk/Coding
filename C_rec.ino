String command;
void setup() {
  // initialize serial communication:
  pinMode(3, OUTPUT);  //pwm1
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);  // PWM2
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, OUTPUT);  //pwm3
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);  // PWM4
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);

  stop(100);
}
void loop()
{
  command = Serial.readStringUntil('\n');
  Serial.println(command);
  if (command.equals("0")){
    stop(100);
  }
  else if (command.equals("1")){
    FW(100);
  }
  else if(command.equals("2")){
    BW(100);
  }
  else if(command.equals("3")){
    SL(100);
  }
  else if(command.equals("4")){
    SR(100);
  }
  else if(command.equals("5")){
    FL(100);
  }
  else if(command.equals("6")){
    FR(100);
  }
  else if(command.equals("7")){
    BL(100);
  }
  else if(command.equals("8")){
    BR(100);
  }
  else{
    stop(100);
  }
  //stop(1000);
}
void stop(int a) {
  digitalWrite(13, LOW);  // F
  digitalWrite(2, LOW);
  analogWrite(3, 0);
  digitalWrite(5, LOW);  // F
  digitalWrite(4, LOW);
  analogWrite(6, 255);
  digitalWrite(7, LOW);  // F
  digitalWrite(8, LOW);
  analogWrite(9, 255);
  digitalWrite(11, LOW);  // F
  digitalWrite(12, LOW);
  analogWrite(10, 255);
  delay(a);
}
void FW(int a) {
  digitalWrite(13, LOW);  // F
  digitalWrite(2, HIGH);
  analogWrite(3, 255);
  digitalWrite(5, HIGH);  // F
  digitalWrite(4, LOW);
  analogWrite(6, 255);
  digitalWrite(7, HIGH);  // F
  digitalWrite(8, LOW);
  analogWrite(9, 255);
  digitalWrite(11, LOW);  // F
  digitalWrite(12, HIGH);
  analogWrite(10, 255);
  delay(a);
}
void BW(int a) {
  digitalWrite(13, HIGH);  // F
  digitalWrite(2, LOW);
  analogWrite(3, 255);
  digitalWrite(5, LOW);  // F
  digitalWrite(4, HIGH);
  analogWrite(6, 255);
  digitalWrite(7, LOW);  // F
  digitalWrite(8, HIGH);
  analogWrite(9, 255);
  digitalWrite(11, HIGH);  // F
  digitalWrite(12, LOW);
  analogWrite(10, 255);
  delay(a);
}
void FR(int a) {
  digitalWrite(13, LOW);  // F
  digitalWrite(2, HIGH);
  analogWrite(3, 255);
  digitalWrite(5, LOW);  // F
  digitalWrite(4, LOW);
  analogWrite(6, 255);
  digitalWrite(7, LOW);  // F
  digitalWrite(8, LOW);
  analogWrite(9, 255);
  digitalWrite(11, LOW);  // F
  digitalWrite(12, HIGH);
  analogWrite(10, 255);
  delay(a);
}
void FL(int a) {
  digitalWrite(13, LOW);  // F
  digitalWrite(2, LOW);
  analogWrite(3, 255);
  digitalWrite(5, HIGH);  // F
  digitalWrite(4, LOW);
  analogWrite(6, 255);
  digitalWrite(7, HIGH);  // F
  digitalWrite(8, LOW);
  analogWrite(9, 255);
  digitalWrite(11, LOW);  // F
  digitalWrite(12, LOW);
  analogWrite(10, 255);
  delay(a);
}
void BL(int a) {
  digitalWrite(13, HIGH);  // F
  digitalWrite(2, LOW);
  analogWrite(3, 255);
  digitalWrite(5, LOW);  // F
  digitalWrite(4, LOW);
  analogWrite(6, 255);
  digitalWrite(7, LOW);  // F
  digitalWrite(8, LOW);
  analogWrite(9, 255);
  digitalWrite(11, HIGH);  // F
  digitalWrite(12, LOW);
  analogWrite(10, 255);
  delay(a);
}
void BR(int a) {
  digitalWrite(13, LOW);  // F
  digitalWrite(2, LOW);
  analogWrite(3, 255);
  digitalWrite(5, LOW);  // F
  digitalWrite(4, HIGH);
  analogWrite(6, 255);
  digitalWrite(7, LOW);  // F
  digitalWrite(8, HIGH);
  analogWrite(9, 255);
  digitalWrite(11, LOW);  // F
  digitalWrite(12, LOW);
  analogWrite(10, 255);
  delay(a);
}
void SR(int a) {
  digitalWrite(13, LOW);  // F
  digitalWrite(2, HIGH);
  analogWrite(3, 255);
  digitalWrite(5, LOW);  // F
  digitalWrite(4, HIGH);
  analogWrite(6, 255);
  digitalWrite(7, LOW);  // F
  digitalWrite(8, HIGH);
  analogWrite(9, 255);
  digitalWrite(11, LOW);  // F
  digitalWrite(12, HIGH);
  analogWrite(10, 255);
  delay(a);
}
void SL(int a) {
  digitalWrite(13, HIGH);  // F
  digitalWrite(2, LOW);
  analogWrite(3, 255);
  digitalWrite(5, HIGH);  // F
  digitalWrite(4, LOW);
  analogWrite(6, 255);
  digitalWrite(7, HIGH);  // F
  digitalWrite(8, LOW);
  analogWrite(9, 255);
  digitalWrite(11, HIGH);  // F
  digitalWrite(12, LOW);
  analogWrite(10, 255);
  delay(a);
}