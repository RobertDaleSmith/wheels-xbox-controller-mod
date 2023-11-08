// define the pins used in the program
const int analogInputPins[] = {A0, A1, A2, A3}; // Analog input pins
const int floatingOutputPins[] = {A2, A3}; // Analog pins used as floating digital outputs

void setup() {
  Serial.begin(115200); // Start serial communication at a baud rate of 9600
  
  // configure the input pins
  for (int i = 0; i < 2; i++) {
    pinMode(analogInputPins[i], INPUT);
  }

  // configure the output pins
  for (int i = 0; i < 2; i++) {
    pinMode(floatingOutputPins[i], OUTPUT);
    // Instead of driving the pin HIGH or LOW, we're setting it to a high-impedance state, effectively making it floating.
    digitalWrite(floatingOutputPins[i], LOW); // This is necessary to ensure the pins are in a known state, but they will remain effectively floating since we're not setting them HIGH.
  }

}

void loop() {
  // read the input on analog pins and print them to the serial monitor
  // Read the analog input values from the joystick
  int rawValueX = analogRead(analogInputPins[0]);
  int rawValueY = analogRead(analogInputPins[1]);

  // Map these values to the range 0-255
  int mappedValueX = map(rawValueX, 0, 1023, 0, 255);
  int mappedValueY = map(rawValueY, 0, 1023, 0, 255);

  // Output the mapped values - this is just for debugging and can be removed later
  Serial.print("X: ");
  Serial.print(mappedValueX);
  Serial.print("\tY: ");
  Serial.println(mappedValueY);

  // Right Stick Up == L2
  if (mappedValueY < 50) {
    pinMode(A2, OUTPUT);
    digitalWrite(A2, LOW);
  } else {
    pinMode(A2, INPUT);
  }

  // Right Stick Down == L1
  if (mappedValueY > 90) {
    pinMode(A3, OUTPUT);
    digitalWrite(A3, HIGH);
  } else {
    pinMode(A3, INPUT);
  }
}
