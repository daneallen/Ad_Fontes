/* Moonlighter SAO
 * by Aeropsace Village
 * for DEFCON 2025
 * 
 * author: @cybertestpilot
 * 
 */

#include <Wire.h>

#define LED1 PIN_PA3
#define LED2 PIN_PA4
#define LED3 PIN_PA5
#define LED4 PIN_PC0
#define BUTTON A6

#define I2C_ADDR 0x7    // The number of years the Aerospace Village has been around
#define BAUD 9600

int led_array[4] = {LED1, LED2, LED3, LED4};
int led_array_index = 0;

int pause = 100;

int ledState = HIGH;        // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;

int LED_STATE = 0;

int delay_value = 3;


void setup() {

  
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  pinMode(BUTTON, INPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int reading = digitalRead(BUTTON);

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
        ledState = !ledState;

        LED_STATE += 1;

        if(LED_STATE >= 8){
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

    default:
      for(int i=0; i<4; i++){
        analogWrite(led_array[i], random(1,255));
      }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  

  delay(delay_value/2);
}


