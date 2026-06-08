# Computational Graphs, Asynchronous Tasks, Thread Pools, Futures, and Divide‑and‑Conquer

This document summarizes several core concepts in parallel programming: computational graphs, asynchronous execution, thread pools, futures, and divide‑and‑conquer algorithms. These tools help structure parallel work, manage concurrency efficiently, and reason about performance.

---

# Computational Graphs

A **computational graph** models the relationships between program steps.  
It visualizes which tasks:

- Must occur in a specific order  
- Can run in parallel  
- Depend on the results of other tasks  

## Directed Acyclic Graphs (DAGs)

A computational graph is typically a **DAG**:

- **Nodes** → tasks or units of work  
- **Edges** → dependencies or required ordering  

### Example (Salad‑Making)

- Chop lettuce  
- Chop tomatoes  
- Mix ingredients  
- Add dressing  

Chopping lettuce and tomatoes can occur **asynchronously**.  
A **spawn** node begins parallel execution.  
A **sync** node ensures both chopping tasks finish before mixing.

## Key Terminology

- **Spawn / fork** — start parallel tasks  
- **Sync / join** — wait for parallel tasks to finish  
- **Asynchronous** — tasks that can occur in any order  
- **Critical path** — longest chain of dependent tasks  

## Analyzing Parallel Potential

- **Work** — total time on a single processor (sum of all tasks)  
- **Span** — shortest possible time with infinite processors (critical path)  
- **Ideal parallelism** — `work / span`  

This ratio indicates the maximum theoretical speedup.

---

# Challenges with Creating Many Threads

Creating a new thread for every small task is inefficient:

- Thread creation has overhead (time + memory)  
- Too many threads cause context switching  
- Performance can degrade instead of improving  

Analogy:  
Ripley and Hicks chop vegetables in parallel.  
Adding more vegetables → spawning more threads → overhead increases.

---

# Thread Pools

A **thread pool** maintains a small set of reusable worker threads.

### Benefits

- Avoids thread creation overhead  
- Reuses existing threads  
- Improves responsiveness  
- Ideal when tasks are short‑lived  

Submitting tasks to a pool is like adding items to a shared to‑do list.

---

# Futures

A **future** represents the result of an asynchronous operation.

- Acts as a placeholder for a value not yet computed  
- Allows the caller to continue working  
- The future becomes “ready” when the task completes  

### Analogy

Ripley asks Hicks to count vegetables in the pantry:

- Hicks gives Ripley an “IOU” (future)  
- Ripley continues working  
- Hicks returns with the result  
- Ripley uses the resolved future to decide what to do next  

## Working with Futures

- Futures are **read‑only**  
- They may not contain a result immediately  
- A thread may need to **wait** for the future to be fulfilled  
- “Resolving” a future means writing the result into it  

---

# Divide‑and‑Conquer Algorithms

Divide‑and‑conquer breaks a problem into smaller subproblems.

### Structure

1. **Divide** — split the problem into smaller pieces  
2. **Conquer** — solve each piece (often recursively)  
3. **Combine** — merge results  

### Example (Shopping Receipts)

- Sequential: iterate through all receipts  
- Parallel: split receipts among processors, sum in parallel, combine totals  

## Recursive Division

- Continue subdividing until reaching a **base case**  
- Base case may be a single element or a threshold size  
- Combine results as recursion unwinds  

Often implemented with:

```cpp
if (small_enough) return direct_solution;
else return combine(left_subproblem, right_subproblem);
