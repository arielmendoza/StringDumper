# StringDumper

A Windows command-line utility that extracts readable strings from binary files — similar to the classic Unix `strings` tool, with support for both ASCII and Unicode (UTF-16 LE) strings.

## Features

- Extracts **ASCII** printable strings (characters 0x20–0x7E)
- Extracts **Unicode** (UTF-16 LE) strings
- Reports the **file offset** of each string found
- Minimum string length filter (4 characters) to reduce noise
- Skips whitespace-only strings
- Supports any binary file: executables, DLLs, firmware images, etc.

## Usage

```
StringDumper.exe <file_path>
```

**Example:**

```
StringDumper.exe C:\Windows\System32\notepad.exe
```

**Sample output:**

```
   ____       __    _ __  ____             __
  / __ \_____/ /_  (_) / / __ \___  ____  / /___  __  __
 / / / / ___/ __ \/ / __/ / / / _ \/ __ \/ / __ \/ / / /
/ /_/ / /  / /_/ / / /_/ /_/ /  __/ /_/ / / /_/ / /_/ /
\____/_/  /_.___/_/\__/_____/\___/ .___/_/\____/\__, /
                                /_/            /____/
========================================================
            StringDumper Utility v1.0
========================================================

File: C:\Windows\System32\notepad.exe
Size: 226816 bytes

--- ASCII Strings (min length: 4) ---
Offset          String
-------------   -----------------------------
0x000000e0      !This program cannot be run in DOS mode.
0x00000180      .text
...

--- Unicode Strings (min length: 4) ---
Offset          String
-------------   -----------------------------
0x00012a00      Open
0x00012a20      Save
...

-------------------------------------
ASCII: 142 strings found
Unicode: 87 strings found
```

## Building

Open `StringDumper.slnx` in **Visual Studio 2022** and build.

Supported platforms: `x64`, `ARM64`, `x86`
Configuration: `Release` / `Debug`

**Requirements:**
- Windows
- Visual Studio 2022 with C++ Desktop Development workload
- C++17 or later (uses `std::filesystem`)

## Use Cases

- Malware analysis / reverse engineering
- Binary inspection and forensics
- Firmware analysis
- Finding hardcoded credentials or configuration strings in executables

## License

MIT License — see [LICENSE](LICENSE) for details.
