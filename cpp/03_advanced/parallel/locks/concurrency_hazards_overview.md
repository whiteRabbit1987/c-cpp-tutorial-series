# Concurrency Hazards: Deadlock, Abandoned Locks, Starvation, and Livelock

This document explains several critical liveness and synchronization hazards in concurrent programming.  
The Dining Philosophers analogy is used only as a teaching tool to illustrate how threads compete for shared resources.

---

# Deadlock: Competing for Multiple Locks

The Dining Philosophers scenario demonstrates how deadlock occurs:

- Two philosophers (threads) alternate between thinking and eating.
- Chopsticks represent mutexes protecting access to shared sushi.
- Each philosopher must acquire **two locks** before eating.
- A deadlock occurs when each philosopher holds one lock and waits forever for the other.

This models real multithreaded programs where threads must acquire multiple resources.

## What Deadlock Is
Deadlock is a state where:

- Each thread waits for another thread to take action.
- No thread can proceed.
- The system makes **zero progress**.

Deadlock typically arises when all four conditions hold:

1. Mutual exclusion  
2. Hold and wait  
3. No preemption  
4. Circular wait  

---

# Liveness

**Liveness** is the property that ensures a concurrent program continues to make progress.

A system with good liveness guarantees:

- Threads eventually enter critical sections.
- Work continues even if threads must take turns.

Deadlock destroys liveness entirely.

---

# Real‑World Example: Banking Transfers

A banking system may require locking both the **sender** and **receiver** accounts during a transfer.

If two threads attempt opposite transfers:

- Thread A locks Account 1  
- Thread B locks Account 2  
- Each waits for the other lock  

This mirrors the Dining Philosophers deadlock pattern.

---

# Preventing Deadlock: Lock Ordering

One solution:

- All threads agree to acquire locks in the **same order**.
- This prevents circular wait.
- At least one thread can always complete its critical section.

Lock ordering is a widely used real‑world strategy.

---

# Abandoned Locks

An **abandoned lock** occurs when:

- A thread acquires a lock  
- Then exits or crashes **without releasing it**  
- Other threads wait forever for a lock that will never be released  

Analogy:

- Barron takes a chopstick (lock)  
- Leaves unexpectedly  
- Olivia waits indefinitely  

This shows that deadlocks can arise not only from competition but also from **unexpected thread termination**.

---

# Starvation

**Starvation** occurs when a thread is continually denied access to a resource it needs.

Causes include:

- A “greedy” thread repeatedly acquiring a lock  
- OS scheduling favoring certain threads  
- Priority systems that disadvantage lower‑priority threads  

Effects:

- Some threads progress  
- Others never do  
- System fairness and performance degrade  

Starvation becomes more likely with:

- Many threads  
- Priority scheduling  
- Long‑held locks  

---

# Livelock

A **livelock** occurs when threads actively respond to each other but still make no progress.

Analogy:

- Two polite philosophers repeatedly offer the last piece of sushi to each other  
- Both remain active  
- Neither eats  
- No forward progress occurs  

## Characteristics

- Threads are busy  
- Threads keep changing state  
- The system never completes  

## Causes

- Over‑aggressive deadlock recovery  
- Multiple threads attempting to resolve a conflict simultaneously  

## Prevention

- Ensure only one thread takes corrective action  
- Use priority rules or random backoff  
- Avoid symmetrical conflict‑resolution logic  

---

# Summary

This module covers the major concurrency hazards:

- **Deadlock** — threads wait forever  
- **Abandoned lock** — lock never released  
- **Starvation** — thread never gets resources  
- **Livelock** — threads keep reacting but never progress  

Understanding these hazards is essential for designing correct, fair, and efficient concurrent systems.
