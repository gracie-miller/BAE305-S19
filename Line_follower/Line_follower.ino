const int PMWA = 5;
const int AIN1 = 2;
const int AIN2 = 4;
const int STBY = 3;
const int PMWB = 6;
const int BIN2 = 8;
const int BIN1 = 7;

float threshold = 3.3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensorValueP = analogRead(A5) * (5.0 / 1024.0);
  float sensorValueD = analogRead (A4) * (5.0 / 1024.0);
  Serial.print (sensorValueP);
  Serial.print ("V\t");
  Serial.print (sensorValueD);
  Serial.println ("V");

 if (sensorValueP < threshold && sensorValueD < threshold) {   
 digitalWrite (STBY, HIGH);
  digitalWrite (AIN1, LOW);
  digitalWrite (AIN2, HIGH);
  digitalWrite (BIN1, LOW);
  digitalWrite (BIN2, HIGH);
   
  analogWrite (PMWB , 154);
  analogWrite (PMWA, 150);

 } else if  (sensorValueP > threshold && sensorValueD < threshold) {        //if passenger over tape, turn right slightly
 digitalWrite (STBY, HIGH);
  digitalWrite (AIN1, LOW);
  digitalWrite (AIN2, HIGH);
  digitalWrite (BIN1, LOW);
  digitalWrite (BIN2, HIGH);
  
  analogWrite (PMWA, 120);
  analogWrite (PMWB, 200);
 
 } else if  (sensorValueD > threshold && sensorValueP < threshold) {       // if driver over tape, turn left slightly
 digitalWrite (STBY, HIGH);
  digitalWrite (AIN1, LOW);
  digitalWrite (AIN2, HIGH);
  digitalWrite (BIN1, LOW);
  digitalWrite (BIN2, HIGH);
  
  analogWrite (PMWA, 200);
  analogWrite (PMWB, 120);
   
 } else{
 digitalWrite (STBY, HIGH);
  digitalWrite (AIN1, LOW);
  digitalWrite (AIN2, HIGH);
  digitalWrite (BIN1, HIGH);
  digitalWrite (BIN2, LOW);

    analogWrite (PMWB, 154);
    analogWrite (PMWA, 150);

  

}

}
