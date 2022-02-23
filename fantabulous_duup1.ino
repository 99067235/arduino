// Load LCD Library
#include <LiquidCrystal.h>

// set crystal pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


const int BTN = 9;
const int LED = 8;       

int state = LOW;      
int reading;           
int previous = LOW;    



long time = 0;         
long debounce = 200;   ers

void setup()
{
  pinMode(BTN, INPUT);
  pinMode(LED, OUTPUT);
  
   // set LCD size
  lcd.begin(16,2);
  
  // set start
  lcd.setCursor(0,0);
  lcd.print("Press button to:");
  lcd.setCursor(0,1);
}

// schrijf hier tussen je code
void loop()
{ 
  reading = digitalRead(BTN);
  if (reading == HIGH && previous == LOW) {
    if (state == HIGH){
      state = LOW;
      lcd.print("Turn light on ");
      lcd.setCursor(0,1);
      delay(1000);
    }
    else{
      state = HIGH;
 	  lcd.print("Turn light off");
      lcd.setCursor(0,1);
      delay(1000);
    }
   
  }

  digitalWrite(LED, state);

  previous = reading;
}

// schrijf hier tussen je code

// schrijf hier tussen je eventuele function(s)


// schrijf hier tussen je eventuele function(s)