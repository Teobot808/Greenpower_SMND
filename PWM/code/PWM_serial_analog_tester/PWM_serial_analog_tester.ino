
// This code can be used for simple testing of PWM control of a transistor.
// Connect the pin which needs PWM control to pin 16 of your ESP32.
// If you are using Arduino, connect the PWM to pin 9 and change 16 to 9 in the code (change it in: pinMode() and analogWrite() functions).
// The value inputed to serial should be between 0-255. If you uncomment these 3 lines in the code: 
    //inputValue = inputValue * 2.55;
      //Serial.print("New value received: ");
       //Serial.print(inputValue/2.55);  // Print the new value
// After uncommenting these lines you can input values between 0-100 and it will have the same effect.

int val = 0;
int inputValue = 0;  // Variable to store the input value
String inputString = "";  // Variable to store the input string


void setup() {
  // put your setup code here, to run once:
pinMode(16, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available() > 0) {
    char receivedChar = Serial.read();  // Read a character
    if (receivedChar == '\n' || receivedChar == '\r') {
      if (inputString.length() > 0) {
        inputValue = inputString.toInt();  // Convert the string to an integer
        //inputValue = inputValue * 2.55;
        //Serial.print("New value received: ");
       //Serial.print(inputValue/2.55);  // Print the new value
                Serial.print("   New value received: ");
        Serial.println(inputValue);  // Print the new value

        inputString = "";  // Clear the string for the next input
      }
    } else {
      inputString += receivedChar;  // Append the character to the input string
    }
  }
val = inputValue;
  analogWrite(16, val);
  //Serial.println(val); uncomment to see the value of val live, this will cause a lot of input to the serial port but you can still input desired PWM values.
}
