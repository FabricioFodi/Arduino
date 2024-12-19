int ldrValor = 0; // valor da ldr
int ldrPerc = 0; // percentual da ldr


void setup() {
  Serial.begin(115200); 
  
}

void loop() {
  
  ldrValor = analogRead(A0); // ler o botao analogico ligado ao A0
  
  ldrPerc = map(ldrValor,0,1024,100,0); //criei um mapa para ler o valor de ldr, me mostre de 0 a 1024 e de 100 a 0%
  
  Serial.println(ldrPerc); // printa o percentual
  
  delay(100); //delay para n dar erros
  
}//fim loop
   