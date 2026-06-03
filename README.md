# BareUtils

Optimized, zero-fragmentation C/C++ utilities for embedded devices (Arduino, ESP32, ESP8266) designed to work without heap fragmentation.

## Features

- **MacUtils**: Safe conversion between binary MAC arrays and formatted strings.
- **StringUtils**: High-performance, in-place string trimming using pointers.
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
