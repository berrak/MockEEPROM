/*!
 * @file MockEEPROM.cpp
 *
 * @mainpage Replace Arduino standard EEPROM library with mocked methods.
 *
 * @section intro_sec Introduction
 *
 * The mocked functions return immediately or return zero. The mocked
 * version let you develop code without the hardware. Another objective
 * of mocking is to focus on avoiding logical human errors in the
 * overall design flow of the program. Unfortunately, this problem in the
 * code tends to be less well-tested and may end up as an end-user complaint.
 *
 * @section dependencies Dependencies
 *
 * This library depends only on default installed libraries for Arduino IDE.
 *
 * @section license License
 *
 * The MIT license.
 *
 */
// Required includes for Arduino libraries always go first.
#ifdef ARDUINO
// class implementation
#include <Arduino.h>
#endif
// class interface declaration
#include "MockEEPROM.h"
