#!/usr/bin/make
# WARN: gmake syntax
SHELL := bash

# This include is unique for every library project!
include ../../MkFiles/MockEEPROM.mk

# Upload sketch to the Arduino board with 'run' command

#UPLOADPORT := /dev/ttyUSB0
#UPLOADPORT := /dev/ttyACM0
#UPLOADPORT := /dev/ttyACM1
#UPLOADPORT := /dev/ttyACM2
UPLOADPORT := /dev/ttyACM3

all: require help

# Standard includes
include ../../MkFiles/require.mk
include ../../MkFiles/help.mk
include ../../MkFiles/clean.mk
include ../../MkFiles/dist.mk
include ../../MkFiles/install.mk
include ../../MkFiles/html.mk
include ../../MkFiles/clang-format.mk
include ../../MkFiles/cppcheck.mk
include ../../MkFiles/arduino-cli.mk

# Lint commands for library contribution to the Arduino official index.
include ../../MkFiles/arduino-lib.mk

run: install
	cd examples/$(TESTSKETCH) && arduino-cli compile --fqbn arduino:avr:uno $(TESTSKETCH).ino
	cd examples/$(TESTSKETCH) && arduino-cli upload -p $(UPLOADPORT) --fqbn arduino:avr:uno $(TESTSKETCH).ino

test-esp32: install
	cd examples/$(TESTSKETCH) && arduino-cli -v compile --fqbn esp32:esp32:tinypico $(TESTSKETCH).ino

test-uno: install
	cd examples/$(TESTSKETCH) && arduino-cli -v compile --fqbn arduino:avr:uno $(TESTSKETCH).ino

test-esp8266: install
	cd examples/$(TESTSKETCH) && arduino-cli -v compile --fqbn esp8266:esp8266:d1_mini $(TESTSKETCH).ino

test-STM32G031: install
	cd examples/$(TESTSKETCH) && arduino-cli -v compile --fqbn STMicroelectronics:stm32:GenG0 $(TESTSKETCH).ino

test: install
	cd test && $(MAKE) all-tests

release: clang-format cppcheck html test
	@echo " --------------------------------------------------------------"
	@echo " Remember, bump version and upload new html-> branch 'gh-pages'"
	@echo " --------------------------------------------------------------"

.PHONY: require help clean-build install dist test test-uno test-esp32 test-esp8266 test-STM32G031 html clang-format cppcheck release lint index
