// C++ Code
//por algum motivo que eu ainda não sei esse código não funciona porque ele entra no if sem eu pressionar o botão.



#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int estadoAnterior = LOW;
int statusBotao = 0;


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(7, INPUT);
    lcd.init();
    lcd.backlight();
}

void loop() {
    statusBotao = digitalRead(7);

    // Verifica se o botão foi pressionado pela primeira vez
    if (statusBotao == HIGH && estadoAnterior == LOW ) {
        
        
        lcd.print("Botao Press!");
        delay(3000); // conta 3 segundos
        lcd.noBacklight(); // apaga o backlight
        delay(5000); // conta 5 segundos
        lcd.noDisplay(); // apaga o display
    }

    // Atualiza o estado anterior do botão
    estadoAnterior = statusBotao;
}