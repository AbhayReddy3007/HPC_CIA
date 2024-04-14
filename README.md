# Parllelisation of Matrix Multiplication
## Parllelism Implementation
Matrix multiplication can be parallelized using threads by dividing the workload among multiple threads, with each thread computing a portion of the resulting matrix. This involves partitioning the input matrices into smaller blocks or rows/columns, and assigning each thread to work on a separate block or set of rows/columns. Synchronization mechanisms ensure data consistency, enhancing performance and efficiency through thread-level parallelism on multi-core processors.

## Tabular Analysis of using Parllelism
![image](https://github.com/AbhayReddy3007/HPC_CIA/assets/116380040/450b8154-71f5-427b-a25a-f3e98b039ec1)

## Pictorial Analysis of using Parllelism
### Serial Vs Parallel work time for Different Population
![image](https://github.com/AbhayReddy3007/HPC_CIA/assets/116380040/a86beeab-933b-4d43-80ea-41681ca43e98)

### No. of Threads vs Time taken for 2500 samples
![image](https://github.com/AbhayReddy3007/HPC_CIA/assets/116380040/f24ea2ee-6102-45e5-92e7-1221f85358b8)

### Speed-up vs Population Size
![image](https://github.com/AbhayReddy3007/HPC_CIA/assets/116380040/d750e759-7dc3-40fe-8bbf-f340f55db702)

### No. of Samples vs Parllel Efficiency
![image](https://github.com/AbhayReddy3007/HPC_CIA/assets/116380040/e084fc93-bdbb-419d-8f89-73a392f9f2a6)
