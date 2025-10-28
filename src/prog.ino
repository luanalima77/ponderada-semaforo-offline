//Chamando a biblioteca do Arduino.
#include <Arduino.h>

//Declarando as portas dos LEDs.
uint32_t portaLEDVermelho = 13;
uint32_t portaLEDAmarelo = 12;
uint32_t portaLEDVerde = 11;

//Declarando a porta do buzzer.
uint32_t portaBuzzer = 10;

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
  
  Serial.begin(115200);
}

//Função para ligar o LED.
void ligarLED(int corDoLED){
  bool taLigado = true;
  switch(corDoLED){
    case 0:
    	digitalWrite(portaLEDVermelho, taLigado);
    	digitalWrite(portaLEDAmarelo, !taLigado);
    	digitalWrite(portaLEDVerde, !taLigado);
    	break;
    case 1:
    	digitalWrite(portaLEDVermelho, !taLigado);
    	digitalWrite(portaLEDAmarelo, !taLigado);
    	digitalWrite(portaLEDVerde, taLigado);
    	break;
    case 2:
    	digitalWrite(portaLEDVermelho, !taLigado);
    	digitalWrite(portaLEDAmarelo, taLigado);
    	digitalWrite(portaLEDVerde, !taLigado);
    	break;
    default:
    	Serial.println("Meu caro dev, a porta do pino inserida não existe.");
  }
}

//Função para tocar um alerta sonoro quando o led for o amarelo.
void tocarAlerta(){
  if(led == 2){
    tone(portaBuzzer, 500);
  }else{
    noTone(portaBuzzer);
  }
}

//Função para trocar o LED que está aceso dado o tempo de cada um.
void trocarLED(){
  led++;
  tempoAnterior = tempoAtual;

  //Quando o sinal estiver no amarelo, tocar um alerta sonoro.
  tocarAlerta();

  if(led > 2){
    led = 0;
  }
}

//Função para ligar o semáforo com base nos tempos definidos para cada led.
void ligarSemaforo(){
   //Chamando a função millis().
  tempoAtual = millis();
  tempoQuePassou = tempoAtual - tempoAnterior;
  
  //LED vermelho ligado.
  if(led == 0){
    ligarLED(0);
    if(tempoQuePassou >=6000){
      trocarLED();
    }
  }
  
  //LED verde ligado.
  else if(led == 1){
    ligarLED(1);
    if(tempoQuePassou >=4000){
      trocarLED();
    }
  }
  
  //LED amarelo ligado.
  else if(led == 2){
    ligarLED(2);
    if(tempoQuePassou >=2000){
      trocarLED();
    }
  }
}

//Função para manter a lógica do semáforo em constante repetição.
void loop() {
	ligarSemaforo();
}


