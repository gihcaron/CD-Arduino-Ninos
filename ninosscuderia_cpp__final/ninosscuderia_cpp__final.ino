//PROGRAMA BASE CARRINHO - NINO'S SCUDERIA (1TDS1) 

// Declaração de veriáveis ---------------

// PINOS UTILIZADOS CONFORME O ENDEREÇAMENTO ABAIXO

//Definição do uso dos pinos do Arduino
#define pinMotor1A     11 //Definir o "cabo/pino" na cor vd para o motor A1 na entrada 11
#define pinMotor1B     10 //Definir o "cabo/pino" na cor az para o motor A2 na entrada 10
#define pinMotor2A     9  //Definir o "cabo/pino" na cor br para o motor B1 na entrada 9
#define pinMotor2B     6  //czDefinir o "cabo/pino" na cor cz para o motor B2 na entrada 6

// Definição dos Pins para o HC-06 
#define pinBtRx        8  //Definir o pin RX (pin de comunicação)- "Cabo" vd
#define pinBtTx        7  //Definir o pin TX (pin de alimentação)- "Cabo" vd

//Biblioteca para comunicação com módulo Bluetooth
// ((((((Explicar a biblioteca))))))
#include <SoftwareSerial.h> //  Linkar ao código a Biblioteca "SoftwareSerial.h"
SoftwareSerial bluetooth(pinBtRx, pinBtTx); // RX, TX

//Configuração do projeto no Arduino  -------------------------------

void setup() {
  //Configura o estado das portas do Arduino
  pinMode(pinMotor1A, OUTPUT); // Saída do arduino para o pino 1 do Motor A
  pinMode(pinMotor2A, OUTPUT); // Saída do arduino para o pino 2 do Motor A
  pinMode(pinMotor1B, OUTPUT); // Saída do arduino para o pino 1 do Motor B
  pinMode(pinMotor2B, OUTPUT); // Saída do arduino para o pino 2 do Motor B
  digitalWrite(13, LOW); // Não está passando energia na porta 13 = > Desliga a porta 
  digitalWrite(2, LOW); // Não está passando energia na porta 2 = > Desliga a porta
  digitalWrite(3, LOW); // Não está passando energia na porta 3 = > Desliga a porta


  //Inicia a comunicação serial para monitorar o que está acontecendo pelo monitor serial
  Serial.begin(9600);

  //Inicia a cominicação serial com o módulo bluetooth
  bluetooth.begin(9600);


}

// Lógica do projeto do Arduino ------------

void loop() {
// Variável para armazenar o dado recebido 
char recebido;

  //Teste do Bluetooth
  // Faz a verificação de dados disponíveis no módulo Blutooth 
  if (bluetooth.available()) { // 
    recebido = bluetooth.read(); // Faz a leitura do dado recebido
    Serial.write(recebido); // Escreve o dado no monitor serial
    Serial.println("- "); // Adiciona uma nova linha (facilitando sua leitura)
     } 
          if (recebido == 'F') {   // Se o comando recebido for F ele MOVIMENTA PARA FRENTE = > F = Front 
     
       digitalWrite(pinMotor1A, HIGH); // Compartilha a energia do Motor 1A = > Liga 
       digitalWrite(pinMotor1B, LOW);  // Interrompe a energia do Motor 1B = > Desliga
       digitalWrite(pinMotor2A, HIGH); // Passa energia ao pino 2 do motor  A = > Liga
       digitalWrite(pinMotor2B, LOW); // Interrompe a engerdia do pino 2 do motor B = > Desliga
    }

     else if (recebido == 'B') {   // Se o comando recebido for "B" MOVIMENTA PARA TRÁS = > B = Back 
     
       digitalWrite(pinMotor1A, LOW); // Interrompe a engergia do pino 1 do motor A = > Desliga
       digitalWrite(pinMotor1B, HIGH); // Passa energia ao pino 1 do motor  B = > Liga/ Ativa
       digitalWrite(pinMotor2A, LOW); //Interrompe a engergia do pino 2 do motor A = > Desliga
       digitalWrite(pinMotor2B, HIGH);// Passa energia ao pino 2 do motor  B = > Liga

     }else if (recebido == 'L') {   // Se o comando recebido for "L" MOVIMENTA PARA ESQUERDA = > "L" = LEFT 
     
       digitalWrite(pinMotor1A, LOW); // Interrompe a engergia do pino 1 do motor A = > Desliga
       digitalWrite(pinMotor1B, LOW); // Interrompe a engergia do pino 1 do motor B = > Desliga
       digitalWrite(pinMotor2A, HIGH); // Passa energia ao pino 2 do motor  A = > Liga
       digitalWrite(pinMotor2B, LOW); // Interrompe a engergia do pino 2 do motor B = > Desliga

     }  else if (recebido == 'R') {   // Se o comando recebido for 'R' MOVIMENTA PARA A DIREITA = > "R" = DIREITA
      
       digitalWrite(pinMotor1A, HIGH); // Passa energia ao pino 1 do motor  A = > Liga
       digitalWrite(pinMotor1B, LOW); // Interrompe a engergia do pino 1 do motor B = > Desliga
       digitalWrite(pinMotor2A, LOW);// Interrompe a engergia do pino 2 do motor A = > Desliga
       digitalWrite(pinMotor2B, LOW);// Interrompe a engergia do pino 2 do motor B = > Desliga
    
    } 

    else if (recebido == 'S') {  //Se o comando recebido for 'S' ele para // PARADO
     
       digitalWrite(pinMotor1A, LOW); // Interrompe a engergia do pino 1 do motor A = > Desliga
       digitalWrite(pinMotor1B, LOW); // Interrompe a engergia do pino 1 do motor B = > Desliga
       digitalWrite(pinMotor2A, LOW);// Interrompe a engergia do pino 2 do motor A = > Desliga
       digitalWrite(pinMotor2B, LOW);// Interrompe a engergia do pino 2 do motor B = > Desliga
    
    } 

}

  