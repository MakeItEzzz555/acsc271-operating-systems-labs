# ACSC271 Operating Systems Labs

> This coursework has been consolidated into [MakeItEzzz555/frederick-university-coursework](https://github.com/MakeItEzzz555/frederick-university-coursework). This repository is archived to preserve its history and URLs.

C/C++ operating-systems labs with introductory I/O, Windows mailslots, POSIX processes and pthreads.

## Contents

| Folder | Course/Lab | Topic | Language/Platform |
| --- | --- | --- | --- |
| `Lab-03` | Existing archived exercises | Hello-world/minimum-input C programs and a C++ command-line parameter viewer. | C / C++ |
| `Lab-04` | Existing archived exercises | Computes integer sum and real geometric mean and writes a result file. | C / C++ |
| `Lab-06/ReadMailSlot` | Existing archived exercises | Windows IPC receiver using mailslot APIs, paired with writer. | C / C++ |
| `Lab-06/WriteMailSlot` | Existing archived exercises | Windows IPC sender using mailslot APIs, paired with reader. | C / C++ |
| `Lab-07` | Existing archived exercises | Threaded sum, process/thread memory example, concurrent printing, and parameterized pthread workers. | C / C++ |
| `acsc372-system-programming/lab6` | Additional Mac/USB coursework | See detailed contents below | C / POSIX |
| `acsc372-system-programming/lab7` | Additional Mac/USB coursework | See detailed contents below | C / POSIX |

Each folder is an independent exercise or project. Original names, source, dependency versions and required project configuration are preserved.

## Getting Started

Lab-03 and Lab-04 contain independent C/C++ files. Compile each with a suitable C/C++ compiler. Lab-06 contains paired Windows mailslot Visual Studio projects; start the reader before the writer. Lab-07 requires POSIX processes and pthreads; compile each file separately with `cc -pthread`. Some concurrent demonstrations intentionally continue indefinitely.

## Validation

The two Windows Lab-06 mailslot programs compiled with MSVC 14.44. The remaining introductory/POSIX labs were not compiled in this Windows archival check. Programs were not executed; process, thread and IPC behavior remains unvalidated.

## Notes

Original implementation is preserved. Build outputs, dependencies, machine-specific IDE state, backups, submission documents and private runtime data are excluded. No license has been inferred for the original work.

## Additional ACSC372 system programming

The Mac archival additions are Frederick ACSC372 labs, grouped here alongside the existing POSIX/operating-systems exercises. The course identity remains explicit in their subdirectory.

| Folder | Course/Lab | Topic | Language/Platform |
| --- | --- | --- | --- |
| `acsc372-system-programming/lab6` | ACSC372 / Lab 6 | Sparse files, seek/read slices, overwrite and restore a byte | C / POSIX |
| `acsc372-system-programming/lab7` | ACSC372 / Lab 7 | fork/pipe/wait synchronization, environment display and child processes | C / POSIX |

Compile one file at a time with a POSIX C compiler, for example `cc -std=c11 Lab6Ex1.c -o lab6ex1` from the lab6 folder, then run `./lab6ex1`. The included `input.txt` is needed by Lab6Ex1 and Lab6Ex2. Lab6Ex2 temporarily changes a byte and restores it on the normal success path; use a disposable copy when experimenting. Filehole creates/truncates `file_with_a_hole.txt` in the current folder. Lab7 needs POSIX fork, pipes and wait, so it is not a native Windows build. `echoall.c` prints the process environment, which may contain local credentials; use a clean environment for experiments and keep its output private.

Mac validation: all six added C files passed Clang syntax checks. Process and file behavior was not run. Existing Windows-source and project files are preserved.
