# get_next_line

## Overview

**get_next_line** is a project that focuses on reading a file descriptor line by line. This function is designed to handle various edge cases while being memory-safe and efficient.

The project strengthens understanding of:

- File descriptors and their manipulation.
- Dynamic memory allocation and management.
- Handling of static variables for persistent state across function calls.

Important: **get_next_line**, as well as **ft_printf**, is already included and integrated in my **[libft](https://github.com/prando-a/42Cursus/tree/master/libft)** project.

---

## Features

- Reads from a file descriptor and returns one line at a time.
- Handles files, standard input (`stdin`), or even pipes.
- Supports varying `BUFFER_SIZE` values, dynamically adjusting memory usage.
- Manages memory effectively to avoid leaks or buffer overflows.
- Stops at `\n` (newline) or EOF.

---

## Function Prototype

```c
char *get_next_line(int fd);
```

- **`fd`**: The file descriptor to read from.
- **Return Value**:
  - The next line from the file descriptor, including the newline character if present.
  - `NULL` if there's nothing else to read or if an error occurs.

---

## Mandatory Part

The function must:

1. Read from a file descriptor until a complete line is found or EOF is reached.
2. Return the read line as a null-terminated string.
3. Handle multiple consecutive calls for continuous line-by-line reading.

---

## Bonus Features

The bonus part of the project includes:

1. **Handling Multiple File Descriptors**:
   - Each file descriptor maintains its own buffer and state.
   - This allows reading from multiple sources simultaneously without data interference.

2. **Improved Performance**:
   - Efficient memory handling ensures optimal performance for large files or streams.

3. **Robust Error Handling**:
   - The function gracefully manages invalid file descriptors and unexpected errors during reading.

---

## Example Usage

### Simple File Reading

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## Example Bonus Usage: Multiple File Descriptors

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line1, *line2;

    if (fd1 < 0 || fd2 < 0)
        return (1);
    while ((line1 = get_next_line(fd1)) != NULL || 
           (line2 = get_next_line(fd2)) != NULL)
    {
        if (line1)
        {
            printf("File 1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("File 2: %s", line2);
            free(line2);
        }
    }
    close(fd1);
    close(fd2);
    return (0);
}
```
Both of these are main fuction examples to compile and test the get_next_line function. Any of these examples are referred below as `main.c`. Continue reading below for testing and compilation.


---

## Important Notes

- **Static Variables**:
  - The function uses static variables to retain the state between successive calls, allowing partial lines to be stored until completed.

- **BUFFER_SIZE**:
  - The `BUFFER_SIZE` macro determines how many bytes are read at a time. It is defaultly set as 1024 on the header file but can be re-defined at compile-time for the program to work (see below).

- **Memory Management**:
  - Always free the returned string after use to prevent memory leaks.

---

## Testing

### Example File

`example.txt`:
```
Hello, World!
This is a second line.
And this is the third line.
```

### Output

For the above file, the program will print:
```
Hello, World!
This is a second line.
And this is the third line.
```

### Test with Standard Input

Run the program without a file and type directly into the terminal:
```bash
./a.out
```

Type a few lines and press `Ctrl+D` to signal EOF.

### Test with Multiple File Descriptors (Bonus)

Create two files (`file1.txt` and `file2.txt`) and use the bonus example provided above. The output will interleave lines from both files.

---

## Compilation

To compile normally with the `main.c` example above:

```bash
gcc get_next_line.c get_next_line_utils.c main.c
```

To compile with a specific buffer size:

```bash
gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c
```

To compile the bonus (as previously stated, the -D flag can be added to state a different buffer size):

```bash
gcc get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

---

