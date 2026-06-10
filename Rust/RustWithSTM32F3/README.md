## `Rust/RustWithSTM32F3/README.md`

# Embedded Rust with STM32F3Discovery

This folder contains embedded Rust projects targeting the STM32F3Discovery development board.

The purpose of these projects is to build familiarity with Rust in a bare-metal embedded environment, including `no_std` development, ARM Cortex-M configuration, GPIO control, and flashing firmware to the board.

## Hardware

- STM32F3Discovery board
- STM32F303VCT6 microcontroller
- ST-LINK programmer/debugger

## Projects

| Project | Description |
|---|---|
| `stm32f3-blinky/` 			 | Basic embedded Rust LED blink project |
| `stm32f3_buttoncontrolledled/` | Button-controlled LED project using the STM32F3Discovery user button and onboard LED |

## Skills Demonstrated

- Embedded Rust project setup
- `#![no_std]` and `#![no_main]`
- ARM Cortex-M runtime setup
- GPIO configuration
- STM32F3 HAL usage
- Firmware build and flashing workflow
- Board-level testing

## Development Notes

During development, the STM32F3Discovery target was configured for the STM32F303VCT6 microcontroller. One setup issue involved selecting the correct HAL feature for the specific chip variant. The correct feature used for this board was:

```toml
features = ["stm32f303xc"]
