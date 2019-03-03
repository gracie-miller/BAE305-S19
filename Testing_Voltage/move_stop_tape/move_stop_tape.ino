const int PMWA = 5;
const int AIN1 = 2;
const int AIN2 = 4;
const int STBY = 3;
const int PMWB = 6;
const int BIN2 = 8;
const int BIN1 = 7;

float threshold = 3.5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensorValueP = analogRead(A5) * (5.0 / 1024.0);
  float sensorValueD = analogRead (A4) * (5.0 / 1024.0);
  Serial.println (sensorValueP);

  digitalWrite (STBY, HIGH);
  digitalWrite (AIN1, LOW);
  digitalWrite (AIN2, HIGH);
  digitalWrite (BIN1, LOW);
  digitalWrite (BIN2, HIGH);

  if (sensorValueP > threshold && sensorValueD > threshold) {
    analogWrite (PMWB, 0);
    analogWrite (PMWA, 0);
  } else {
    analogWrite (PMWB, 179);
    analogWrite (PMWA, 175);
  }

}
