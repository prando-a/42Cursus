# 42Cursus - common-core
Every project done so far at 42School in Málaga. This made the mastering of coding out of a true life experience, of which I must be grateful. <br>
Projects are mostly related to from basic to advanced C / C++ programming. Some projects have strong influence on bash language, environment and system-managing. Every project includes a README.md fully documenting it (Work in progress as of 2024/12/29). [Skills acquired are in this section](#skills-learnt)


## Summary

### [libft + extra functions](https://github.com/prando-a/42Cursus/tree/master/libft)
My first library, our C Swiss knife. Every mandatory + bonus functions are included, memory safe and passed with strict tests of [paco](https://github.com/xicodomingues/francinette). ft_printf and get_next_line are included along some functions from the deprecated previous libft version and some more useful extra memory and parsing functions used for further C projects.

### [ft_printf](https://github.com/prando-a/42Cursus/tree/master/ft_printf)
Simple printf implementation done in the easy way, composed of a lot of writes. Funny to do, very easy to understand, useful enough for further C projects.

### [get_next_line](https://github.com/prando-a/42Cursus/tree/master/get_next_line)
Reads a file descriptor and returns a line (read until a newline char or EOF is found), used to read files or the standard input. Easy to understand, memory safe, just a delight to read.

### [push_swap](https://github.com/prando-a/42Cursus/tree/master/push_swap)
Allegedly efficient integer sorting program using two stacks (linked lists) with limited elements movements to make development hard. [Radix](https://en.wikipedia.org/wiki/Radix_sort) was used as the main sorting algorithm.
Frankly very easy to read and very light source code.

### [so_long](https://github.com/prando-a/42Cursus/tree/master/so_long)
First contact with the [**MLX42**](https://github.com/codam-coding-college/MLX42) library (stylized GLFW and OpenGL weird mix) to make a 2D game about collecting a certain amount of elements and then unlocking the exit where game finishes. By passing some general parsing rules, any map can be proccessed.

### [pipex](https://github.com/prando-a/42Cursus/tree/master/pipex)
Introduction to command execution and use of pipes in C. This program takes info from an input file, and executes commands automatically finding their correct path, each of them communicated by a pipe, until the last command which final output will be flushed into an output file.

### [minishell](https://github.com/prando-a/42Cursus/tree/master/minishell)
First duo project (with [@pepe587](https://github.com/pepe587) as the master of parsing and signal management), and this one was a massive challenge. Implementation of a bash shell with essential features, such as a bunch of incorporated built-ins, use of system and custom environment variables, execution of undefined number of commands communicated by pipes, read from and write into files, input history and custom signal actions. Everything with a solid front-end and an exquisite memory and file descriptors management. 
Uses [readline()](https://tiswww.case.edu/php/chet/readline/rltop.html) libraries.

### [philosophers](https://github.com/prando-a/42Cursus/tree/master/philosophers)
A simple implementation of the (in)famous [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) with use of threads as philos and mutexes as forks. A curious yet strange introduction to thread management with a philosophical perspective.

### [cub3D](https://github.com/prando-a/42Cursus/tree/master/cub3D)
The latest C project, duo-baked (Yes, again with the master [@pepe587](https://github.com/pepe587)).
Second and likely last experience with the [**MLX42**](https://github.com/codam-coding-college/MLX42) library but now about doing a first-person maze engine using [ray casting](https://en.wikipedia.org/wiki/Ray_casting). My comrade used his own algorithm and made the entire animation and wall-collision systems. Maybe the most epic project we had the honor to complete. cub3D can parse any valid map which must also contain paths to any desired texture and floor and ceiling colors.

### [cpp-modules](https://github.com/prando-a/42Cursus/tree/master/cpp_modules)
First C++ assignments, a series of short exercises regarding every basic of this language. 10 mini-projects, arranged on two batches (00 to 04 and 05 to 09). Concepts introduced are
OOP, classes, polymorphism, inheritance, operators overload, data abstraction, exceptions, advanced castings, templates, algorithms and containers (vectors, lists, stacks, maps...). basically everything mandatory for a C learner to understand and deal with its mentioned successor.

### [inception](https://github.com/prando-a/42Cursus/tree/master/inception)
This project regards the use of [docker-compose](https://docs.docker.com/compose/) to create and link three containers to generate a server environment. One container must have a database service installed (mariaDB), another one for Wordpress and finally one more for a webserver (Nginx). Each container must be created with an image made from scratch manually installing requirements with Dockerfiles and scripts.

### [ft_irc](https://github.com/prando-a/42Cursus/tree/master/ft_irc)
The only major C++ project in common-core, this time about building a IRC Chat server setting its own socket, bind the connection and listen through a given port on arguments. The server has to handle multiple client sockets connection with [poll()](https://pubs.opengroup.org/onlinepubs/009696799/functions/poll.html) or [select()](https://man7.org/linux/man-pages/man2/select.2.html) and then give an IRC chat service including channels with a bunch of modes activated, permission and access managing among users, follow the protocol for regular IRC clients (used [Hexchat](https://hexchat.github.io/) as reference) and allowing connection via netcat). [@pepe587](https://github.com/pepe587) contributed to the project building most server commands.

### [ft_transcendence]() (Currently in development)
Last common-core project. A clone of the classic Pong game has to be implemented with its corresponding backend, frontend, users database and auth system modules using a docker-compose. There is certain freedom on choosing the language for every module, and a bunch of base-mandatory parts. More info and code will be available when it is complete. Our team is working hard on it.

----------------------------------------------
----------------------------------------------

## Skills learnt

The areas covered by the projects include:

1. **Algorithms and Data Structures** ():  
   - Learning to design and optimize efficient algorithms.  
   - Handling and applying various data structures (lists, stacks, queues, trees, graphs, etc.).

2. **C/C++ Programming**:  
   - Mastery of low-level programming in C and high-level programming in C++.  
   - Direct manipulation of memory, pointers, structures, and control flow.

3. **Low-Level Software Development**:  
   - Programming focused on direct interaction with the machine and the operating system.  
   - In-depth knowledge of memory management, process handling, threads, and synchronization (mutexes, semaphores).

4. **Operating Systems and Linux Administration** ([pipex](https://github.com/prando-a/42Cursus/tree/master/pipex), [minishell](https://github.com/prando-a/42Cursus/tree/master/minishell)):  
   - Deepening knowledge of how operating systems work, especially in Linux environments.  
   - Managing processes, memory, files, and devices.  
   - Using terminal tools, scripting, user management, permissions, and networking.

5. **Computer Networking** ([ft_irc](https://github.com/prando-a/42Cursus/tree/master/ft_irc), ):  
   - Learning how computers communicate over networks.  
   - Using protocols and tools such as sockets, TCP/IP, UDP, HTTP, etc.

6. **Concurrent Programming** ([philosophers](https://github.com/prando-a/42Cursus/tree/master/philosophers), [so_long](https://github.com/prando-a/42Cursus/tree/master/so_long), [cub3D](https://github.com/prando-a/42Cursus/tree/master/cub3D)):  
   - Creating multi-threaded and multi-tasking applications. 
   - Implementing synchronization and managing shared resources.

7. **Testing and Debugging** ([libft library](https://github.com/prando-a/42Cursus/tree/master/libft)):  
   - Developing good practices for testing, debugging, and optimizing code.  
   - Using tools such as gdb, Valgrind, and others.

8. **Game Development** ([so_long](https://github.com/prando-a/42Cursus/tree/master/so_long), [cub3D](https://github.com/prando-a/42Cursus/tree/master/cub3D)):  
   - In projects like **cub3d**, students can experience graphical programming, raycasting, game engines, and real-time user input handling.

9. **Low-Level Hardware Interaction**:  
   - In some projects, students work with hardware-level manipulation, such as controlling input/output devices.

Each of these fields is developed through practical projects that simulate real-world situations, preparing students to face complex challenges in the professional world.