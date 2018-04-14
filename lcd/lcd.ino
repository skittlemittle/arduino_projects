// Displays "Hello World" on a JHD 162A LCD

// include the library code
#include <LiquidCrystal.h>

// initialize the library and set the pins the LCD is connected to
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
	// Print a message to the LCD.
  lcd.print("hello, world!");
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print another message on the next line
  lcd.print("random message");
}

