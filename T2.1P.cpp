
//Declared constant output variable
const uint8_t BTN_PIN = 2;
const uint8_t RED_PIN = 13;
const uint8_t BLU_PIN = 7;

//Declared variable and their initial statue
volatile uint8_t ButtonState = 0;
uint8_t ledState = LOW;

//Declared a void function
void setup()
{
  pinMode(A1,INPUT);
  //To configure BTN_PIN to behave as an input
  pinMode(BTN_PIN, INPUT_PULLUP);
  //To configure LED_PIN to behave as an output
  pinMode(RED_PIN, OUTPUT);
  //Passes the value 9600 to the speed parameter.
  pinMode(BLU_PIN, OUTPUT)；

  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), pin_ISR, CHANGE);
}

void loop()
{
}

void pin_ISR(){
  ButtonState = digitalRead(BTN_PIN);
  //digitalWrite(LED_PIN, ButtonState);
  double temperature = (-40 + 0.488155 * (analogRead(A1) - 20));
  Serial.print(temperature);
  Serial.println("");
  if (temperature > 24)
  {
    digitalWrite(RED_PIN, ButtonState);
  }
  if (temperature < 18)
  {
    digitalWrite(BLU_PIN, ButtomState);
  }
}