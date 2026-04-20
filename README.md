# RV-Sparse-Challenge-Hamza

**Candidate:** Hamza Ahmad  
**Affiliation:** UET Lahore / Xcelerium  
**Challenge:** Efficient CSR Extraction and Sparse Matrix-Vector Multiplication (SpMV)

---

##  Project Overview

This repository contains a high-performance implementation of Sparse Matrix-Vector Multiplication (SpMV) optimized for environments with strict memory constraints. The implementation focuses on converting a dense row-major matrix into Compressed Sparse Row (CSR) format and subsequently performing the multiplication $y = Ax$.

### Key Features
- **Zero Dynamic Allocation:** The implementation strictly avoids `malloc`, `calloc`, or `free` at runtime, ensuring deterministic behavior and suitability for embedded systems or real-time RISC-V environments.
- **CSR Extraction:** Efficiently scans dense row-major matrices to extract non-zero elements into pre-allocated CSR buffers (`val`, `col_ind`, `row_ptr`).
- **Optimized SpMV Kernel:** Performs $y = Ax$ by leveraging the CSR structure to skip zero-value multiplications, significantly reducing compute cycles for sparse datasets.

---

##  Technical Details

### CSR Representation
The matrix is represented using three primary arrays:
1.  **`val`**: Stores the non-zero elements.
2.  **`col_ind`**: Stores the column index for each non-zero element.
3.  **`row_ptr`**: Stores the index in `val` where each row starts.

### SpMV Logic
The multiplication follows the standard CSR algorithm:
$$y[i] = \sum_{j=row\_ptr[i]}^{row\_ptr[i+1]-1} val[j] \times x[col\_ind[j]]$$

### Memory Management
To adhere to the challenge constraints:
- All buffers must be provided by the caller.
- Memory complexity is $O(NNZ)$ for storage and $O(N)$ for row pointers, where $NNZ$ is the number of non-zero elements and $N$ is the number of rows.

---

## How to Run

### Prerequisites
- GCC Compiler
- Math library (`-lm`)

### Compilation and Execution
Navigate to the project directory and run the following commands:

```bash
# Compile the challenge source code
gcc -lm -o run challenge.c

# Execute the binary
./run
