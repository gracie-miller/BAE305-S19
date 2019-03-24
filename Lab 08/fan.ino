

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode(7, OUTPUT);
}

void loop() {
 delay (1000); // put your main code here, to run repeatedly:
for (int i=0; i<=100; i++)
{
  Serial.println (i);
 analogWrite (7, i+130);
  delay(250);
}
delay (1000);
for (int i= 100; i>=0; i--)
{Serial.println(i);
analogWrite (7, i+120);
delay (250);
}
analogWrite(7,0);
}
