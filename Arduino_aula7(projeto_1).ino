// projeto 1.1 com LCD
// feito com chatGPT


#include <Adafruit_LiquidCrystal.h>

const int pinoPotenciometro = A0;   // Pino analógico do potenciômetro
const int pinoFotovoltaico = A1;    // Pino analógico do fotovoltaico
const int pinoBotao = 7;            // Pino digital do botão
const int pinoLED = 10;             // Pino do LED

int valorPotenciometro = 0;         // Variável para armazenar a leitura do potenciômetro
int valorFotovoltaico = 0;          // Variável para armazenar a leitura do fotovoltaico
int estadoBotao = 0;                // Variável para armazenar o estado do botão
int ultimoEstadoBotao = 0;          // Variável para armazenar o estado anterior do botão
bool logicaHabilitada = true;       // Variável para controlar a lógica

int ultimoValorPotenciometro = -1;  // Último valor do potenciômetro
int ultimoValorFotovoltaico = -1;   // Último valor do fotovoltaico

int segundos = 0;
Adafruit_LiquidCrystal lcd_1(0);

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.print("Hello, LCD!");

  pinMode(pinoLED, OUTPUT);      // Configura o pino do LED como saída
  pinMode(pinoBotao, INPUT);     // Configura o pino do botão como entrada
  Serial.begin(9600);            // Inicia a comunicação serial para depuração
}

void loop() {
  // Lê o estado do botão
  estadoBotao = digitalRead(pinoBotao);

  // Verifica se o estado do botão mudou
  if (estadoBotao != ultimoEstadoBotao) {
    delay(50);  // Aguarda um curto período para evitar leituras instáveis
    if (estadoBotao == HIGH) {
      // Inverte o estado da lógica ao pressionar o botão
      logicaHabilitada = !logicaHabilitada;
     
      // Se a lógica estiver desativada, acende o LED
      if (!logicaHabilitada) {
        digitalWrite(pinoLED, HIGH);
      } else {
        digitalWrite(pinoLED, LOW);
      }
    }
  }

  // Armazena o estado atual do botão para a próxima iteração
  ultimoEstadoBotao = estadoBotao;

  // Se a lógica estiver habilitada, continua com a lógica existente
  if (logicaHabilitada) {
    // Lê os valores do potenciômetro e do fotovoltaico
    valorPotenciometro = analogRead(pinoPotenciometro);
    valorFotovoltaico = analogRead(pinoFotovoltaico);

    // Mapeia o valor do potenciômetro para o intervalo de 0-100
    int valorPotenciometroMapeado = map(valorPotenciometro, 0, 1023, 100, 0);

    // Mapeia o valor do fotovoltaico para o intervalo de 0-100
    int valorFotovoltaicoMapeado = map(valorFotovoltaico, 0, 1023, 100, 0);

    // Imprime os valores no monitor serial (opcional)
    Serial.print("Potenciometro: ");
    Serial.print(valorPotenciometroMapeado);
    Serial.print("%, Luminosidade: ");
    Serial.print(valorFotovoltaicoMapeado);
    Serial.println();

    // Verifica se houve alterações no potenciômetro ou na luminosidade
    if (valorPotenciometroMapeado != ultimoValorPotenciometro || valorFotovoltaicoMapeado != ultimoValorFotovoltaico) {
      // Exibe os valores no LCD apenas se houver alterações
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Pot: ");
      lcd_1.print(valorPotenciometroMapeado);
      lcd_1.print("%  ");

      lcd_1.setCursor(0, 1);
      lcd_1.print("Luz: ");
      lcd_1.print(valorFotovoltaicoMapeado);
      lcd_1.print("%  ");

      // Atualiza os últimos valores
      ultimoValorPotenciometro = valorPotenciometroMapeado;
      ultimoValorFotovoltaico = valorFotovoltaicoMapeado;
    }

    // Acende o LED se a luminosidade for menor que o valor do potenciômetro
    if (valorFotovoltaicoMapeado < valorPotenciometroMapeado) {
      digitalWrite(pinoLED, HIGH);  // Liga o LED
    } else {
      digitalWrite(pinoLED, LOW);   // Desliga o LED
    }
  }

  delay(50);  // Aguarda 500 milissegundos antes da próxima leitura
}