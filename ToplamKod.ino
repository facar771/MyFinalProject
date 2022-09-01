//ServoMotorTanımlamaları
#include <Servo.h>
Servo sg90;


//StepMotorTanımlamaları
const int YonPini1 = 5;
const int Adim1 = 16;

const int YonPini2 = 0;
const int Adim2 = 4;

const int YonPini3 = 2;
const int Adim3 = 14;

const int YonPini4 = 3;
const int Adim4 = 1;


//UltrasonikSensörTanımlamaları
unsigned int sure,mesafe;
int echo=13;
int trig=15;


void setup() 
{
  //StepMotorTanımlamaları
  pinMode(Adim1, OUTPUT);
  pinMode(YonPini1, OUTPUT);
  
  pinMode(Adim2, OUTPUT);
  pinMode(YonPini2, OUTPUT);
  
  pinMode(Adim3, OUTPUT);
  pinMode(YonPini3, OUTPUT);

  pinMode(Adim4, OUTPUT);
  pinMode(YonPini4, OUTPUT);

  //ServoMotorTanımlamaları
  sg90.attach(12);
  
  //UltrasonikSensörTanımlamaları
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  //Serial.begin(9600);

  delay(1000);
  Motor1Yukari(5);
  delay(500);
  Motor3Geri(5);
  delay(500);
  Motor2Sol(10);
  delay(500);
  Servo0();
  delay(500);
}

void loop() 
{
  Ultrasonik();
  if(mesafe < 5)
  {
    while(mesafe < 20)
    {
      Ultrasonik();
      BandMotoru(1);
    }
    delay(500);

    Motor2Sag(6);
    delay(500);

    Motor1Asagi(7);
    delay(500);
  
    Motor3Ileri(3.5);
    delay(500);
    
    ServoKapa();
    delay(500);

    Motor3Geri(1);
    delay(500);

    Motor1Yukari(1);
    delay(500);

    Motor1Yukari(7);
    delay(500);
    
    Motor3Geri(5);
    delay(500);

    Motor2Sag(14);
    delay(500);

    Motor3Geri(1);
    delay(500);

    Motor1Asagi(1);
    delay(500);

    ServoAc();
    delay(500);

    Motor2Sol(20);
    delay(500);

    Motor3Ileri(3.5);
    delay(500);
  }
}

void Ultrasonik()
{
  digitalWrite(trig,HIGH);
  delayMicroseconds(20);
  digitalWrite(trig,LOW);
  sure=pulseIn(echo,HIGH);
  mesafe=(sure/2)/29.1;
  //Serial.println(mesafe);
  delay(1);
  //Serial.println(mesafe);
}

//StepMotorTanımlamaları
void BandMotoru(int adim)
{
  digitalWrite(YonPini4, HIGH);
  
  for(int x = 0; x < 500 * adim; x++)
  {
     digitalWrite(Adim4, HIGH);
     delayMicroseconds(100);
     digitalWrite(Adim4, LOW);
     delayMicroseconds(100);
  }
}

void Motor2Sol(int adim)
{
  digitalWrite(YonPini2, LOW); 
  
  for(int x = 0; x < 100 * adim; x++)
  {
     digitalWrite(Adim2, HIGH);
     delayMicroseconds(500);
     digitalWrite(Adim2, LOW);
     delayMicroseconds(500);
  }
}

void Motor2Sag(int adim)
{
  digitalWrite(YonPini2, HIGH); 
  
  for(int x = 0; x < 100 * adim; x++)
  {
     digitalWrite(Adim2, HIGH);
     delayMicroseconds(500);
     digitalWrite(Adim2, LOW);
     delayMicroseconds(500);
  }
}

void Motor1Yukari(float adim)
{
  digitalWrite(YonPini1, LOW); //sola
  
  for(int x = 0; x < 100 * adim; x++)
  {
     digitalWrite(Adim1, HIGH);
     delayMicroseconds(500);
     digitalWrite(Adim1, LOW);
     delayMicroseconds(500);
  }
}

void Motor1Asagi(float adim)
{
  digitalWrite(YonPini1, HIGH); //sola
  
  for(int x = 0; x < 100 * adim; x++)
  {
     digitalWrite(Adim1, HIGH);
     delayMicroseconds(500);
     digitalWrite(Adim1, LOW);
     delayMicroseconds(500);
  }
}

void Motor3Ileri(int adim)
{
  digitalWrite(YonPini3, LOW); //sola
  
  for(int x = 0; x < 100 * adim; x++)
  {
     digitalWrite(Adim3, HIGH);
     delayMicroseconds(500);
     digitalWrite(Adim3, LOW);
     delayMicroseconds(500);
  }
}

void Motor3Geri(int adim)
{
  digitalWrite(YonPini3, HIGH); //sola
  
  for(int x = 0; x < 100 * adim; x++)
  {
     digitalWrite(Adim3, HIGH);
     delayMicroseconds(500);
     digitalWrite(Adim3, LOW);
     delayMicroseconds(500);
  }
}

void ServoKapa()
{
  sg90.write(0);
}

void ServoAc()
{
  sg90.write(120);
}

void Servo0()
{
  sg90.write(130);
}
