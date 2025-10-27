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