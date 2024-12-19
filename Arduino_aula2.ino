// C++ code
//

int estadoAnterior = LOW;
int statusBotao = 0;

void setup()
{
	pinMode(7, INPUT);
  	pinMode (10, OUTPUT);
}

void loop()
{
 statusBotao = digitalRead(7);
	if(statusBotao == HIGH && estadoAnterior == LOW // caso o botao for verdadeiro ou falso...
      ){
    digitalWrite(10, !digitalRead(10)); // digitalWrite= ele vai escrever
    }
 
  estadoAnterior = statusBotao;
}