# Evaluating Parallel Performance

Evaluating parallel performance requires understanding how problem size, processor count, and algorithm structure affect execution time. This document summarizes key concepts including weak and strong scaling, throughput, latency, speedup, Amdahl’s Law, and efficiency.

---

# Weak Scaling vs. Strong Scaling

## Weak Scaling — Increasing Problem Size
Weak scaling measures how well a system handles **larger workloads** when more processors are added.

- Work per processor stays **constant**
- Total problem size **increases**
- Goal: complete a proportionally larger problem in the **same amount of time**

### Example
- One worker decorates **10 cupcakes** in an hour  
- Two workers can decorate **20 cupcakes** in the same hour  

The system scales to larger problems without increasing runtime.

---

## Strong Scaling — Solving the Same Problem Faster
Strong scaling measures how much faster a **fixed-size** problem can be solved using more processors.

- Problem size stays **constant**
- Processor count increases
- Goal: reduce execution time

### Example
- One worker decorates **10 cupcakes** in 60 minutes  
- Two workers finish in **~30 minutes**  

The problem doesn’t grow — it just completes faster.

---

# Key Metrics in Parallel Computing

## Throughput
Number of tasks completed per unit time.

- 1 worker → 10 cupcakes/hour  
- 3 workers → 30 cupcakes/hour  

Throughput increases with more processors.

---

## Latency
Time to complete **one** task from start to finish.

- Decorating one cupcake still takes **six minutes**, regardless of worker count  

Latency is per‑task and does not improve with parallelism.

---

## Speedup
Measures how much faster a parallel program runs compared to sequential execution.



\[
\text{Speedup} = \frac{T_\text{sequential}}{T_\text{parallel}}
\]



### Example
- Sequential: 60 minutes  
- Parallel (2 workers): 30 minutes  
- Speedup = 60 / 30 = **2**

---

# Limitations of Parallelization

Real programs contain both:

- **Parallelizable** sections  
- **Sequential** sections (cannot be parallelized)

Sequential portions limit maximum speedup and cause diminishing returns as more processors are added.

---

# Amdahl’s Law

Amdahl’s Law estimates the **maximum possible speedup** of a parallel program based on the fraction that can be parallelized.



\[
\text{Speedup} = \frac{1}{(1 - P) + \frac{P}{S}}
\]



Where:

- **P** = parallelizable portion  
- **S** = speedup of the parallel portion (often equal to number of processors)

### Example (95% parallelizable)
- 2 processors → speedup ≈ **1.9**  
- 3 processors → **2.7**  
- 4 processors → **3.5**  
- 1000 processors → **19.6**  
- 1,000,000 processors → **just under 20**

The **5% sequential** portion caps the speedup.

---

# Limits on Parallel Effectiveness

Maximum speedup depends heavily on the parallelizable fraction:

| Parallelizable Portion | Max Speedup |
|------------------------|-------------|
| 90%                    | 10×         |
| 75%                    | 4×          |
| 50%                    | 2×          |

Even small sequential parts dramatically limit performance.

---

# Decision-Making in Parallel Programming

Amdahl’s Law helps determine:

- Whether parallelization is worthwhile  
- Whether overhead outweighs benefits  
- Whether the program is parallelizable enough to justify multiple processors  

Parallelizing everything is **not** always beneficial.

---

# Measuring Speedup and Efficiency

Amdahl’s Law predicts theoretical speedup.  
Actual performance requires **empirical measurement**.

---

## Calculating Speedup



\[
\text{Speedup} = \frac{T_\text{sequential}}{T_\text{parallel}}
\]



- Speedup > 1 → parallelization helped  
- Speedup < 1 → sequential is better  

### Example (Ripley & Hicks)
- Sequential: 25 seconds  
- Parallel: 17 seconds  
- Speedup = 25 / 17 ≈ **1.47**

---

## Calculating Efficiency



\[
\text{Efficiency} = \frac{\text{Speedup}}{\text{Number of processors}}
\]



### Example
- Speedup = 1.47  
- Processors = 2  
- Efficiency = 1.47 / 2 = **73.5%**

With more processors:

- Speedup = 2.2  
- Processors = 8  
- Efficiency = 2.2 / 8 = **27.5%**

Efficiency drops as overhead increases.

---

# Benchmarking Best Practices

To obtain reliable performance measurements:

- Limit other running programs  
- Average multiple runs  
- Warm up the system (especially with JIT environments)  
- Run once before timing to stabilize cache behavior  

---

# Summary

- **Weak scaling** → solve bigger problems with more processors  
- **Strong scaling** → solve the same problem faster  
- **Throughput** increases with more processors  
- **Latency** per task stays constant  
- **Speedup** measures parallel benefit  
- **Amdahl’s Law** shows limits of parallelization  
- **Efficiency** measures processor utilization  
- Real-world performance requires careful measurement and benchmarking  
