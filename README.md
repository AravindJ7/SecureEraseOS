# SecureEraseOS

**SecureEraseOS** is a specialized, lightweight, bootable Linux-based operating system designed for securely wiping storage devices (NVMe, SATA, USB, etc.). Built with Buildroot, it features a custom C++ application that automatically detects all connected drives and provides robust data sanitization methods.

## Features

- **Universal Booting**: Hybrid ISO supporting both modern UEFI and legacy BIOS systems.
- **Comprehensive Hardware Support**: Full kernel support for NVMe, SATA (AHCI), and standard block devices.
- **Automated Detection**: Instantly discovers all connected storage devices.
- **Robust Wiping**: Implements industry-standard secure erase algorithms.
- **Lightweight & Fast**: Runs entirely in RAM (ramfs), ensuring the host system remains untouched.

## Usage

1. **Download the ISO**: You can find the latest `SecureEraseOS.iso` in this repository.
2. **Create a Bootable USB**: Use tools like [Rufus](https://rufus.ie/) (on Windows) or `dd` (on Linux/macOS) to flash the ISO to a USB flash drive.
3. **Boot the System**:
   - Insert the USB into the target machine.
   - Enter the BIOS/UEFI boot menu and select the USB drive.
   - Choose **SecureEraseOS (Standard Mode)** from the GRUB menu.
   - *(Optional)* If you experience hardware detection issues, use **Compatibility Mode (ACPI Noirq)**.
4. **Wipe Devices**: Follow the on-screen prompts in the SecureEraseOS application to select and wipe your drives.

## Development & Build

SecureEraseOS is constructed using a highly customized [Buildroot](https://buildroot.org/) environment. The core application is written in modern C++ and interfaces directly with Linux `sysfs` and `ioctl` for low-level device management.
