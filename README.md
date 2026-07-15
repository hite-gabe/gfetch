# gfetch
gfetch is a system info fetch tool written in c.

## Requirements
gfetch can run on about any Linux system. This includes Debian, Arch, Linux Mint, Ubuntu, Fedora, and so on...

## Features
* Displays Operating System and Kernel Version
* Fetches the current active Username
* Reads the live System Time
* Accurately calculates Total RAM using kernel memory units
* Displays Total and Free Storage space for the root partition

## Installation

1. Clone the repository or download the source code:
   ```bash
   gcc main.c -o gfetch
2. You can also download the pre-compiled binary, and copy it to usr/local/bin/ using
   ```bash
   sudo cp gfetch /usr/local/bin/
