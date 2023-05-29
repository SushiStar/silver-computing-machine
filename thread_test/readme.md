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


## Launching A New Thread
The performance gain might not be as large as expected; There's an inherent overhead
associated with launching a thread, because the OS has to allocate the associated kernel
resources and stack space and then add new thread to the scheduler, all of which takes
time. If the task being run on the thread is completed quickly, the time taken by the task
may be dwarfed by the overhead of launching the thread, possibly making the overall
performance of the application worse than if the task had been executed directly by the
spawning thread.

Furthermore, threads are a limited resource. If you have too many threads running at once,
this consumes OS resources and may take the system as a whole run slower. Not only that,
but using too many threads can exhaust the available memory or address space for a
process, because each thread requires a separate stack space.

Finally, the more threads you have running, the more context switching the operating
system has to do. Each context switch takes time that could be spent doing useful work, so
at some point, adding an extra thread will reduce the overall application performance
rather than increase it.
