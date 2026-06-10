# Circular Buffer in C

## Overview

This program implements a fixed-size circular buffer in C and includes basic verification tests for initialization, push, pop, full, empty, and wraparound behavior.

Circular buffers are commonly used in embedded systems for UART receive buffers, producer/consumer queues, sensor data buffering, and real-time data handling.

## Skills Demonstrated

- C struct design
- Fixed-size array buffering
- Head and tail index management
- Count-based full/empty detection
- Error handling through return codes
- Basic manual unit-style testing

## Functions

| Function | Description |
|---|---|
| `cb_init()` | Initializes the circular buffer |
| `cb_is_empty()` | Checks whether the buffer is empty |
| `cb_is_full()` | Checks whether the buffer is full |
| `cb_push()` | Adds an item to the buffer |
| `cb_pop()` | Removes an item from the buffer |

## Error Handling

The implementation uses return codes to indicate success or failure conditions.

| Return Code | Meaning |
|---:|---|
|  `0` | Success |
| `-1` | Buffer full or empty condition |
| `-2` | Null pointer argument |

## Development Notes

During development, the build setup was tested through Notepad++ and NppExec using MinGW GCC. One issue encountered was that the script was not correctly detecting the active file extension. The fix was to use `$(EXT_PART)` and compare against `.c` and `.cpp`.

The compiler paths were also adjusted to use the installed MinGW tools:

```text
C:\mingw64\bin\gcc.exe
C:\mingw64\bin\g++.exe
