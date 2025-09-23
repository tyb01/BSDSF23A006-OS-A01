
# REPORT.md

##  Feature 2: Multi-file Compilation with Makefile

**Q1. Explain the linking rule in this part's Makefile: `$(TARGET): $(OBJECTS)`. How does it differ from a Makefile rule that links against a library?**  
- This rule means: to build the final program (`TARGET`), we need all the compiled object files (`OBJECTS`).  
- In this case, the linker directly combines `.o` files into the executable.  
- When linking against a library, the rule would instead use something like `-lmyutils` (with `-L` to show the library path), so the linker pulls functions from a library file instead of directly from object files.

**Q2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?**  
- A **git tag** marks a specific commit as important, usually for a release version.  
- It helps track stable points in history.  
- A **simple tag** is just a pointer to a commit.  
- An **annotated tag** has extra info like message, author, and date (preferred for releases).  

**Q3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?**  
- A GitHub Release is a packaged version of your project for others to download easily.  
- Attaching binaries means users don’t need to compile; they can directly run your program.  

---

##  Feature 3: Static Libraries

**Q1. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?**  
- In Part 2, I  compiled `.c` files directly into an executable.  
- In Part 3, I first compiled `.c` into `.o` files, then used `ar` to archive them into `libmyutils.a`.  
- The Makefile links the main program with this `.a` library instead of separate `.o` files.  

**Q2. What is the purpose of the `ar` command? Why is `ranlib` often used immediately after it?**  
- `ar` collects object files into a static library (`.a`).  
- `ranlib` adds an index so the linker can quickly find functions inside the library.  

**Q3. When you run `nm` on your `client_static` executable, are the symbols for functions like `mystrlen` present? What does this tell you about how static linking works?**  
- No, the symbols don’t appear, because the code from the library is copied directly into the executable.  
- This shows that static linking makes the final program self-contained and independent of the library file.  

---

## Feature 4: Dynamic Libraries

**Q1. What is Position-Independent Code (-fPIC) and why is it a fundamental requirement for creating shared libraries?**  
- PIC makes sure code can run no matter where it is loaded in memory.  
- Shared libraries need this because different programs may load them at different memory addresses.  

**Q2. Explain the difference in file size between your static and dynamic clients. Why does this difference exist?**  
- The static client is larger because it contains full copies of all library functions.  
- The dynamic client is smaller because it only stores references, and the actual code stays in the `.so` file, loaded at runtime.  

**Q3. What is the `LD_LIBRARY_PATH` environment variable? Why was it necessary to set it for your program to run, and what does this tell you about the responsibilities of the operating system's dynamic loader?**  
- `LD_LIBRARY_PATH` tells the OS loader where to look for shared libraries.  
- Without setting it, the system doesn’t know about your custom `libmyutils.so` in the project folder.  
- This shows the loader’s job is to find and connect dynamic libraries when running a program.  

---

##  Feature 5: Man Pages & Installation

**Q1. What are the required sections of a man page and why?**  
- `.TH`: Title and header info.  
- `.SH NAME`: Program/function name and one-line description.  
- `.SH SYNOPSIS`: Shows how to use it (syntax).  
- `.SH DESCRIPTION`: Explains in detail what it does.  
- `.SH AUTHOR`: Who wrote it.  
- These sections keep all man pages consistent and easy to read.  

**Q2. Why use `make install`?**  
- It simulates how software is installed on Linux.  
- It copies the binary into `/usr/local/bin` so you can run it from anywhere.  
- It copies man pages into the right folder so `man` can find them.  
- It gives a real-world feel of how professional software is deployed.  

---

##  Final Reflection

This project helped me understand:  
- How to split code into multiple files for clarity.  
- How to use Makefiles to automate builds.  
- The difference between static and dynamic linking.  
- How to create and use man pages for documentation.  
- How to use Git features like branches, tags, and GitHub releases.  
