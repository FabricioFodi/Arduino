// C++ code
// fazer um código que ligue o led se LDR for menor que 40 e o botao nao funciona, se for acima de 40 o botao funciona.

int ldrValor = 0; // valor da ldr
int ldrPerc = 0;  // percentual da ldr
int percAnt = 0;
int potValor = 0; // valor do Potenciometro
int potPerc = 0;  // Percentual do Potenciometro


int estadoAnterior = LOW;
int statusBotao = 0;

void setup()
{
	pinMode(7, INPUT);
  	pinMode (10, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
 statusBotao = digitalRead(7);
	if(statusBotao == HIGH && estadoAnterior == LOW // caso o botao for verdadeiro ou falso...
      ){
    digitalWrite(10, !digitalRead(10)); // digitalWrite= ele vai escrever
    }
 ldrValor = analogRead(A1); // ler o botao analogico ligado ao A0
 potValor = analogRead(A0);
  
  potPerc = map(potValor, 0, 1024, 100, 0);
  ldrPerc = map(ldrValor, 0, 1024, 100, 0); //criei um mapa para ler o valor de ldr, me mostre de 0 a 1024 e de 100 a 0%
  
  if (ldrPerc <= potPerc || potPerc <=40) {      //se ldrPerc for diferente da PercAnt...
  	digitalWrite(10, HIGH);
  }
    
  
  
  Serial.print("potenciometro: ");
  Serial.print(potPerc); //printa o percentual
  Serial.print("	Luminosidade: ");
  Serial.println(ldrPerc);
  delay(100); //delay para n dar erros
 
  estadoAnterior = statusBotao;
}