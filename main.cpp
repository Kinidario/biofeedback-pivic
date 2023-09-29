#include <Arduino.h>
//variáveis
int sa = 15, sb =2, ar = 4, var = 0, state = 0;
unsigned long tempoAtual= 0, tempoPassado = 0, intervalo = 500;

void setup() {
  // setup
  pinMode(sa, OUTPUT);
  pinMode(sb, OUTPUT);
  pinMode(ar, INPUT);

}

void loop() {
  // o código vai ler o analog read e o tempo toda vez que o loop terminar
  var = analogRead(ar);
  tempoAtual = millis();
  //se ele detectar alguma tensão no pino a ponte H é acionada
  if(var < 3720){
    // o state define qual pino será ligado
    if(state == 0){
      digitalWrite(sb, LOW);
      digitalWrite(sa, HIGH);
    }
    if(state == 1){
      digitalWrite(sa, LOW);
      digitalWrite(sb, HIGH);
    }
    // se o período da onda tiver passado o state muda
    if(tempoAtual - tempoPassado >= intervalo){
      state = 1 - state;
      tempoPassado = tempoAtual;
    }

  }
  else{
    digitalWrite(sa, LOW);
    digitalWrite(sb, LOW);
    tempoAtual = 0;
    tempoPassado = 0;
    state = 0;
  }
}
