# Threads and Processes Overview

## Processes
- A process is an executing instance of a program.
- Contains its own code, data, and execution state.
- Each process has an independent address space.
- Modern systems can run hundreds of processes simultaneously.

## Threads
- Threads are smaller execution units inside a process.
- Represent independent paths of execution.
- Share the same address space and resources of their parent process.
- Managed directly by the operating system.

## Processes vs. Threads
- Processes are isolated; threads share memory within the same process.
- Threads communicate easily; processes require special IPC mechanisms.
- Threads are lightweight: cheaper to create, destroy, and switch between.
- Process switching is slower due to separate memory spaces.

## Analogy: Cooking in a Kitchen
- A **process** is a kitchen (address space).
- **Threads** are cooks working on different tasks in the same kitchen.
- Different **processes** are separate kitchens preparing different meals.

## Choosing Threads or Processes
- Threads are preferred when tasks share data and need low overhead.
- Processes are used when isolation, security, or fault‑tolerance is required.
- Implementation details vary across OSes and languages.

---

# Concurrency vs. Parallelism

## Concurrency
- A program is structured into independent tasks that can overlap in time.
- Does not require multiple processors.
- A single CPU can switch rapidly between tasks, creating the illusion of simultaneity.

## Parallelism
- Requires multiple processors or cores.
- Tasks truly execute at the same time.
- Enables significant speedups for computation‑heavy workloads.

## Analogy: Salad Preparation
- Two tasks (chopping tomatoes, slicing cucumbers) are **concurrent**.
- With one knife (single core), tasks take turns.
- With two knives (two cores), tasks run **in parallel**.

## Forms of Parallel Hardware
- Multicore CPUs in desktops and mobile devices.
- GPUs with many specialized cores.
- Clusters distributing work across multiple machines.

## Key Distinctions
- Concurrency = dealing with many things at once (structure).
- Parallelism = doing many things at once (execution).
- Concurrency enables parallelism but does not guarantee it.

## Use Cases
- Concurrency: GUIs, I/O‑bound tasks, device drivers.
- Parallelism: matrix math, simulations, large computations.

---

# Operating System Scheduling

## Role of the Scheduler
- Manages how processes and threads share CPU time.
- Loads new processes into memory and places them in the ready queue.
- Cycles through ready tasks, giving each a time slice.
- On multiprocessor systems, distributes tasks across all CPUs.

## Process Execution States
- A process may run, block for I/O, or be swapped out after its time slice.
- The OS ensures fairness and responsiveness.

## Context Switching
- Saves the state of one task and loads another.
- Enables multitasking but introduces overhead.
- Schedulers balance switch frequency with performance.

## Scheduling Algorithms
- Vary by OS and system goals.
- Some maximize throughput; others minimize latency.
- Preemptive scheduling can interrupt tasks; non‑preemptive cannot.

## Key Takeaways
- Scheduling is handled by the OS; programmers cannot rely on execution order.
- Programs must be written to behave correctly regardless of scheduling.

---

# Thread Lifecycle and States

## Thread Creation
- A new process starts with a single main thread.
- Threads can spawn child threads, which may spawn their own children.
- The main thread typically finishes last.

## Thread States
**NEW**  
- Thread created but not yet running.

**RUNNABLE**  
- Eligible to run; may be swapped in and out by the scheduler.

**BLOCKED**  
- Waiting for a resource or event; not using CPU time.

**TERMINATED**  
- Finished execution or aborted; notifies parent thread.

## Key Concepts
- Threads can create children to perform parallel tasks.
- `join()` allows a parent to wait for a child to finish.
- Terminology varies across languages.
- Efficient thread management is essential for concurrency and parallelism.

---

# Background Tasks and Daemon Threads

## Background Services
- Threads often run periodic or continuous tasks (e.g., garbage collection).
- These threads operate independently of the main program.

## Garbage Collection Example
- Runs concurrently with the main thread.
- Frees unused memory automatically.
- Represents a long‑running background service.

## Normal (Non‑Daemon) Threads
- Prevent the program from exiting until they finish.
- Long‑running tasks may keep the process alive indefinitely.

## Daemon Threads
- Background threads that do **not** prevent program termination.
- Must be explicitly marked as daemon threads.
- When the main thread exits, daemon threads are terminated abruptly.

## Cautions
- Abrupt termination is safe for tasks like garbage collection.
- Unsafe for I/O tasks (e.g., writing files), which may corrupt data.
- Use daemon threads only when abrupt termination is acceptable.

