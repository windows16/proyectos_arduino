#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int PIRPin = 2; 
const int buzzerPin = 3;  

LiquidCrystal_I2C lcd(0x27, 16, 2);

int lastPIRState = -1; // Variable para almacenar el último estado del PIR (-1 para forzar actualización inicial)

void setup() {
  lcd.init(); 
  lcd.backlight(); 
  lcd.print("MKP ACTIVADO"); 

  pinMode(PIRPin, INPUT);
  pinMode(buzzerPin, OUTPUT);  
  
  
  digitalWrite(buzzerPin, LOW);
  
 
}

void loop() {
  int currentPIRState = digitalRead(PIRPin);
  
  
  if (currentPIRState != lastPIRState) {
    
    lastPIRState = currentPIRState;
    
    // Limpiar la segunda línea
    lcd.setCursor(0, 1);
    lcd.print("                "); 
    
    
    lcd.setCursor(0, 1);
    if (currentPIRState == HIGH) {
      lcd.print("YA LO VI JEFE");
      
      tone(buzzerPin, 2400, 500); 
    } else {
      lcd.print("Ni mais");
    
      noTone(buzzerPin);
    }
  }
  
  // Delay pequeño para estabilidad del sistema
  delay(10);
}