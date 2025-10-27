//Chamando a biblioteca do Arduino.
#include <Arduino.h>

//Declarando as portas dos LEDs.
uint32_t portaLEDVermelho = 13;
uint32_t portaLEDAmarelo = 12;
uint32_t portaLEDVerde = 11;

//Declarando as variáveis de tempo.
unsigned long tempoAtual;
unsigned long tempoAnterior = 0;
unsigned long tempoQuePassou;

//Variável para armazenar o estado do LED (0 é vermelho, 1 é amarelo e 2 é verde).
int led = 0;

void setup() {
  //Configurando os LEDs como dispositivos de saída.
  pinMode(portaLEDVermelho, OUTPUT);
  pinMode(portaLEDAmarelo, OUTPUT);
  pinMode(portaLEDVerde, OUTPUT);
  
  Serial.begin(115000);
}

//Função para manter a lógica do semáforo em constante repetição.
void loop() {

}