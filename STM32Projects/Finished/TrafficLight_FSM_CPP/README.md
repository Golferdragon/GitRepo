# Traffic Light FSM in C++ for STM32F3Discovery

## Overview

This project implements a traffic light controller as a finite state machine using C++ on the STM32F3Discovery board.

The purpose of the project is to practice embedded C++ development, state machine design, GPIO control, and STM32CubeIDE project organization.

## Hardware

- STM32F3Discovery board
- STM32F303VCT6 microcontroller
- Onboard LEDs and/or configured GPIO outputs

## Tools

- STM32CubeIDE
- STM32CubeMX configuration
- GCC ARM embedded toolchain
- ST-LINK debugger/programmer

## Skills Demonstrated

- Embedded C++ development
- Finite state machine design
- GPIO output control
- STM32CubeIDE project setup
- STM32 startup/build configuration
- Hardware-level testing and debugging

## Project Structure

| Path / File | Description |
|---|---|
| `Core/` 								| Main STM32 application source and configuration files |
| `Drivers/` 							| STM32 HAL/CMSIS drivers 								|
| `TrafficLight_FSM_CPP.ioc` 			| STM32CubeMX configuration file 						|
| `.cproject`, `.project`, `.mxproject` | STM32CubeIDE project metadata 						|
| `TrafficLight_FSM_CPP.cfg` 			| Debug/programming configuration 						|
| `STM32F303VCTX_FLASH.ld` 				| Linker script for STM32F303VCTx flash memory 			|

## Development Notes

During development, one build issue encountered was:

- undefined reference to 'main'
