void loop() {
  // copy from virtual serial line to uart and vice versa
  if (Serial.available()) {           // got anything from USB-Serial?
    char c = (char)Serial.read();     // read from USB-serial
    if (commandMode == false) {       // if we aren't in command mode...
      if (c == '~') {                 //    Tilde '~' key pressed?
        commandMode = true;           //       enter in command mode
      } else {
        Serial1.write(c);             //    otherwise write char to Linux
      }
    } else {                          // if we are in command mode...
      if (c == '0') {                 //     '0' key pressed?
        Serial1.begin(57600);         //        set speed to 57600
        Serial.println("Speed set to 57600");
      } else if (c == '1') {          //     '1' key pressed?
        Serial1.begin(115200);        //        set speed to 115200
        Serial.println("Speed set to 115200");
      } else if (c == '2') {          //     '2' key pressed?
        Serial1.begin(250000);        //        set speed to 250000
        Serial.println("Speed set to 250000");
      } else if (c == '3') {          //     '3' key pressed?
        Serial1.begin(500000);        //        set speed to 500000
        Serial.println("Speed set to 500000");
      } else if (c == '~') {
        Serial1.write((uint8_t *)"\xff\0\0\x05XXXXX\x0d\xaf", 11);
        Serial.println("Sending bridge's shutdown command");
      } else {                        //     any other key pressed?
        Serial1.write('~');           //        write '~' to Linux
        Serial1.write(c);             //        write char to Linux
      }
      commandMode = false;            //     in all cases exit from command mode
    }
  }
  if (Serial1.available()) {          // got anything from Linux?         
    char c = (char)Serial1.read();    // read from Linux  
    Serial.write(c);                  // write to USB-serial
  }
}
