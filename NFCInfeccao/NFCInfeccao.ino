// Inclusao das bibliotecas para o NFC
#include <SPI.h>
#include <MFRC522.h>

// Portas e objeto para o NFC
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

// Portas do LED RGB
int  Vermelho = 7;
int  Verde = 6;
int  Azul = 5;

// Cartoes de virus (pode ser descoberto ao observar o monitor Serial e escanear o cartao
String Cartao1 = "1BD92F";
String Cartao2 = "7170691C";

// Virus conhecidos
int  Virus1 = 0;
int  Virus2 = 0;
 
void setup(){
  // Inicia a comunicacao serial com o computador
  Serial.begin(9600);
  // Inicia a comunicacao SPI
  SPI.begin();
  // Inicia noss moduli MRFC522
  mfrc522.PCD_Init();
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
  if( ! mfrc522.PICC_IsNewCardPresent())
    return;
  if( ! mfrc522.PICC_ReadCardSerial())
    return;
  
  // Cria uma variavel para guardar a UID do NFC
  String conteudo= "";

  // Transforma a UID em hexadecimal para facilitar a leitura
  for (byte i = 0; i < mfrc522.uid.size; i++)
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));

  // Coloca todas as letras da UID em maiusculo e envia ela na tela
  conteudo.toUpperCase();
  Serial.println(conteudo);

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