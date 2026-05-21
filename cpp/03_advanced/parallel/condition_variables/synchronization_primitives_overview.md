# Synchronization Primitives: Condition Variables, Monitors, and Semaphores

This document explains higher-level synchronization mechanisms that extend the capabilities of basic locks and mutexes. These tools enable threads to coordinate, wait for conditions, and manage shared resources more efficiently.

---

# Limitations of Locks and Mutexes

Locks and mutexes ensure **mutual exclusion**, preventing multiple threads from accessing shared data simultaneously.  
However, they do **not** provide mechanisms for:

- Waiting for specific conditions  
- Signaling other threads  
- Coordinating multi-step operations  

This leads to inefficient patterns such as busy-waiting or manual polling.

---

# Condition Variables

A **condition variable** allows threads to wait for a condition to become true.  
They work together with a mutex to form a more expressive synchronization tool.

## Purpose

- Avoids busy-waiting  
- Allows threads to sleep until notified  
- Enables efficient producer–consumer coordination  

## Core Operations

### **Wait**
- Releases the mutex  
- Puts the thread to sleep  
- Re-acquires the mutex when awakened  

### **Signal (notify_one)**
- Wakes **one** waiting thread  

### **Broadcast (notify_all)**
- Wakes **all** waiting threads  

---

# Monitors

A **monitor** combines:

- A mutex  
- One or more condition variables  
- Shared data  
- Protected procedures  

### Analogy (Barron & Olivia)

- The monitor is a **room** containing shared data and protected functions  
- The mutex is the **lock on the door**  
- Condition variables are **waiting rooms** outside the monitor  

Monitors ensure mutual exclusion while allowing threads to wait and be notified.

---

# Practical Use Case: Shared Buffer

A typical producer–consumer queue uses:

- **One mutex** → protects the buffer  
- **Two condition variables**:  
  - `not_full` → producers wait when full  
  - `not_empty` → consumers wait when empty  

This avoids busy-waiting and ensures efficient synchronization.

---

# Semaphores

A **semaphore** controls access to a shared resource using a counter.

Unlike mutexes:

- Semaphores can allow **multiple threads** to access a resource  
- Any thread may release a semaphore  

## How Semaphores Work

- When the counter is **positive**, a thread may acquire it (counter decrements)  
- When the counter is **zero**, threads block  
- Releasing increments the counter and may wake waiting threads  

---

# Types of Semaphores

## Counting Semaphore
- Counter can be 0, 1, 2, 3, …  
- Represents a pool of identical resources  
- Example: a **two-port phone charger**  
  - Two ports → semaphore count = 2  
  - Each device plugged in decrements the count  
  - When count = 0, additional devices must wait  

## Binary Semaphore
- Counter is either **0** or **1**  
- Similar to a mutex, but **any thread** may release it  
- Useful for signaling between threads  

---

# Advantages of Semaphores

- Allow multiple threads to access shared resources  
- Can act as signaling mechanisms  
- Useful for resource pools  
- More flexible than simple mutexes  

---

# Summary

- **Locks** provide mutual exclusion but no signaling  
- **Condition variables** allow threads to wait and notify  
- **Monitors** combine mutexes + condition variables into a structured tool  
- **Semaphores** manage access to shared resources and support multi-threaded coordination  

These primitives enable more expressive and efficient synchronization than mutexes alone.
