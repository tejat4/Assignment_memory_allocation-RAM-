# Assignment_memory_allocation-RAM
Here’s a clean README.md you can directly use for your GitHub repository for this memory allocation assignment:

Simple Bare-Metal Memory Allocator
You are given 100 KB of simulated RAM.

You must implement two functions that mimic a simple bare-metal memory manager:
allocate(int size) → Allocates a block of memory of given size in bytes.
deallocate(int *ptr) → Frees a previously allocated block.


1. Rules:
Minimum allocation = 1 byte
Maximum allocation = 100 KB
Return pointer to allocated memory or NULL if not enough space
Freed memory should be reusable

2. Function Prototypes:
int* allocate(int size);       // size in bytes
void  deallocate(int *ptr);    // pointer to allocated memory


3. Sample Usage
int *mem[100];
mem[0] = allocate(128);     // 128 bytes
mem[1] = allocate(1024);    // 1 KB
mem[2] = allocate(4096);    // 4 KB
deallocate(mem[1]);         // free 1 KB block
mem[1] = allocate(512);     // reuse freed space


4. How It Works
Static memory array (memory[]) simulates RAM.
Block structure stores:
Start address
Size
Free/in-use status
Metadata table (blocks[]) tracks up to 100 allocations.

 Allocation:
1. First looks for reusable freed blocks.
2. If none found, allocates from the unused memory region.
Deallocation simply marks the block as free (no merging).

5. Features:
Fixed-size memory pool (100 KB)
Supports reuse of freed blocks
No OS dependency (bare-metal style)
Simple and easy to understand

6. Limitations
No block merging → fragmentation can occur.
Max 100 allocations at a time.
No memory alignment guarantees.

7. Example Output
Simulation complete.


---

Do you want me to also add a memory allocation diagram in this README so it looks more visual and GitHub-friendly?
It would help explain the allocator’s working at a glance.
