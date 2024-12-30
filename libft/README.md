# libft + ft_printf + get_next_line + deprecated + personal functions

## Overview

The first student project of 42, a library of many (maybe TOO many) C99 implementations and some really useful string and linked lists managing functions. Those are exactly 43 functions, bonus included.

Also, aside from what must be done to get the project validated, I made some functions I found a little useful for further Cursus projects and other personal stuff. They started to be done for fun and killing time but they ended to be, as I said, useful in an unexpected moment. They respect the 42 norme and no forbidden functions in use (just malloc and free).

Basically, libft must be completed with the asked functions, but after that, it is highly recommended to incorporate more that will be needed later, starting from their already included expansions, **ft_printf** and **get_next_line**.

As being my first student project, don't expect to see much skill and readable code, expect the worst possible in fact. I got to rearrange some functions after validating the project, but ft_split for example needs to be redone because it is a complete disaster (BUT IT WORKS!). Moreover I didn't take much things seriously, such as variable names (char *mander 🙂).

---

## Skills acquired

- Develop a deeper knowledge of C programming by reimplementing the original standard library functions, and thus understanding their innners.
- Learn to write modular, reusable, and optimized code.
- Gain experience with Makefiles for compiling projects.
- Building a strong base for memory-safe programming practices.
- Build a strong foundation for future projects by creating reliable utility functions.
- Exposure to linked list implementation and manipulation.
---
## Contents

### 1. **Mandatory Functions (Detailed)**

The mandatory functions in **Libft** are divided into two parts: standard C library replacements and additional utilities. Here’s a more detailed explanation of each function and its purpose:

---

#### **Part 1: Standard C Library Functions**

These functions replicate common functions from the C standard library. Implementing them helps you understand their inner workings and provides tools for future projects where standard library functions might be restricted.

- **Memory Manipulation:**
  - `memset`:  
    Fills a block of memory with a specific value. Useful for initializing arrays or buffers.  
    Prototype:  
    ```c
    void *ft_memset(void *s, int c, size_t n);
    ```

  - `bzero`:  
    Similar to `memset` but specifically sets all bytes in a memory block to `0`.  
    Prototype:  
    ```c
    void ft_bzero(void *s, size_t n);
    ```

  - `memcpy`:  
    Copies `n` bytes from a source memory block to a destination. Overlap is not handled.  
    Prototype:  
    ```c
    void *ft_memcpy(void *dst, const void *src, size_t n);
    ```

  - `memmove`:  
    Similar to `memcpy` but handles overlapping memory blocks safely.  
    Prototype:  
    ```c
    void *ft_memmove(void *dst, const void *src, size_t len);
    ```

  - `memchr`:  
    Searches for the first occurrence of a character in a memory block.  
    Prototype:  
    ```c
    void *ft_memchr(const void *s, int c, size_t n);
    ```

  - `memcmp`:  
    Compares two memory blocks byte by byte and returns the difference.  
    Prototype:  
    ```c
    int ft_memcmp(const void *s1, const void *s2, size_t n);
    ```

- **String Manipulation:**
  - `strlen`:  
    Calculates the length of a null-terminated string.  
    Prototype:  
    ```c
    size_t ft_strlen(const char *s);
    ```

  - `strdup`:  
    Allocates and duplicates a string.  
    Prototype:  
    ```c
    char *ft_strdup(const char *s1);
    ```

  - `strcpy`:  
    Copies a string, including the null terminator, to another.  
    Prototype:  
    ```c
    char *ft_strcpy(char *dst, const char *src);
    ```

  - `strncmp`:  
    Compares at most `n` characters between two strings.  
    Prototype:  
    ```c
    int ft_strncmp(const char *s1, const char *s2, size_t n);
    ```

  - `strchr` / `strrchr`:  
    Finds the first/last occurrence of a character in a string.  
    Prototype:  
    ```c
    char *ft_strchr(const char *s, int c);
    char *ft_strrchr(const char *s, int c);
    ```
  - `strnstr`:  
    Locates a substring in a string, searching at most `len` characters.  
    Prototype:  
    ```c
    char *ft_strnstr(const char *haystack, const char *needle, size_t len);
    ```

- **Conversion and Utilities:**
  - `atoi`:  
    Converts a string to an integer.  
    Prototype:  
    ```c
    int ft_atoi(const char *str);
    ```

  - `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`:  
    Checks for alphabetic characters, digits, alphanumeric, ASCII, or printable characters.  
    Prototype examples:  
    ```c
    int ft_isalpha(int c);
    int ft_isdigit(int c);
    ```

  - `toupper` / `tolower`:  
    Converts a character to uppercase/lowercase.  
    Prototype:  
    ```c
    int ft_toupper(int c);
    int ft_tolower(int c);
    ```

---

#### **Part 2: Additional Utility Functions**

These utility functions are not part of the standard C library but are essential for various programming tasks.

- **Memory Allocation and String Creation:**
  - `calloc`:  
    Allocates and initializes memory to zero for an array.  
    Prototype:  
    ```c
    void *ft_calloc(size_t count, size_t size);
    ```

  - `substr`:  
    Extracts a substring from a string.  
    Prototype:  
    ```c
    char *ft_substr(char const *s, unsigned int start, size_t len);
    ```

  - `strjoin`:  
    Concatenates two strings into a new allocated string.  
    Prototype:  
    ```c
    char *ft_strjoin(char const *s1, char const *s2);
    ```

  - `split`:  
    Splits a string into an array of substrings based on a delimiter.  
    Prototype:  
    ```c
    char **ft_split(char const *s, char c);
    ```

  - `itoa`:  
    Converts an integer to a string.  
    Prototype:  
    ```c
    char *ft_itoa(int n);
    ```

- **Function Pointers and Iterators:**
  - `strmapi`:  
    Applies a function to each character of a string and creates a new string with the results.  
    Prototype:  
    ```c
    char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
    ```

  - `striteri`:  
    Applies a function to each character of a string in place.  
    Prototype:  
    ```c
    void ft_striteri(char *s, void (*f)(unsigned int, char*));
    ```

  - `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`:  
    Outputs characters, strings, or numbers to a file descriptor.  
    Prototypes:  
    ```c
    void ft_putchar_fd(char c, int fd);
    void ft_putstr_fd(char *s, int fd);
    ```

---

### 2. **Bonus Functions**

The bonus part introduces the implementation of **singly linked lists**. These functions enable the creation, manipulation, and traversal of linked list data structures:

- **Creation:**
  - `lstnew`: Creates a new list node.

- **Addition:**
  - `lstadd_front`: Adds a node to the beginning of the list.
  - `lstadd_back`: Adds a node to the end of the list.

- **Traversal and Counting:**
  - `lstsize`: Counts the number of nodes.
  - `lstlast`: Retrieves the last node.

- **Manipulation:**
  - `lstdelone`: Deletes a node and frees its content.
  - `lstclear`: Deletes all nodes and frees the list.
  - `lstiter`: Iterates over the list and applies a function to each node.

- **Transformation:**
  - `lstmap`: Creates a new list by applying a function to each node of an existing list.

---

### 3. Personal functions: Optional but strong additions

During the project, some additional utility functions were implemented to facilitate future work. These may include:

- Advanced string manipulation.
- Memory allocation helpers.
- Additional linked list functionalities.

These functions are not required but add value to the library, demonstrating a deeper understanding of C programming.

In my case, I added a lot of string / array creation and managing, debug messages, and file descriptor related:

- **Debugging and Output Utilities:**
  - `ft_msg`, `ft_err_msg`: Print messages to standard output or standard error.
  ```c
    void	ft_msg(char *str);
    void	ft_err_msg(char	*str);
  ```
  - `ft_putmatrix`, `ft_put_triarr`: Display arrays or multidimensional arrays for debugging.

- **File and Descriptor Management:**
  - `ft_file_to_str`, `ft_file_to_arr`: Read file contents as strings or arrays of strings.
  - `ft_putfd`, Print file descriptor content.
  - `ft_putfd_fd`: Duplicate file descriptor content.

- **String and Array Manipulation:**
  - `ft_merge`: Combine strings from an array with a customizable separator.
  - `ft_arrjoin`, `ft_arrdup`: Array joining or duplicating utilities.

- **Advanced Utilities:**
  - `ft_ftoa`: Convert floats to strings.
  - `ft_chrdel`: Remove specific characters from strings.
  - `ft_realloc`: Dynamically resize memory allocations safely.

---

## Compilation

The project includes a `Makefile` for compiling the library into a static `.a` file. It supports the following commands:

```bash
make        # Compiles the mandatory functions into libft.a
make bonus  # Compiles both mandatory and bonus functions into libft.a
make clean  # Removes all object files
make fclean # Removes object files and the compiled library
make re     # Recompiles the entire project from scratch
```

To include `libft` in any program, compile it linking it using `-L` and `-lft` flags.

---

## Usage

### Including Libft in a Project

1. Compile `libft` using the `make` command to generate `libft.a`.
2. Include the `libft.h` header file in your source files:

   ```c
   #include "libft.h"
   ```

3. Link `libft.a` during compilation:

   ```bash
   gcc main.c -L/path/to/libft -lft -o program_name
   ```

---

## Testing

Libft is rigorously tested to ensure functionality and reliability. Various testing tools and custom test files were used, including:

- [Francinette](https://github.com/xicodomingues/francinette)
- Custom test suites for edge cases and performance testing.



---


Libft is more than just a project; it’s a stepping stone to mastering C programming. By implementing these fundamental functions, we gain a profound understanding of how things work under the hood and set the stage for tackling more complex projects in 42 School