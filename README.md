# BareUtils

Optimized, zero-fragmentation C/C++ utilities for embedded devices (Arduino, ESP32, ESP8266) designed to work without heap fragmentation.

## Features

- **MacUtils**: Safe conversion between binary MAC arrays and formatted strings.
- **StringUtils**: Zero-allocation, high-performance string utilities for microcontrollers:
  - `trim`: Fast in-place whitespace removal using pointer arithmetic.
  - `numberToText`: Zero-allocation `uint32_t` to text conversion with a 4-slot static circular buffer.
  - `buildParts`: Linear-time $O(N)$ string concatenation using `std::initializer_list` without dynamic allocation or `strcat` rescans.
- **BinaryUtils**: Ultra-fast translation between raw binary buffers and hex representation.

## Usage

Include the main header in your PlatformIO/Arduino project:

```cpp
#include <BareUtils.h>
```

Or include specific utils:

```cpp
#include <MacUtils.h>
#include <StringUtils.h>
#include <BinaryUtils.h>
```
