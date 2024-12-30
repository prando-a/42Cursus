# ft_irc



### Description



The **ft_irc** project consists of creating a basic Internet Relay Chat (IRC) server that complies with the RFC 2812 specification for client-server communication. The server allows clients to connect, authenticate, join channels, send messages, and perform basic IRC commands.



This project is an excellent opportunity to learn:

- **Network programming in C**: Using sockets and related functions to establish and manage connections.

- **Multiplexing with `select()`**: Handling multiple simultaneous connections efficiently.

- **Protocol implementation**: Understanding and implementing the IRC protocol based on RFC 2812.



### Technical concepts related to ft_irc



1. **Network Programming Functions**:

   - **Socket creation**: `socket()` is used to create a socket for communication.

   - **Address manipulation**: Functions such as `htons()` and `inet_addr()` convert data to network byte order and handle IP addresses.

   - **Binding**: `bind()` associates the socket with a specific IP and port.

   - **Listening**: `listen()` allows the socket to accept incoming connections.

   - **Accepting connections**: `accept()` retrieves new connections from clients.

   - **Data transfer**: `recv()` and `send()` handle the exchange of data between server and clients.



2. **Multiplexing with `select()`**:

   - Monitor multiple file descriptors (sockets) simultaneously.

   - Efficiently handle incoming connections and messages without blocking operations.



3. **IRC-Specific Concepts**:

   - Authentication: Handling client authentication with mandatory passwords.

   - Channel management: Creating and managing channels for group communication.

   - Parsing and handling commands: Implementing commands like `JOIN`, `PRIVMSG`, `QUIT`, etc.

 ## Usage

### Compilation

The project is compiled with a Makefile located in the `ft_irc` directory. To compile the server, run:

```bash
make
```
This will generate an executable named `ircserv`. Execution is as:

 ```bash
 ./ircserv [port] [password]
 ```

 - **Port**: The port number on which the server will listen for connections.
 - **Password**: A mandatory password for client authentication.

 ### Example:

 ```bash
 ./ircserv 6667 mypassword
 ```

 ---

 ## Connecting to the Server

 ### Using HexChat (Recommended Client)

 HexChat is a graphical IRC client that fully supports communication with the server.

 1. Open HexChat and create a new network:
    - Go to **HexChat > Network List >  Add**.
    - Enter the server name (e.g., "MyIRC").
    - Click "Edit" and enter `localhost/[port]` as the server address (e.g., `localhost/6667`).
    - Add the server password in the "Password" field.

 2. Connect to the server by selecting the network and clicking **Connect**.

 3. Use standard IRC commands to interact with the server:
    - `/join #channel` to join a channel.
    - `/msg user message` to send a private message.

 ### Using Netcat

 Netcat is a simple command-line tool that can be used to connect to the server.

 1. Open a terminal and run:

    ```bash
    nc localhost [port]
    ```

    Replace `[port]` with the port number of the server (e.g., `6667`).

 2. Authenticate by sending the password:

    ```bash
    PASS mypassword
    ```

 3. Register a nickname and username:

    ```bash
    NICK mynickname
    USER myusername 0 * :Real Name
    ```

 4. Use IRC commands to interact with the server (e.g., `JOIN`, `PRIVMSG`).

 ---

 ## Implementation Details

 The project uses the following steps to establish and manage the server:

 ### Socket Creation:

 ```c
 int server_fd = socket(AF_INET, SOCK_STREAM, 0);
 ```

 - Creates a socket for IPv4 TCP communication.

 ### Address Binding:

 ```c
 struct sockaddr_in address;

 address.sin_family = AF_INET;
 address.sin_addr.s_addr = INADDR_ANY;
 address.sin_port = htons(port);

 bind(server_fd, (struct sockaddr*)&address, sizeof(address));
 ```

 - Binds the socket to the specified port.

 ### Listening for Connections:

 ```c
 listen(server_fd, SOMAXCONN);
 ```

 - Puts the socket in a state where it can accept incoming connections.

 ### Multiplexing with `select()`:

 - The server uses `select()` to monitor multiple sockets (server and client connections).
 - File descriptors are added to the `fd_set` set, and `select()` waits for activity.
 - Example usage:

    ```c
    FD_SET(server_fd, &readfds);
    select(max_fd + 1, &readfds, NULL, NULL, NULL);
    ```

 ### Handling Client Connections:

 - Accept new connections with `accept()`.
 - Read and parse client messages using `recv()`.
 - Respond with appropriate IRC messages or commands using `send()`.

 ---

 ## Notes

 - The server implements the IRC protocol as defined in [RFC 2812](https://datatracker.ietf.org/doc/html/rfc2812).
 - The implementation uses `select()` for multiplexing. Alternative methods such as `poll()` or `epoll()` are mostly used but `select()` is way more advanced and simple to use.
 - Error handling is implemented for all critical operations, including invalid commands, connection failures, and authentication errors.

 ---