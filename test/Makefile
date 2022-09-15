#!/usr/bin/make
# WARN: gmake syntax

# The 'make-test-all.sh' script finds all sketeches in examples/ for tests
all: help

help:
	@echo
	@echo " help ---------- show this help"
	@echo " all-tests ----- Compiles all sketches (*.ino) found below examples/"
	@echo

all-tests: all-uno all-tinypico all-d1mini all-STM32G0
	@echo " Compiles OK (Arduino Uno 328P, ESP32-TinyPICO, ESP8266-D1-mini, STM32G0)"

all-uno:
	cd ../examples && make-test-all.sh arduino:avr:uno

all-tinypico:
	cd ../examples && make-test-all.sh esp32:esp32:tinypico

all-d1mini:
	cd ../examples && make-test-all.sh esp8266:esp8266:d1_mini

all-STM32G0:
	cd ../examples && make-test-all.sh STMicroelectronics:stm32:GenG0

.PHONY: all help all-uno all-tinypico all-d1mini all-d1mini all-STM32G0 all-tests
