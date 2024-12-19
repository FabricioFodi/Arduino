int ldrValor = 0; // valor da ldr
int ldrPerc = 0; // percentual da ldr
int percAnt = 0;


void setup() {
  Serial.begin(115200); 
  
}

void loop() {
  
  ldrValor = analogRead(A0); // ler o botao analogico ligado ao A0
  
  ldrPerc = map(ldrValor,0,1024,100,0); //criei um mapa para ler o valor de ldr, me mostre de 0 a 1024 e de 100 a 0%
  
  if (ldrPerc != percAnt) {      //se ldrPerc for diferente da PercAnt...
    // Atualiza a porcentagem anterior
    percAnt = ldrPerc;
  Serial.println(ldrPerc); // printa o percentual
  
  //delay(100); //delay para n dar erros
  }
}//fim loop
   
// fazer com que o serial só atualize quando houver mudança de porcentagem