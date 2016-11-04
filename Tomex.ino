#include <SoftwareSerial.h>   //Inlcui a biblioteca SoftwareSerial.h
 
#define RxD         6 //Define RxD como 6
#define TxD         7 //Define TxD como 7
 
#define RELE_LAMPADA         4 //RELE_LAMPADA como 4
 
SoftwareSerial blueToothSerial(RxD,TxD); //Instancia a biblioteca SoftwareSerial.h
 int flag = 1;
void setup()
{

  pinMode(LED_AMARELO, OUTPUT); //Configura o pino 2 como saída
  pinMode(LED_VERMELHO, OUTPUT); //Configura o pino 3 como saída
  pinMode(RELE_LAMPADA, OUTPUT); //Configura o pino 4 como saída
  blueToothSerial.begin(9600);
  
  Serial.begin(9600);

}
 
void loop()
{
  
  char letra; //Variável char para armazenar o caractere recebido
if(blueToothSerial.available()) //Se algo for recebido pela serial do módulo bluetooth
    {
      letra = blueToothSerial.read(); //Armazena o caractere recebido na variável letra
      
      if(letra == 'L'){
        if(flag == 1){
          digitalWrite(RELE_LAMPADA,HIGH); 
          flag = 0; 
        }
        else{
          
          digitalWrite(RELE_LAMPADA,LOW);
          flag= 1;
        }
      }
     
  }

  
}
 
 
