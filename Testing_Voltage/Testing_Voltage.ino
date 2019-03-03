float threshold = 3.0;

void setup() {
  // put your setup code here, to run once:
Serial. begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float sensorValueP = analogRead(A5)*(5.0/1024.0);
float sensorValueD = analogRead (A4) *(5.0/1024.0);

Serial.print (sensorValueP);
Serial.print ("V\t");

if (sensorValueP > threshold) {
  Serial.print ("X\t");
} else {
  Serial.print ("O\t");
}

Serial.print (sensorValueD);
Serial.println ("V");

if (sensorValueD > threshold) {
  Serial.print ("X\t");
} else {
  Serial.print ("O\t");
}

delay(10);
}
