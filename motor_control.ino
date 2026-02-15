int speed_pin = 5;
int dir1 =13;
int dir2 = 12;
int mSpeed;
int myVoltPin = A3;
int readVal;
float V2;
int mspeed;
int del = 10;

void setup() {
pinMode(speed_pin,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
Serial.begin(9600);

}

void loop() {
digitalWrite(dir1,HIGH);
digitalWrite(dir2,LOW);
long sum = 0;
for(int i=0;i<10;i++){
  sum = sum + analogRead(myVoltPin);
}
float avgReading = sum/10;
V2 = avgReading*(5./1023.);
delay(del);
mspeed = (V2*255/5);
analogWrite(speed_pin,mspeed);
Serial.print("V2:");
Serial.print(V2);
Serial.print(" ");
Serial.print("Speed:");
Serial.println(mspeed);


}
