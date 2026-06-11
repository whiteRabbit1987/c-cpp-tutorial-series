# Designing Parallel Programs

Designing an effective parallel program involves four major stages: **partitioning**, **communication**, **agglomeration**, and **mapping**. Each stage refines the structure of the program to improve performance, scalability, and maintainability.

---

# Partitioning: Breaking Down the Problem

Partitioning divides a problem into discrete chunks of work that can be executed in parallel. At this stage, the goal is **maximum decomposition**, without worrying about processor count or hardware limitations.

Two complementary approaches guide this process:

---

## Domain (Data) Decomposition

Domain decomposition focuses on dividing the **data** into partitions, with computation assigned to each partition.

- Works best when data can be split into equal‑sized chunks  
- Common in numerical simulations, image processing, and grid‑based problems  
- Example: Decorating a tray of cupcakes by dividing them into blocks or assigning every other cupcake cyclically  

Domain decomposition is the foundation of many parallel algorithms.

---

## Functional Decomposition

Functional decomposition divides the **work** into separate tasks, each performing a different part of the computation.

- Data requirements are secondary  
- Useful when tasks represent distinct stages of a pipeline  
- Example: Breaking cupcake production into mixing, baking, frosting, decorating  

Functional and domain decomposition are often combined to reveal optimization opportunities that may not be visible from a single perspective.

---

# Communication Between Parallel Tasks

Once a problem is partitioned, tasks must coordinate and exchange data. Communication patterns depend on the relationships between tasks.

---

## Types of Task Communication

### 1. Independent Tasks
Tasks require no shared data.

- Example: Frosting cupcakes independently  
- No communication required  

### 2. Interdependent Tasks
Tasks depend on information from others.

- Example: Decorating cupcakes in a rainbow pattern, where each task needs neighbor colors  

---

## Communication Structures

### Point‑to‑Point Communication
Direct communication between specific tasks.

- Suitable when each task interacts with only a few neighbors  
- Involves sender (producer) and receiver (consumer) roles  

### Collective Communication
Communication involving a group of tasks.

- Broadcast (one‑to‑many)  
- Scatter/gather (distribute/collect data)  

### Centralized Management
A single task coordinates many workers.

- Simple to implement  
- Can become a bottleneck  
- Divide‑and‑conquer strategies help distribute load  

---

## Communication Factors to Consider

### Synchronous vs. Asynchronous
- **Synchronous (blocking)** — tasks wait for communication to complete  
- **Asynchronous (non‑blocking)** — tasks continue working while communication occurs  

### Performance Considerations
- **Processing overhead** — time spent communicating vs. computing  
- **Latency** — time for a message to travel  
- **Bandwidth** — amount of data transferable per unit time  

### Context Matters
- On a single machine: latency/bandwidth are less critical  
- On distributed systems: communication dominates performance  

---

# Agglomeration

Agglomeration refines the initial partitioning by combining tasks to reduce overhead and improve efficiency.

---

## Granularity

### Fine‑Grained Parallelism
- Many small tasks  
- **Pros:** Excellent load balancing  
- **Cons:** High communication overhead  

### Coarse‑Grained Parallelism
- Few large tasks  
- **Pros:** Low communication overhead  
- **Cons:** Potential load imbalance  

### Medium‑Grained Parallelism
- Balanced approach  
- Often the most efficient for general‑purpose systems  

---

## Demonstration

Ripley and Hicks frost 12 cupcakes:

- Initially: 12 tasks → **34 communication events**  
- After agglomeration: 2 tasks (6 cupcakes each) → **2 communication events**  
- Each communication now carries more information, but total overhead is drastically reduced  

---

## Recommendations

- Avoid hard‑coding the number of tasks  
- Use compile‑time or runtime parameters to control granularity  
- Design programs to adapt to available processors  

---

# Mapping in Parallel Design

Mapping assigns tasks to specific processors or hardware units.

Mapping is unnecessary for:

- Single‑processor systems  
- Systems with automatic scheduling (e.g., thread pools)  

Mapping is essential for:

- Distributed systems  
- Specialized hardware (clusters, GPUs, accelerators)  

---

## Goals of Mapping

### Increasing Concurrency
Place tasks that can run simultaneously on different processors.

### Improving Locality
Place frequently communicating tasks on the same processor to reduce communication cost.

These goals often conflict, requiring careful trade‑offs.

---

## Challenges and Considerations

- Dynamic workloads may require **dynamic load balancing**  
- Mapping strategies depend heavily on hardware topology  
- Domain decomposition and agglomeration techniques often guide mapping decisions  

---

# Summary

- **Partitioning** breaks the problem into tasks  
- **Communication** defines how tasks exchange data  
- **Agglomeration** balances granularity and overhead  
- **Mapping** assigns tasks to processors for optimal performance  

Together, these stages form a structured approach to designing efficient, scalable parallel programs.
