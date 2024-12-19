// Cronometro que conta apenas quando pressionar o botão e para quando pressionado novamente
//C++ Code

int statusBotao = 0;
int statusAnterior = 0;
int statusLed = 0;
int ligarCronometro = 0;
float cronometro = 0;
float cronoMillis = 0;


// usar a mesma logica da aula 3

void setup() {
  Serial.begin(115200); 
  pinMode(7, INPUT); 
  pinMode(10, OUTPUT);
}

void loop() {
  
 statusBotao = digitalRead(7);
  if(statusBotao == true) {  // true, HIGH, 1 são a mesma coisa;
                             // false, LOW, 0 são a mesma coisa;

                            // statusAnterior == 0; ---> desligado
    if(statusAnterior == 0){               // == 1; ---> ligado
    statusAnterior = 1;     // statusAanterior = 1; ---> botão foi pressionado
      if(statusLed == LOW){                 // = 0; ---> botão não foi pressionado
      digitalWrite(10, HIGH);
      statusLed = 1;
      ligarCronometro = 1;
      }
    else{
    digitalWrite(10, LOW);
      statusLed = 0;
      ligarCronometro = 0;
    }
   }
  }
  else{
    statusAnterior = 0;
  }
  delay(10);
    if(ligarCronometro == true){
     cronoMillis++; 
 }
    else{
      cronoMillis = 0;
    }
    cronometro = cronoMillis / 100; // 1 dividido por 100
    Serial.println(cronometro);
  
}//fim loop
   