// Inclusao das bibliotecas para o NFC
#include <SPI.h>
#include <NFC.h>

// Portas e objeto para o NFC
#define PINO_SS 10
#define PINO_RESET 9
NFC  nfc(PINO_SS, PINO_RESET);   // Create MFRC522 instance.

// Portas do LED RGB
int  Vermelho = 7;
int  Verde = 6;
int  Azul = 5;

// Cartoes de virus (pode ser descoberto ao observar o monitor Serial e escanear o cartao
String Cartao1 = " 1B D9 02 0F";
String Cartao2 = " 71 70 69 1C";

// Virus conhecidos
int  Virus1 = 0;
int  Virus2 = 0;
 
void setup(){
  // Inicia a comunicacao serial com o computador
  Serial.begin(9600);
  // Inicia a comunicacao SPI
  SPI.begin();
  // Inicia noss moduli MRFC522
  nfc.iniciar();
  // Define  as portas do RGB como saidas
  pinMode(Vermelho, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
  // Escreve os valores iniciais no RGB, deixando apenas o verde ligado
  digitalWrite(Vermelho,HIGH);
  digitalWrite(Azul,HIGH);
  digitalWrite(Verde,LOW);
}
 
void loop(){
  // Procura por novos cartoes com o NFC e o seleciona em seguida, caso nao encontre nada recomeca o loop principal
  if( ! nfc.cartaoEstaPresente())
    return;
  if( ! nfc.lerCodigoCartao())
    return;
  
  // Cria uma variavel para guardar a UID do NFC
  String conteudo= "";

  // Transforma a UID em hexadecimal para facilitar a leitura
  nfc.imprimirUID(&nfc, &conteudo);

  // Verifica se esta sendo exposto ao virus1
  if(conteudo == Cartao1){
    // Caso esteja exposto, liga o LED azul e apaga o verde
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,LOW);
    delay(2000);
    // Verifica se já foi infectado por esse virus antes, se já tiver sido infectado apenas pula a parte de estar infeccioso
    if(Virus1 == 0){
      // Acende a luz vermelha
      digitalWrite(Azul,HIGH);
      digitalWrite(Vermelho,LOW);
      delay(3000);
      // Salva como ja exposto ao virus
      Virus1 = 1;
    }
  }

  // Repete o mesmo processo do virus1 para o 2
  if(conteudo == Cartao2){
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,LOW);
    delay(1000);
    if(Virus2 == 0){
      digitalWrite(Azul,HIGH);
      digitalWrite(Vermelho,LOW);
      delay(2000);
      Virus2 = 1;
    }
  }
  // Garante que apenas o verde esteja ligado
  digitalWrite(Vermelho,HIGH);
  digitalWrite(Azul,HIGH);
  digitalWrite(Verde,LOW);
}
