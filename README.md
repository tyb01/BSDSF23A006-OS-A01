# Operating Systems Assignment – PA-01  

## Overview  
This project demonstrates how to build, structure, and document a Linux software project step by step. It covers:  
- Multi-file compilation  
- Using Makefiles  
- Static and dynamic libraries  
- Documentation with man pages  
- Git branching, tagging, and GitHub releases  

The final deliverable is a command-line program called **`client`** that uses both string functions and file functions.  

---

##  Project Structure  

BSDSF23A006-OS-A01/
│── include/ # Header files (.h)
│ ├── mystrfunctions.h
│ ├── myfilefunctions.h
│
│── src/ # Source files (.c)
│ ├── mystrfunctions.c
│ ├── myfilefunctions.c
│ ├── main.c
│
│── lib/ # Libraries (.a and .so)
│ ├── libmyutils.a
│ ├── libmyutils.so
│
│── bin/ # Binaries
│ ├── client
│ ├── client_static
│ ├── client_dynamic
│
│── man/ # Documentation
│ ├── man3/ # Function man pages
│ ├── mystrlen.1
│ ├── mystrcpy.1
│ ├── mystrncpy.1
│ ├── mystrcat.1
│ ├── wordcount.1
│ └── mygrep.1
│
│── Makefile # Build automation
│── REPORT.md # Report answers
│── README.md # Project guide

---
##  Build Instructions  

### 1. Clone the repository  
```bash
git clone https://github.com/tyb01/BSDSF23A006-OS-A01.git
cd BSDSF23A006-OS-A01
2. Compile using Make
make
Builds the program into bin/client.

Intermediate object files go to obj/.

3. Clean build files
bash
Copy code
make clean
📦 Installation
Install the program and man pages system-wide:

bash
Copy code
sudo make install
Now you can run the program from anywhere:

bash
Copy code
client test.txt
And view the documentation:

bash
Copy code
man client
man mystrlen
man mygrep
🔑 Features Implemented
Feature 1 – Multi-file Compilation

Code is split into .c and .h files.

Feature 2 – Makefile

Professional Makefile with macros and recursive build.

Feature 3 – Static Library

Utility functions archived into libmyutils.a.

Program linked with the static library.

Feature 4 – Dynamic Library

Utility functions compiled into libmyutils.so.

Program dynamically linked (requires LD_LIBRARY_PATH).

Feature 5 – Man Pages & Install

Created man pages for all functions and the client program.

Added install target for system-wide installation.

🛠 Git Workflow
Branches

multifile-build → Multi-file project setup

static-build → Static library build

dynamic-build → Dynamic library build

man-pages → Documentation & install target

Tags & Releases

v0.1.1-multifile

v0.2.1-static

v0.3.1-dynamic

v0.4.1-final

Each tag corresponds to a GitHub Release with attached binaries and libraries.

 Author
Name: Muhammad Tayyab
Roll No: BSDSF23A006
Email: tyb3122@gmail.com
