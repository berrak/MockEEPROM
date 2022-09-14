#ifdef ARDUINO
//============================================================================
// Sketch name : MockEEPROM.ino
// Author      : Created by Debinix Team (c).
// Date        : 2022-09-14.
// License     : The MIT License.
// Description :
// Mock methods for Arduino library EEPROM. Replace Arduino methods and
// develope code without the hardware. Shows how the EEPROM function works.
// The mocked functions returns immediately or returns zero.
//
// Add:   #include <MockEEPROM.h>
//        using namespace mock;
//        and
//        Prepend all Arduino's calls with 'MockEEPROM::'
//
// To revert mocking, remove these changes in the IDE or with shell
// the script 'make-demock.sh'. See (https://github.com/berrak/Mock)
//
// Source: https://github.com/berrak/MockEEPROM
//
//============================================================================

#include <MockEEPROM.h>
using namespace mock;

float write_value = 3.14156;
float read_zero_pi_value = 1 ;  // any float but not 0
int byte_write = 0xFF ;
int byte_read = 0xAA ;          // any byte but not 0x00

void setup() {

    Serial.begin(9600);
    delay(1000);
    Serial.println("Mocked Arduino methods returns zero, or returns directly.");
    Serial.println("Setup done.");
}

void loop() {

    // Mocked Arduino EEPROM library calls - writes/puts/updates never occures
    Serial.print("Adr:0, try to put PI to EEPROM: ");
    Serial.println(write_value,5);
    MockEEPROM::put(0, write_value);

    read_zero_pi_value = MockEEPROM::get(0,write_value);
    Serial.print("Adr:0, get from EEPROM: ");
    Serial.println(read_zero_pi_value);

    Serial.print("Adr:4, try to write hex 'FF' to EEPROM: ");
    Serial.println(byte_write,HEX);
    MockEEPROM::write(4, byte_write);

    byte_read = MockEEPROM::read(4);
    Serial.print("Adr:4, read byte from EEPROM: ");
    Serial.println(byte_read);

    Serial.print("Adr:4, try to update hex 'AA' to EEPROM: ");
    Serial.println(0xAA,HEX);
    MockEEPROM::update(4, 0xAA);

    byte_read = MockEEPROM::read(4);
    Serial.print("Adr:4, read byte after update from EEPROM: ");
    Serial.println(byte_read);

    // Call to lengt(), begin() and end() all returns zero.
    Serial.print("length(): ");
    Serial.println(MockEEPROM::length());

    Serial.print("begin(): ");
    Serial.println(MockEEPROM::begin());

    Serial.print("end(): ");
    Serial.println(MockEEPROM::end());
    delay(10000);

    Serial.println();

}

#endif // ARDUINO

