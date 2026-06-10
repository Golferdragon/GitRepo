## `Rust/RustWithSTM32F3/stm32f3-blinky/README.md`

# STM32F3 Blinky in Rust

## Overview

This project is a basic embedded Rust LED blink program for the STM32F3Discovery board.

The purpose of the project is to verify the embedded Rust toolchain, board configuration, linker setup, and firmware flashing process.

## Hardware

- STM32F3Discovery board
- STM32F303VCT6 microcontroller
- ST-LINK programmer/debugger
- Onboard LED

## Skills Demonstrated

- Embedded Rust setup
- `no_std` development
- Cortex-M runtime usage
- GPIO output configuration
- Firmware build process
- Flashing a `.bin` file to the STM32F3Discovery board

## Project Structure

| Path | Description |
|---|---|
| `.cargo/` 	| Cargo configuration for the embedded target |
| `src/` 		| Rust source files |
| `Cargo.toml` 	| Project manifest and dependencies |
| `Cargo.lock` 	| Locked dependency versions |

## Build

```bash
cargo build
