# push-swap

### Description

The objective of this project is to sort a stack of integers using a limited set of operations and the least number of moves possible. The program consists of two stacks, `a` and `b`, and it must sort the stack `a` in ascending order using predefined operations.

This project is an excellent opportunity to learn:
- **Algorithm optimization**: Implementing sorting algorithms with a focus on minimizing operations.
- [**Radix sort**](https://en.wikipedia.org/wiki/Radix_sort): Using a non-comparison-based sorting algorithm to achieve efficient performance on large stacks.
- **Data structures**: Managing stacks and understanding their manipulation through operations. In this case, linked lists were used.

### Allowed Operations

The following operations can be performed on the stacks:
- `sa`: Swap the first two elements of stack `a`.
- `sb`: Swap the first two elements of stack `b`.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the top element from stack `b` to stack `a`.
- `pb`: Push the top element from stack `a` to stack `b`.
- `ra`: Rotate stack `a` upwards (first element becomes last).
- `rb`: Rotate stack `b` upwards.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Reverse rotate stack `a` (last element becomes first).
- `rrb`: Reverse rotate stack `b`.
- `rrr`: Perform `rra` and `rrb` simultaneously.

### Usage

This program is compiled with a Makefile located in the `push-swap` directory. Type `make` or `make all` to compile the project. <br>

Once compiled, a `push_swap` executable will be generated. Execution is as follows:

`./push_swap [list of integers]`

* Pro test tip: You can use the `shuf`command to generate unique numbers and count movements this way:

1. Store numbers in a shell variable:
`ARG=$(shuf -i 1-100 -n 10 | tr '\n' '`
This creates a variable containing (as the example says) 10 numbers in a range from 1 to 100 separated by spaces with `tr` since shuf does by newlines.

2. Variable can now be used as arguments for push_swap
`./push_swap $ARG` 
3. The output of every movement can be redirected to be counted `wc`.
`./push_swap $ARG | wc -l`
