# 42Cursus - common-core
Every project done so far at 42School in Málaga. This made the mastering of coding out of a true life experience, of which I must be grateful.

## Summary

### [libft + extra functions](https://github.com/prando-a/42Cursus/tree/master/libft)
My first library, our C Swiss knife. Some functions are a mess to read, but I will try to improve them later. Every mandatory + bonus functions are included, memory safe and passed with strict tests of [paco](https://github.com/xicodomingues/francinette). There are some useful extra memory and parsing functions used for further C projects.

### [ft_printf](https://github.com/prando-a/42Cursus/tree/master/ft_printf)
Simple printf implementation done in the easy way, composed of lotta writes. Funny to do, very easy to understand, useful enough for further C projects.

### [get_next_line](https://github.com/prando-a/42Cursus/tree/master/get_next_line)
Reads a file descriptor and returns a line (read until a newline char or EOF is found), used to read files or the standard input. Easy to understand, memory safe, just a delight to read. :)

### [push_swap](https://github.com/prando-a/42Cursus/tree/master/push_swap)
Allegedly efficient integer sorting program using two stacks (linked lists) with limited elements movements to make development hard. Radix was used as the main sorting algorithm. Frankly very easy to read and very light source code.

### [so_long](https://github.com/prando-a/42Cursus/tree/master/so_long)
First contact with the MLX42 library (stylized GLFW and OpenGL weird mix) to make a 2D game about collecting a certain amount of elements and then unlocking the exit where game finishes. By passing some general parsing rules, any map can be proccessed.

### [pipex](https://github.com/prando-a/42Cursus/tree/master/pipex)
Introduction to command execution and use of pipes in C. This program takes info from an input file, and executes commands automatically finding their correct path, each of them communicated by a pipe, until the last command which final output will be flushed into an output file.

### [minishell](https://github.com/prando-a/42Cursus/tree/master/minishell)
First duo project (with @pepe587 as the master of parsing and signal management), and this one was a massive challenge. Implementation of a bash shell with essential features, such as a bunch of incorporated built-ins, use of system and custom environment variables, execution of undefined commands communicated by pipes, read and write into files, input history and custom signal actions. Everything with a solid front-end and an exquisite memory and file descriptors management. Uses readline() libraries.

### [philosophers](https://github.com/prando-a/42Cursus/tree/master/philososphers)
A simple implementation of the (in)famous [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) with use of threads as philos and mutexes as forks. A weird introduction to thread management with a philosophical persepctive.

### [cub3D](https://github.com/prando-a/42Cursus/tree/master/cub3D)
The latest C project, duo-baked (Yes, again with the master @pepe587).
Second and likely last experience with the MLX42 library but now with doing a first-person maze engine using [ray casting](https://en.wikipedia.org/wiki/Ray_casting). My comrade used his own algorithm and made the entire animation and wall-collision systems. Maybe the most epic project we had the honor to complete. cub3D can read any valid map which must also contain paths to any desired texture and floor and ceiling colors.
