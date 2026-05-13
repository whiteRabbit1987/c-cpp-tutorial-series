# Parallel Computing Overview

Parallel computing allows multiple processors to work simultaneously on different parts of a task. It improves performance, increases throughput, and enables solving problems too large or slow for a single processor.

---

# 1. Sequential vs. Parallel Computing

## Sequential Computing
- Executes one instruction at a time on a single processor.
- Performance is limited by processor speed.
- Example: One cook making a salad → 3 minutes.

## Parallel Computing
- Breaks work into independent parts executed simultaneously.
- Uses multiple processors to reduce total completion time.
- Example: Two cooks preparing a salad → 2 minutes.

---

# 2. Advantages of Parallel Computing
- Faster completion of large or complex tasks.
- Higher throughput: more work done in the same time.
- Enables solving problems too large for a single CPU.
- Time savings often justify specialized hardware.

---

# 3. Challenges of Parallel Computing
- More complex programming and coordination.
- Adding processors does not guarantee linear speedup.
- Synchronization and communication overhead can reduce performance.
- Dependent tasks may cause waiting and bottlenecks.

---

# 4. Real‑World Applications
- Web search engines processing millions of queries per second.
- Scientific computing, simulations, AI/ML, graphics, finance.
- Industries where time saved directly reduces cost.

---

# 5. Flynn’s Taxonomy (Four Classes of Computer Architecture)

Parallel hardware is categorized by instruction streams and data streams.

## SISD — Single Instruction, Single Data
- Traditional sequential machine.
- One instruction stream, one data stream.

## SIMD — Single Instruction, Multiple Data
- Many processors execute the same instruction on different data.
- Ideal for repetitive operations on large datasets.
- Used heavily in GPUs and image processing.

## MISD — Multiple Instruction, Single Data
- Multiple processors run different instructions on the same data.
- Rarely used in practice.

## MIMD — Multiple Instruction, Multiple Data
- Each processor executes different instructions on different data.
- Most common architecture today (multicore CPUs, clusters, supercomputers).

### MIMD Subtypes
**SPMD — Single Program, Multiple Data**  
- Many processors run the same program on different data.
- Can diverge via conditional logic.
- Most common parallel programming model.

**MPMD — Multiple Program, Multiple Data**  
- Different processors run different programs.
- Often uses a manager/worker structure.
- Useful for specialized distributed systems.

---

# 6. Shared vs. Distributed Memory

Memory organization strongly affects performance. Even with many processors, slow memory access can become the bottleneck.

## Shared Memory Architecture
All processors share a global address space.

### UMA — Uniform Memory Access
- Equal access time for all processors.
- Used in SMP and modern multicore CPUs.

### NUMA — Non‑Uniform Memory Access
- Access time varies depending on memory region.
- Built by linking multiple SMP systems.
- All memory is still globally accessible.

### Cache Considerations
- Each core has its own cache.
- Cache coherency must be maintained.
- Hardware handles coherency in multicore CPUs.

### Pros / Cons
**Pros:** Easy to program, simple data sharing  
**Cons:** Limited scalability, contention for shared memory

---

## Distributed Memory Architecture
Each processor has its own local memory; no global address space.

### Characteristics
- Memory changes are not visible across nodes.
- Programmers must explicitly send/receive data.

### Pros / Cons
**Pros:** Highly scalable, memory grows with processors, cost‑effective  
**Cons:** Communication is harder and must be manually managed

---

# Key Takeaways
- Parallel computing provides major performance gains when tasks can be split.
- Requires careful design to avoid synchronization and communication bottlenecks.
- Essential for modern large‑scale, data‑intensive applications.

