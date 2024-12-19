// C++ code
// código para exibir no serial a contagem ao pressionar o botão, caso o botão fique pressionado por muito tempo ele conta apenas 1 clique

int contador = 0;
int statusBotao = 0;
int botao_esta_pressionado = 0;

void setup()
{
	pinMode(7, INPUT);
  	pinMode (10, OUTPUT);
  	pinMode (11, OUTPUT);
  	pinMode (12, OUTPUT);
  	Serial.begin(115200);
}

void loop()
{
 statusBotao = digitalRead(7);
  if(statusBotao == true){
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
    
    if(botao_esta_pressionado == 0){
    botao_esta_pressionado = 1;
      contador++;
      Serial.println(contador);
    }
  }
  else{
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
    botao_esta_pressionado = 0;
  }
  delay(100);
}