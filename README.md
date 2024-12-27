# 42Cursus - common-core
Every project done so far at 42School in Málaga. This made the mastering of coding out of a true life experience, of which I must be grateful.

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
First contact with the MLX42 library (stylized GLFW and OpenGL weird mix) to make a 2D game about collecting a certain amount of elements and then unlocking the exit where game finishes. By passing some general parsing rules, any map can be proccessed.

### [pipex](https://github.com/prando-a/42Cursus/tree/master/pipex)
Introduction to command execution and use of pipes in C. This program takes info from an input file, and executes commands automatically finding their correct path, each of them communicated by a pipe, until the last command which final output will be flushed into an output file.

### [minishell](https://github.com/prando-a/42Cursus/tree/master/minishell)
First duo project (with [@pepe587](https://github.com/pepe587) as the master of parsing and signal management), and this one was a massive challenge. Implementation of a bash shell with essential features, such as a bunch of incorporated built-ins, use of system and custom environment variables, execution of undefined number of commands communicated by pipes, read from and write into files, input history and custom signal actions. Everything with a solid front-end and an exquisite memory and file descriptors management. 
Uses [readline()](https://tiswww.case.edu/php/chet/readline/rltop.html) libraries.

### [philosophers](https://github.com/prando-a/42Cursus/tree/master/philososphers)
A simple implementation of the (in)famous [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) with use of threads as philos and mutexes as forks. A curious yet strange introduction to thread management with a philosophical perspective.

### [cub3D](https://github.com/prando-a/42Cursus/tree/master/cub3D)
The latest C project, duo-baked (Yes, again with the master [@pepe587](https://github.com/pepe587)).
Second and likely last experience with the MLX42 library but now about doing a first-person maze engine using [ray casting](https://en.wikipedia.org/wiki/Ray_casting). My comrade used his own algorithm and made the entire animation and wall-collision systems. Maybe the most epic project we had the honor to complete. cub3D can parse any valid map which must also contain paths to any desired texture and floor and ceiling colors.

### [cpp-modules](https://github.com/prando-a/42Cursus/tree/master/cpp_modules)
First C++ assignments, a series of short exercises regarding every basic of this language. 10 mini-projects, arranged on two batches (00 to 04 and 05 to 09). Concepts introduced are
OOP, classes, polymorphism, inheritance, operators overload, data abstraction, exceptions, advanced castings, templates, algorithms and containers (vectors, lists, stacks, maps...). basically everything mandatory for a C learner to understand and deal with its mentioned successor.

### [inception](https://github.com/prando-a/42Cursus/tree/master/inception)
This project regards the use of [docker-compose](https://docs.docker.com/compose/) to create and link three containers to generate a server environment. One container must have a database service installed (mariaDB), another one for Wordpress and finally one more for a webserver (Nginx). Each container must be created with an image made from scratch manually installing requirements with Dockerfiles and scripts.

### [ft_irc](https://github.com/prando-a/42Cursus/tree/master/ft_irc)
The only major C++ project in common-core, this time about building a IRC Chat server setting its own socket, bind the connection and listen through a given port on arguments. The server has to handle multiple client sockets connection with [poll()](https://pubs.opengroup.org/onlinepubs/009696799/functions/poll.html) or [select()](https://man7.org/linux/man-pages/man2/select.2.html) and then give an IRC chat service including channels with a bunch of modes activated, permission and access managing among users, follow the protocol for regular IRC clients (used [Hexchat](https://hexchat.github.io/) as reference) and allowing connection via netcat. [@pepe587](https://github.com/pepe587)) contributed to the project building most server commands.

### [ft_transcendence]() (Currently in development)
Last common-core project. A clone of the classic Pong game has to be implemented with its corresponding backend, frontend, users database and auth system modules using a docker-compose. There is certain freedom on choosing the language for every module, and a bunch of base-mandatory parts.