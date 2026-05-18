# Data Races in Concurrent Programming

A **data race** occurs when two or more threads access the same memory location **at the same time**, and **at least one** of those threads writes to it. Without synchronization, the final result becomes unpredictable.

---

## Anatomy of a Data Race

Even a simple increment operation is not atomic. It consists of three steps:

1. **Read** – load the current value from memory  
2. **Modify** – compute a new value  
3. **Write** – store the updated value back to memory  

If two threads interleave these steps, the final result becomes corrupted.

---

## Example Scenario

Imagine two threads updating a shared shopping list:

- The list starts with **1 clove of garlic**  
- Thread A wants to add **2 cloves**  
- Thread B wants to add **5 cloves**  

Due to scheduling interleaving, the final result may incorrectly become **3 cloves** instead of the expected **8**.

This happens because both threads perform:


on the same memory location at overlapping times.

---

## Why Data Races Are Hard to Debug

Data races are notoriously difficult to diagnose because:

- Thread scheduling is unpredictable  
- The bug may appear only under certain timing conditions  
- The program may behave correctly most of the time  
- Adding debug prints can change timing and hide the bug  

---

## Key Takeaways

- Data races occur when multiple threads access and modify shared data without synchronization  
- They lead to corrupted state and nondeterministic behavior  
- Recognizing potential data races is essential for writing reliable concurrent programs  
- Thread scheduling randomness makes these bugs intermittent and difficult to reproduce  

---

# Concurrent Access and Critical Sections

When multiple threads read and write shared data, the program must protect the **critical section** — the part of the code that accesses the shared resource.

---

## Critical Sections

A **critical section** is any block of code that:

- Reads or writes shared data  
- Must not be executed by more than one thread at a time  

Example: incrementing a shared counter involves:


These three steps must be treated as **one uninterrupted action**.

---

## Mutex (Mutual Exclusion)

A **mutex** ensures that only one thread can enter a critical section at a time.

A typical mutex usage pattern:

1. Acquire the lock  
2. Execute the critical section  
3. Release the lock  

If another thread already holds the lock, the requesting thread **blocks** until the lock becomes available.

---

## Atomic Operations

Lock acquisition is an **atomic operation**:

- It cannot be interrupted  
- It appears instantaneous to other threads  
- It prevents two threads from entering the critical section simultaneously  

---

## Thread Blocking

If a thread attempts to acquire a lock that is already held:

- It **waits** (blocks)  
- The scheduler may switch to another runnable thread  
- Once the lock is released, the blocked thread becomes runnable again  

---

## Best Practices

- Keep critical sections **as short as possible**  
- Perform non‑critical work **outside** the locked region  
- Minimize contention by reducing shared state  
- Use atomic operations when appropriate  
- Avoid unnecessary locking to prevent bottlenecks  

---

This document provides the conceptual foundation for understanding **mutexes**, **locks**, and **synchronization primitives** used throughout concurrent programming.
