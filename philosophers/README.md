
# philosophers

### Description

The goal of this project is to understand the basics of multithreading by solving the dining philosophers problem. Knowledge acquired through it is:
- The creation and management of threads using the `pthread` library.
- Synchronization using mutexes to avoid race conditions.
- Basic time management and delays using `gettimeofday()` for precise timing.

This project requires implementing a simulation of the dining philosophers problem, where multiple philosophers sit at a table, alternating between eating, thinking, and sleeping, without causing deadlocks or data races.

### Usage

This program is compiled with a Makefile located in the philosophers directory. Type `make` or `make all` to compile the project. <br>

Once compiled, a `philosophers` executable will be generated. Execution is as follows:

```bash
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

- **Arguments**:
  1. `number_of_philosophers`: The number of philosophers sitting at the table.
  2. `time_to_die`: Time (in milliseconds) a philosopher can go without eating before dying.
  3. `time_to_eat`: Time (in milliseconds) it takes for a philosopher to eat.
  4. `time_to_sleep`: Time (in milliseconds) a philosopher spends sleeping.
  5. `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation ends when all philosophers have eaten at least this many times.

If the arguments are invalid or an error occurs, the program will print an error message.

---

### Examples of Execution

1. **Example**:  
   ```bash
   ./philosophers 5 800 200 200
   ```
   **What it does**:  
   Simulates 5 philosophers sitting at the table with the following parameters:
   - Each philosopher has 800ms before starving.
   - Eating takes 200ms.
   - Sleeping takes 200ms.

2. **Example**:  
   ```bash
   ./philosophers 4 410 200 200 5
   ```
   **What it does**:  
   Simulates 4 philosophers with the same timing parameters as above, but the simulation ends once each philosopher has eaten 5 times.

---

### Notes

- **Synchronization**: Mutexes are used to protect shared resources like forks and the console output.
- **Precision**: Time is measured in milliseconds using `gettimeofday()` for accurate delay handling.
- **Philosopher Death**: The program will print a message when a philosopher dies, and the simulation will stop.

Ensure you test your program with various input values to validate that it behaves as expected in all scenarios, including edge cases like:
- Very small `time_to_die` values, ensuring philosophers die immediately if not eating.
- Simulations with only one philosopher, where starvation should occur since they cannot eat.
