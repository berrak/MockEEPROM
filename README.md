[![GitHub license](https://img.shields.io/github/license/berrak/MockEEPROM.svg?logo=gnu&logoColor=ffffff)](https://github.com/berrak/MockEEPROM/blob/master/LICENSE)
[![GitHub version](https://img.shields.io/github/release/berrak/MockEEPROM.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/MockEEPROM/releases/latest)
[![GitHub issues](https://img.shields.io/github/issues/berrak/MockEEPROM.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/MockEEPROM/issues)
[![Documentation](https://img.shields.io/badge/documentation-doxygen-green.svg)](https://berrak.github.io/MockEEPROM/)
[![Installation instructions](https://www.ardu-badge.com/badge/MockEEPROM.svg?)](https://www.ardu-badge.com/MockEEPROM)

# Arduino library MockEEPROM
Replace the Arduino library EEPROM with the `mocked` version and let you develop code without the hardware. The mocked functions return immediately or return zero. Run parallel hardware and system development for greater efficiency. Arduino's command line tool, such as [arduino-cli](https://github.com/arduino/arduino-cli), frees you from Arduino IDE for tests and uploads.

## Why try mocking Arduino speak and and it's libraries?

- Develop software independently of any related parallel hardware project.
- Use any development environment or your favorite editor with `arduino-cli` and library `MockEEPROM`.
- Use existing well-known tools for debugging.
- Reach set time goals faster in any Arduino microcontroller project.

The purpose of this library is to be a practical eye-opener on mocked object usage, at least for some early phases of the project development cycle. Another objective of mocking is to focus on avoiding `logical human errors` in the overall design flow of the program. Unfortunately, this problem in the code tends to be less well-tested and may end up as an end-user complaint.

## Usage

Add the `include path` to the `MockEEPROM` source directory for the IDE. For example, in the `Eclipse IDE`, open.
`Project->Properties->C++ General->Paths and Symbols->Includes->Languages: Gnu C++, Include Directories: /home/bekr/Arduino/libraries/MockEEPROM/src`.

At the beginning of the `main.cpp` file, add.
```cpp
#include <MockEEPROM.h>
using namespace mock;
```
Pre-pend all Arduino's EEPROM library calls with '`MockEEPROM::`', like this.

```cpp
MockEEPROM::put(0, value);
```
The mocked functions return immediately or return zero. To remove all mocking fragments, use either search/replace in the IDE, or run the `make-demock.sh` (recommended method) shell script on the file to erase all added `mock` -fragments. If replacing `Arduino language constructs`, add the include path for `Mock` in the IDE. See library [Mock](https://github.com/berrak/Mock/) for information.


## Examples

In Arduino IDE scroll down the long list below `File->Examples` and find `MockEEPROM`. An example run may look like the following screen output. Note that the mocked methods return zero or return immediately.

```
Mocked Arduino methods returns zero, or returns directly.
Setup done.
Adr:0, try to put PI to EEPROM: 3.14156
Adr:0, get from EEPROM: 0.00
Adr:4, try to write hex 'FF' to EEPROM: FF
Adr:4, read byte from EEPROM: 0
Adr:4, try to update hex 'AA' to EEPROM: AA
Adr:4, read byte after update from EEPROM: 0
length(): 0
begin(): 0
end(): 0
```

## Documentation (GitHub Pages - Doxygen)

[Library documentation](https://berrak.github.io/MockEEPROM/).

## How to Install

Click on the green `Library Manager` badge above for instructions,
or use the alternative manual installation procedure.

1. Navigate to the [Releases page](https://github.com/berrak/MockEEPROM/releases).
1. Download the latest released ZIP-archive in `~/Arduino/libraries`.
1. Unzip the archive.
1. Rename the new directory. Remove *version-code*, or *master* in the name like this for `MockEEPROM`.
1. Restart Arduino IDE.
1. In Arduino IDE scroll down the long list below `Sketch->Include Library` and find `MockEEPROM`.

## Ensure any mock-fragments are removed in the build process

In the [Mock](https://github.com/berrak/Mock) `script` folder is the canonical `make-demock.sh` shell script for removing any mock fragments in the released code. Ensure that your Arduino installation uses the latest version of `Mock`. The script will remove mock fragments and ensure that, e.g., `MockEEPROM` is replaced with `EEPROM`. Finally, add the `#include <EEPROM.h>` to the source; now, the actual Arduino library works as expected.

Run the script with the file name, as the argument, like so.
```
make-demock.sh sketch.ino
make-demock.sh other.cpp
make-demock.sh other.h
```

## Planned Improvements/Changes

For planned changes, improvements, and known bugs, please visit the [Github issues tracker](https://github.com/berrak/MockEEPROM/issues).

