
int calibrationTime = 30;


long unsigned int lowIn;


long unsigned int pause = 5000;

boolean lockLow = true;
boolean takeLowTime;

int pirPin = 7;
#define r1 5
//int Buzzer = 6;


void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(r1, OUTPUT);
  //pinMode(Buzzer, OUTPUT);
  digitalWrite(pirPin, LOW);


  Serial.print("mengkalibrasi sensor");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" selesai");
    digitalWrite(r1, HIGH); 
    Serial.println("SENSOR AKTIF");
    delay(50);
  }

  void loop(){

     if(digitalRead(pirPin) == HIGH){
       digitalWrite(r1, HIGH);   
       //tone(Buzzer,500);
       if(lockLow){  
       
         lockLow = false;
         Serial.println("---");
         Serial.print("gerakan terdetiksi selama ");
         Serial.print(millis()/1000);
         Serial.println(" detik"); 
         delay(50);
         }
         takeLowTime = true;
       }

     if(digitalRead(pirPin) == LOW){
       digitalWrite(r1, LOW);

       if(takeLowTime){
        lowIn = millis();
        takeLowTime = false;
        }

       if(!lockLow && millis() - lowIn > pause){
           lockLow = true;
           Serial.print("gerakan selesai di  ");      
           Serial.print((millis() - pause)/1000);
           Serial.println(" detik");
           delay(50);
           }
       }
  }