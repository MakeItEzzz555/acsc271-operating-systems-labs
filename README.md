# ACSC271 Operating Systems Labs

C/C++ operating-systems labs with introductory I/O, Windows mailslots, POSIX processes and pthreads.

## Contents

| Folder / file | Topic | Technologies |
| --- | --- | --- |
| `Lab-03` | Hello-world/minimum-input C programs and a C++ command-line parameter viewer. | C / C++ |
| `Lab-04` | Computes integer sum and real geometric mean and writes a result file. | C / C++ |
| `Lab-06/ReadMailSlot` | Windows IPC receiver using mailslot APIs, paired with writer. | C / C++ |
| `Lab-06/WriteMailSlot` | Windows IPC sender using mailslot APIs, paired with reader. | C / C++ |
| `Lab-07` | Threaded sum, process/thread memory example, concurrent printing, and parameterized pthread workers. | C / C++ |

Each folder is an independent exercise or project. Original names, source, dependency versions and required project configuration are preserved.

## Getting Started

Lab-03 and Lab-04 contain independent C/C++ files. Compile each with a suitable C/C++ compiler. Lab-06 contains paired Windows mailslot Visual Studio projects; start the reader before the writer. Lab-07 requires POSIX processes and pthreads; compile each file separately with `cc -pthread`. Some concurrent demonstrations intentionally continue indefinitely.

## Validation

The two Windows Lab-06 mailslot programs compiled with MSVC 14.44. The remaining introductory/POSIX labs were not compiled in this Windows archival check. Programs were not executed; process, thread and IPC behavior remains unvalidated.

## Notes

Original implementation is preserved. Build outputs, dependencies, machine-specific IDE state, backups, submission documents and private runtime data are excluded. No license has been inferred for the original work.
