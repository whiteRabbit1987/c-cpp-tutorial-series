# Reentrant (Recursive) Mutexes

A **reentrant mutex** is a type of mutex that allows the **same thread** to lock it multiple times without causing a deadlock. It internally tracks how many times it has been locked by its owning thread, and it must be unlocked the same number of times before another thread can acquire it.

## Key Characteristics

- A thread may lock the mutex multiple times.
- The mutex keeps an internal lock count.
- The thread must unlock it the same number of times.
- Also known as **recursive mutexes** or **recursive locks**.

## Reentrant vs Standard Mutexes

- **Standard mutexes** will deadlock if a thread tries to lock a mutex it already owns.
- **Reentrant mutexes** prevent this by allowing repeated locking by the same thread.

## Use Cases

### Nested Function Calls
Useful when a function that acquires a lock calls another function that also acquires the same lock.

### Recursive Functions
Essential when a recursive function must lock a shared resource on each call.

## Advantages and Considerations

- Simplifies integration of locks into existing code.
- Reduces the need to track lock ownership manually.
- Some developers argue that reentrant mutexes can hide poor design and prefer refactoring to avoid nested locking.

---

# Try-Lock

A **try-lock** is a non-blocking attempt to acquire a mutex. Instead of waiting, the thread immediately receives success or failure.

## How Try-Lock Works

- If the mutex is free → lock is acquired → returns **true**.
- If the mutex is held → returns **false** immediately.
- Allows threads to continue doing useful work instead of blocking.

## Analogies

- Two threads (e.g., Olivia and Barron) attempt to update a shared shopping list.
- A pencil represents the mutex.
- With try-lock, if the pencil is in use, the thread simply moves on and tries again later.
- Another analogy: checking a bathroom at a party — if it's occupied, you return to the party instead of waiting outside.

## Advantages

- Prevents unnecessary blocking.
- Useful when threads have multiple tasks and can switch to another job.
- Improves efficiency and resource utilization.

---

# Reader-Writer Locks (Shared Mutexes)

A **reader-writer lock** allows multiple threads to read shared data simultaneously, while still ensuring exclusive access for writers.

## Lock Modes

- **Shared (READ) mode** → multiple readers allowed.
- **Exclusive (WRITE) mode** → only one writer allowed.

## How They Work

- Many threads may hold a read lock at the same time.
- Only one thread may hold a write lock.
- Write locks block all other readers and writers.
- Write locks cannot be acquired while any read locks are active.

## Use Cases

- Workloads with **many more reads than writes**.
- Database systems.
- Caches and shared configuration structures.

## Considerations

- More complex than standard mutexes.
- Higher overhead.
- Reader/writer preference varies by implementation (some favor readers, others writers).

## Best Practices

- Use reader-writer locks when reads dominate.
- Use a standard mutex when writes are frequent.
- Consider application-specific access patterns before choosing a lock type.
