## `Rust/RustWithSTM32F3/stm32f3_buttoncontrolledled/README.md`

# STM32F3 Button-Controlled LED in Rust

## Overview

This project controls an onboard LED on the STM32F3Discovery board using the board's user button.

The purpose of this project is to move beyond a basic blinky example and practice GPIO input, GPIO output, pull-up input configuration, and simple embedded control logic in Rust.

## Hardware

- STM32F3Discovery board
- STM32F303VCT6 microcontroller
- User button
- Onboard LED

## Hardware Notes

For the STM32F3Discovery board:

| Signal | Pin |
|---|---|
| User button 	| `PC13` |
| Green LED 	| `PE9` |

## Skills Demonstrated

- Embedded Rust
- `#![no_std]`
- GPIO input configuration
- GPIO output configuration
- Pull-up input handling
- Reading button state
- Controlling an LED based on input state

## Development Notes

This project used the `stm32f3xx-hal` crate with the STM32F303 device feature:

```toml
stm32f3xx-hal = { version = "0.9.2", features = ["stm32f303xc"] }
