# Semáforo offline
&nbsp; &nbsp; &nbsp; &nbsp;Basicamente, este é um projeto de um semáforo offline para controlar o fluxo de pedestres e veículos, utilizando LEDs, resistores e programação Arduino com a linguagem de programação C++. Em linhas gerais, o objetivo é montar e programar um semáforo que funcione correta e seguramente, replicando o comportamento dos semáforos reais.

## Programação e lógica do semáforo
A lógica do semáforo segue a sequência de cores e tempos (em segundos):
- Vermelho – 6 segundos  
- Verde – 4 segundos  
- Amarelo – 2 segundos  

&nbsp; &nbsp; &nbsp; &nbsp;O ciclo se repete continuamente.

## Estrutura de pastas
```bash
├── assets/ — Imagens e recursos visuais do projeto.  
├── documents/ — Documentação do projeto.  
│   └── documentacao.md — Arquivo principal de documentação, onde foi colocado tudo o que foi solicitado na ponderada.  
├── src/ — Código-fonte principal do projeto.  
│   └── prog.ino — Programa principal em Arduino.  
├── .gitattributes 
├── .gitignore
├── diagram.json — Diagrama do circuito para simulação (usado pelo Wokwi).  
├── platformio.ini — Arquivo de configuração do PlatformIO (plataforma, placa, bibliotecas etc).  
├── README.md — Descrição geral do projeto.  
└── wokwi.toml — Configurações do simulador Wokwi.
```