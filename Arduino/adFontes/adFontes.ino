/* Ad Fontes STEM Badge 2025
 * 
 * author: @cybertestpilot
 * 
 */

#include <SoftwareTimer.h>

// The definitions of the pins mapped to the MCU
#define LED1 PIN_PA3
#define LED2 PIN_PA4
#define LED3 PIN_PA5
#define LED4 PIN_PC0
#define BUTTON A6


int led_array[4] = {LED1, LED2, LED3, LED4};
int led_array_index = 0;

int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;

// The initial value the board is set to for the purposes of the the LED initial state
int LED_STATE = 9;

int delay_value = 0;

// The delay value being used to set the twinkle effect of the random blinking
bool doTwinkle = false;
bool doDelay = false; 
unsigned long delayStart = 0;
unsigned long delayLenFast = 100;

void twinkleEffect();
SoftwareTimer twinkleTimer(100, &twinkleEffect);

void chaseEffect();
SoftwareTimer chaseTimer(200, &chaseEffect);
bool doChase = false;
int chaseIndex = 0;
int led_chase_array[4] = {LED1, LED2, LED4, LED3};

void breatheEffect();
SoftwareTimer breathTimer(15, &breatheEffect);
bool doBreathe = false;
int breathValue = 1;
int breathDir = 1;


void setup() {
  
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  pinMode(BUTTON, INPUT);  
}

void twinkleEffect(){
  if(doTwinkle == true){
    for(int i=0; i<4; i++){
      analogWrite(led_array[i], random(1,255));
    }
  }
}

void chaseEffect(){
  if(doChase == true){
    for(int i=0; i<4; i++){
      if(i == chaseIndex){
        digitalWrite(led_chase_array[i], HIGH);
      }else{
        digitalWrite(led_chase_array[i], LOW);
      }
    }
    chaseIndex += 1;
    if(chaseIndex >= 4){
      chaseIndex = 0;
    }
  }
}

void breatheEffect(){
  if(doBreathe == true){
    for(int i=0; i<4; i++){
      analogWrite(led_array[i], breathValue);
    }
    breathValue += 1*breathDir;

    if(breathValue >= 250){
      breathDir = -1;
    }
    if(breathValue <= 10){
      breathDir = 1;
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  
  int reading = digitalRead(BUTTON);  // Read the value/state of the Button pin to see if it's been pressed

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // reset the debouncing timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;      

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        

        LED_STATE += 1;

        if(LED_STATE >= 10){
          LED_STATE = 0;
        }

        delay_value += 30;
        if(delay_value >= 255){
          delay_value = 1;
        }        
      }
    }
  }

  switch (LED_STATE) {
    case 0:
      doBreathe = false;
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);      
      break;
    case 1:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      break;
    case 2:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      break;
    case 3:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      break;
    case 4:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      break;
    case 5:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      break;
    case 6:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      break;
    case 7: //twinkle effect
      doTwinkle = true;
      break;
    case 8: //chase effect
      doTwinkle = false;
      doChase = true;
      break;
    case 9: //breath effect
      doChase = false;
      doBreathe = true;
    default:
      break;
          
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  twinkleTimer.tick();
  chaseTimer.tick();
  breathTimer.tick();
}


