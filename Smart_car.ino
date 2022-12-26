#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // pin RX, TX

//define variabel
String arah;

//define name pin motor DC
#define motorKiri_1 11
#define motorKiri_2 10
#define motorKanan_2 6
#define motorKanan_1 9

void setup() {
//  pengaturan baud rate
  Serial.begin(9600);
  mySerial.begin(9600);

//pengaturan arah I/O pin
  pinMode(motorKiri_1, OUTPUT);
  pinMode(motorKiri_2, OUTPUT);

  pinMode(motorKanan_2, OUTPUT);
  pinMode(motorKanan_1, OUTPUT);
}

void loop() {
  { 
    while(mySerial.available()){
      delay(10);
      char masukan = mySerial.read();
      arah += masukan;
    }
    //read variabel panjang arah   
    if(arah.length() > 0){
    //Serial.println(arah);
    
    if(arah == "maju"){
      analogWrite(motorKiri_1, 100);
      analogWrite(motorKiri_2, 0);

      analogWrite(motorKanan_1, 100);
      analogWrite(motorKanan_2, 0);
      //Serial.println("maju");
      delay(300);      
      }      
    if(arah == "kiri"){
      analogWrite(motorKiri_1, 0);
      analogWrite(motorKiri_2, 0);

      analogWrite(motorKanan_1, 100);
      analogWrite(motorKanan_2, 0);
      //Serial.println("belok kiri");
      delay(300);     
      }
    if(arah == "kanan"){
      analogWrite(motorKiri_1, 100);
      analogWrite(motorKiri_2, 0);

      analogWrite(motorKanan_1, 0);
      analogWrite(motorKanan_2, 0);
      //Serial.println("belok kanan");
      delay(300);  
    }
   if(arah == "mundur"){
      analogWrite(motorKiri_1, 0);
      analogWrite(motorKiri_2, 100);

      analogWrite(motorKanan_1, 0);
      analogWrite(motorKanan_2, 100);
      //Serial.println("mundur");
      delay(300);   
    }
   if(arah == "berhenti"){
      analogWrite(motorKiri_1, 0);
      analogWrite(motorKiri_2, 0);

      analogWrite(motorKanan_1, 0);
      analogWrite(motorKanan_2, 0);
      //Serial.println("berhenti");
      delay(300);   
    }
  arah = "";
  }
}
}
