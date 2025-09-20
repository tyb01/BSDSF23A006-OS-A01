Q1 — Explain the linking rule $(TARGET): $(OBJECTS). How does it differ from linking against a library?

With $(TARGET): $(OBJECTS), all $(OBJECTS) are specified explicitly and included in the link. The linker resolves symbols across these objects and produces the executable. This is the direct approach and is straightforward for small projects or initial builds.

With static library linking (link against libmyutils.a), you usually supply just the library instead of the object files. The static archive is a collection of .o files. During linking, the linker examines your unresolved symbol table and extracts only those .o files from the archive that define symbols needed by the executable. This can reduce binary size and allow separation of code. The library approach decouples compilation of the library from the main project.

Practical difference: If you add an object to an archive but no symbol in the final program uses it, that object will not be pulled in (i.e., not included) — whereas if you listed that object directly in $(OBJECTS), it would always be linked in.

Q2 — What is a git tag and why is it useful? Difference between a simple tag and annotated tag?

Short: A tag is a pointer to a specific commit used to mark releases. Annotated tags are full Git objects (with author, date, message, optionally GPG-signed). Lightweight tags are just a name pointing to a commit.

Detailed:

Usefulness: tags mark important points in history (releases, stable milestones). They make it easy to check out that exact code, and are used by release workflows and CI/CD systems.

Lightweight tag: git tag v1.0 — is just a name. No meta information (author/time/message). Equivalent to a branch pointer but static.

Annotated tag: git tag -a v1.0 -m "release notes" — stores tagger, timestamp, message. They are preferred for public releases because they record context and can be cryptographically signed.

When creating a Release on GitHub, annotated tags are preferred because they carry the release message and metadata.

Q3 — Purpose of a GitHub Release; significance of attaching binaries

Short: A Release is a GitHub UI construct built on top of a tag that packages code, release notes, and binary artifacts for distribution.

Detailed:

Releases provide a user-friendly way to publish stable versions of a project (with notes & assets). They are searchable, linkable, and allow users/grader to download compiled artifacts for quick evaluation.

Attaching binaries (e.g., bin/client) is important because:

The grader can run your compiled program without building (useful when they check many student submissions).

It demonstrates that your code builds successfully on your environment.

For large projects or where builds require special environment, attached binary avoids complex build steps for the consumer.

For shared libraries, attach .so / .a if required by the assignment so the grader can test multiple linking scenarios.


Q1. What is Position-Independent Code (-fPIC) and why required?

-fPIC generates machine code that uses relative addressing instead of absolute addresses.

Shared libraries may be loaded at different addresses in different processes. With PIC, the library can be mapped anywhere without modification.

Without PIC, the loader would need to rewrite instructions at runtime (slow and unsafe).

So -fPIC is fundamental for .so builds.

Q2. Why is client_dynamic smaller than client_static?

client_static embeds the library code inside itself (every function needed is copied in).

client_dynamic only has references to libmyutils.so. At runtime, the .so is loaded into memory and shared.

Therefore, dynamic executables are smaller and multiple processes can share the same .so in memory.

Q3. What is LD_LIBRARY_PATH? Why did we need it?

LD_LIBRARY_PATH is an environment variable telling the dynamic loader (ld-linux) where to search for shared libraries at runtime.

By default, loader searches system dirs like /usr/lib. Our libmyutils.so was in a custom ./lib/, so it wasn’t found.

Setting LD_LIBRARY_PATH=$(pwd)/lib added our project’s lib folder to the search path.

This demonstrates that the OS dynamic loader is responsible for locating .so files at program startup.
