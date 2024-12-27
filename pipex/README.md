
# pipex

### Description

The target on completing this project is understanding the use of FD pipes, processes with fork(), and command execution with execve().

The program takes an argument containing a path to a file whose content will be used as input information. A second argument is a command to be executed taking the input. A third command will execute a second command taking the first command's output as input. The final output will be flushed into a file named as the fourth and last argument.

The bonus version can take any desired number of commands. If the first argument is `here_doc`, the input for the first command will be prompted on the standard input until a line containing the delimiter is given. The delimiter is entered as the second argument.

### Usage

This program is compiled with a Makefile located in the pipex directory. Type `make` or `make all` to compile the regular version or `make bonus` to compile the bonus version. <br>

Then, in both cases, a `pipex` executable will be generated. Execution is as follows:

- **Regular version**:
  ```bash
  ./pipex [input file] [cmd1] [cmd2] [output file]
  ```

- **Bonus version**:
  ```bash
  ./pipex [input file | here_doc] [delimiter if here_doc is used] [cmd1] [cmd2] ... [output file]
  ```

---

### Examples of Execution

#### Regular Version
Suppose we have a file named `input.txt` containing some text. Here are examples of execution:

1. **Example**:  
   ```bash
   ./pipex input.txt "cat -e" "wc -l" output.txt
   ```
   **What it emulates**:  
   ```bash
   < input.txt cat -e | wc -l > output.txt
   ```

2. **Example**:  
   ```bash
   ./pipex input.txt "grep 'hello'" "sort" output.txt
   ```
   **What it emulates**:  
   ```bash
   < input.txt grep 'hello' | sort > output.txt
   ```

3. **Example**:  
   ```bash
   ./pipex input.txt "awk '{print $1}'" "uniq" output.txt
   ```
   **What it emulates**:  
   ```bash
   < input.txt awk '{print $1}' | uniq > output.txt
   ```

#### Bonus Version
Suppose we have `input.txt` and use the bonus version for chaining multiple commands:

1. **Example**:  
   ```bash
   ./pipex input.txt "cat -e" "grep 'pattern'" "sort -r" output.txt
   ```
   **What it emulates**:  
   ```bash
   < input.txt cat -e | grep 'pattern' | sort -r > output.txt
   ```

2. **Example** (with `here_doc`):  
   ```bash
   ./pipex here_doc "END" "cat" "wc -c" output.txt
   ```
   Input prompt:
   ```
   > This is a test
   > END
   ```
   **What it emulates**:  
   ```bash
   cat << END | cat | wc -c > output.txt
   This is a test
   END
   ```

3. **Example**:  
   ```bash
   ./pipex input.txt "head -n 5" "tail -n 3" "tr a-z A-Z" output.txt
   ```
   **What it emulates**:  
   ```bash
   < input.txt head -n 5 | tail -n 3 | tr a-z A-Z > output.txt
   ```

---

### Notes
- Input files must exist and be readable. Output files will be created if they do not exist or overwritten if they do.
- For the `here_doc` feature, the delimiter must exactly match the input text to terminate the input stream.
- Ensure all commands (`cmd1`, `cmd2`, etc.) are valid and available in the system's `$PATH`.
