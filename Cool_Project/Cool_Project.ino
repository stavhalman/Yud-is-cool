
#define EnA 9
#define EnB 10
#define EnC 11

int state = 0;

int frequency = 0;

int motor1pin1 = 4;
int motor1pin2 = 5;

int motor2pin1 = 6;
int motor2pin2 = 7;

int motor3pin1 = 2;
int motor3pin2 = 3;

int engine1 = 0;
int engine2 = 0;
int engine3 = 0;
  
void setup() {
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(EnC, OUTPUT);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  analogWrite(EnA, 100);
  analogWrite(EnB, 50);
  analogWrite(EnC, 50);
  
  Serial.begin(9600);
}
void engine_1(){
  if (engine1 == 1){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  }
  
  else if (engine1 == 2){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  }
  
  else{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  }
}
void engine_2(){
  if (engine2 == 1){
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  }
  
  else if (engine2 == 2){
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  }
  
  else{
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  }
}
void engine_3(){
  if (engine3 == 1){
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  }
  
  else if (engine3 == 2){
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  }
  
  else{
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  }
}
void loop() {
  if (Serial.available() > 0){
    char Incoming_value = Serial.read();
    Serial.print(Incoming_value);
    Serial.print("\n");
    if (Incoming_value == '0'){
      if (engine1 == 1){
        engine1 = 0;
      }else{
        engine1 = 1;
      }
      
    }
    if (Incoming_value == '1'){
      if (engine1 == 2){
        engine1 = 0;
      }else{
        engine1 = 2;
      }
      
    }
    if (Incoming_value == '2'){
      if (engine2 == 1){
        engine2 = 0;
      }else{
        engine2 = 1;
      }
      
    }
    if (Incoming_value == '3'){
      if (engine2 == 2){
        engine2 = 0;
      }else{
        engine2 = 2;
      }
      
    }
    if (Incoming_value == '4'){
      if (engine3 == 1){
        engine3 = 0;
      }else{
        engine3 = 1;
      }
      
    }
    if (Incoming_value == '5'){
      if (engine3 == 2){
        engine3 = 0;
      }else{
        engine3 = 2;
      }
      
    }
  }
  engine_1();
  engine_2();
  engine_3();
  delay(100);
}
