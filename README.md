# StringDumper — ASCII & Unicode String Extractor

![C++17](https://img.shields.io/badge/C++-17-blue.svg?logo=c%2B%2B)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg?logo=windows)
![License](https://img.shields.io/badge/License-MIT-green.svg)

A lightning-fast, command-line utility for reverse engineers and malware analysts. It scans any binary file and extracts printable **ASCII** and **Unicode (UTF-16 LE)** strings, providing the exact raw hex offset for each discovery. It's the perfect first-step triage tool for unknown binaries.

       ____       __    _ __  ____             __
      / __ \_____/ /_  (_) / / __ \___  ____  / /___  __  __
     / / / / ___/ __ \/ / __/ / / / _ \/ __ \/ / __ \/ / / /
    / /_/ / /  / /_/ / / /_/ /_/ /  __/ /_/ / / /_/ / /_/ /
    \____/_/  /_.___/_/\__/_____/\___/ .___/_/\____/\__, /
                                    /_/            /____/
                          www.orbitdeploy.com

---

## 🔥 Features

| Feature | Details |
| :--- | :--- |
| **Dual Encoding** | Seamlessly detects both standard ASCII (1-byte) and UTF-16 LE (2-byte) strings. |
| **Precise Offsets** | Reports the exact raw offset (`0x...`) within the file where the string begins, ready to be inspected in an exact hex editor or disassembler. |
| **Memory-Mapped I/O** | Uses Windows native memory mapping (`CreateFileMappingW`) to handle massive files with zero overhead and instantaneous processing. |
| **Configurable Threshold** | Ignores garbage data by enforcing a minimum string length (default is usually 4+ characters). |

---

## ⚙️ Requirements

* **Windows OS** (Relies on native Win32 APIs for file mapping)
* **Visual Studio 2022** (C++17 standard or later)
* Architectures: **x64** and **x86**

---

## 🛠️ Build

1. Open `StringDumper.slnx` in Visual Studio 2022.
2. Select your desired configuration (`Release` is recommended for speed).
3. Build the solution. The output will be `StringDumper.exe`.

---

## 🚀 Usage

Run the tool from your command prompt or PowerShell terminal.

    StringDumper.exe <path_to_binary>

**Example Output:**

    [0x000004E0] [ASCII]   This program cannot be run in DOS mode.
    [0x00001024] [ASCII]   .text
    [0x00002A40] [UTF-16]  kernel32.dll
    [0x00002A58] [UTF-16]  VirtualAlloc
    [0x000031B0] [ASCII]   http://malicious-domain.com/payload.bin

*(Outputs vary heavily depending on the target binary)*

---

## 📂 Use Cases in Reverse Engineering

Extracting strings is typically step zero in static analysis. Use `StringDumper` to quickly identify:
* Suspicious URLs, IP addresses, or domains.
* Imported or dynamically loaded DLL names (`ntdll.dll`, `wininet.dll`).
* Leftover debug paths (PDB paths) indicating the original author's environment.
* Registry keys or file paths the executable might attempt to modify.

---

## 🤝 Support & More Tools

This tool is part of the **OrbitDeploy** research initiative, focused on building lightweight, zero-overhead C++ utilities for system administrators and reverse engineers. 

If you find this utility helpful for your static analysis workflows, please consider **giving this repository a ⭐ star** to stay updated on future releases and undocumented Windows API research!

Visit [OrbitDeploy.com](https://www.orbitdeploy.com) for more tools.

---

## 📄 License

MIT License. See [LICENSE](LICENSE) for details.
