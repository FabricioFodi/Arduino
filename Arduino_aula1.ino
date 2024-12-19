
// C++ code
//
void setup()
{
    // declarando as saídas
  pinMode( 10, OUTPUT); 
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(10, HIGH);
  delay(1000); // espera por 1 sec;
  digitalWrite(10, LOW);
  delay(1000); // espera por 1 sec;
  
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  delay(1000);
  
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12,LOW);
  delay(1000);
}