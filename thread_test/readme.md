# Threads

## Concurrency with Multiple Processes
The first way to make use of concurrency within an application is to divide the
application into multiple, separate, single-threaded processes that are run that the same
time. These separate processes can then pass messages to each other through all the normal
inter-process communication channels (signals, sockets, files, pipes, and so on). One
downside is that such communication between processes is either complicated to setup or
slow, or both, because operating systems typically provide a lot of protection between
processes to avoid one process accidentally modifying data belonging to another process.

The alternative approach to concurrency is to run multiple threads in a single process.
Threads are much like light-weight processes: each thread runs independently of others,
and each may run a different sequence of instructions. But all threads in a process share
the same address space, and most of the data can be accessed directly from all threads --
global variables remain global, and pointers or references to objects or data can be
passed around among threads.
