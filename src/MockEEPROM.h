/*!
 * @file MockEEPROM.h
 *
 * This is part of mocked EEPROM library for the Arduino platform.
 *
 * The MIT license.
 *
 */

#ifndef MOCKEEPROM_H_
#define MOCKEEPROM_H_

#ifndef ARDUINO
#include <cstdint>
#include <thread>
#include <iostream>
#endif

/*!
 *  \addtogroup mock
 *  @{
 */

//! Arduino mocked methods
namespace mock {

    //-------------------------------------------------------------------------
    /*!
     @brief  Arduino Mock methods for Arduino library EEPROM.
     */
    //-------------------------------------------------------------------------
    class MockEEPROM {
    public:

        //-----------------------------------------------------------------
        /*!
         @brief  Constructor.
         */
        //-----------------------------------------------------------------
        MockEEPROM(void) {
        }
        ;

        //-----------------------------------------------------------------
        /*!
         @brief  Deallocate MockEEPROM object.
         */
        //-----------------------------------------------------------------
        ~MockEEPROM(void) {
        }
        ;

        // ------------------ Arduino EEPROM library -----------------------

        //-----------------------------------------------------------------
        /*!
         @brief  Mocked EEPROM read.
         @param  address
         Read a byte from EEPROM address.
         @return The mocked read() value, i.e., zero.
         */
        //-----------------------------------------------------------------
        static uint16_t read(uint16_t address) {
            return 0;
        }
        ;

        //-----------------------------------------------------------------
        /*!
         @brief  Mocked EEPROM write returns without action.
         @param  address
         The EEPROM address to write a byte.
         @param  value
         The value (byte) to write at that address.
         */
        //-----------------------------------------------------------------
        static void write(uint16_t address, uint16_t value) {
        }
        ;

        //-----------------------------------------------------------------
        /*!
         @brief  Mocked EEPROM update returns without action.
         @param  address
         The EEPROM address to write a byte.
         @param  value
         The value to write (byte), if different at that address.
         */
        //-----------------------------------------------------------------
        static void update(uint16_t address, uint16_t value) {
        }
        ;

        //-----------------------------------------------------------------
        /*!
         @brief  Mocked EEPROM get.
         @param  address
         Read from EEPROM address.
         @param  data
         Read data from EEPROM address.
         @return The mocked get() value, i.e., zero.
         */
        //-----------------------------------------------------------------
        static uint16_t get(uint16_t address, uint16_t data) {
            return 0;
        }
        ;

        //-----------------------------------------------------------------
        /*!
         @brief  Mocked EEPROM put.
         @param  address
         The EEPROM address to write a byte.
         @param  data
         Write data to EEPROM address.
         */
        //-----------------------------------------------------------------
        static void put(uint16_t address, uint16_t data) {
        }
        ;

        //-----------------------------------------------------------------
        /*!
         @brief  Mocked EEPROM length.
         @return The mocked length() value, i.e., zero.
         */
        //-----------------------------------------------------------------
        static uint16_t length(void) {
            return 0;
        }
        ;

        //-----------------------------------------------------------------
        /*!
         @brief  Mocked EEPROM begin.
         @return The mocked begin() value, i.e., zero.
         */
        //-----------------------------------------------------------------
        static uint16_t begin(void) {
            return 0;
        }
        ;

        //-----------------------------------------------------------------
        /*!
         @brief  Mocked EEPROM end.
         @return The mocked end() value, i.e., zero length.
         */
        //-----------------------------------------------------------------
        static uint16_t end(void) {
            return 0;
        }
        ;

    };

/*  class MockEEPROM */

} /* namespace mock */

/*! @} End of Doxygen Groups*/

#endif /* MOCKEEPROM_H_ */
