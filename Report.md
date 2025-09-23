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









🔹 REPORT.md Answers (Part-3)

Q1. Compare the Makefile from Part-2 and Part-3. What are the key differences?

In Part-2, the Makefile linked all object files directly into the executable ($(TARGET): $(OBJECTS)).

In Part-3, utility object files are first archived into a static library (libmyutils.a), and then the main program is linked against the library using -L and -lmyutils.

New variables: LIBDIR, LIB, and a new rule for building .a.

This separation makes the build modular and scalable — multiple programs can reuse the same library without recompiling the utilities.

Q2. Purpose of ar and ranlib

ar creates an archive of object files (.o) → .a.

ar rcs means:

r: replace or add files,

c: create if needed,

s: write an index (symbol table).

ranlib updates the archive’s symbol index. Some systems need this for the linker to quickly resolve symbols. Even if ar rcs already writes the index, ranlib ensures portability.

Q3. When you run nm on client_static, are the symbols present? What does that mean?

Yes, symbols like mystrlen show up in nm bin/client_static.

This means the function code was copied from the static library into the executable.

It proves that static linking embeds library code inside the binary, unlike dynamic linking (where the binary just has references and the code is loaded at runtime from .so).