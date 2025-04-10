# ft_irc
## Definition
ft_irc is a C++ implementation of an Internet Relay Chat(IRC) server and client developed as part of 42 School's curriculum. It adheres to core standards from [RFC 1459](https://www.rfc-editor.org/rfc/rfc1459.html), enabling real-time text communication through a distributed network architecture.

## Core Features
### 1. Server Architecture
- Handles concurrent client connections using multi-threaded design
- Supports multiple simultaneous users with non-blocking I/O
- Implements user authentication and registration system

### 2. Channel Operations
- Creates/manages IRC channels with join/part commands
- Broadcasts messages to all channel members
- Supports channel-specific modes and topics

### 3. Communication
- Processes standard IRC commands: JOIN, PRIVMSG, NICK, PART
- Enables private messaging between users
- Manages user nicknames and channel membership

### 4. Technical Implementation
- Built using C++98 standard with socket programming
- Includes error handling for network operations
- Maintains connection states using non-blocking sockets

## What i learned
1. [poll()](DOC/poll().md)
2. [socket](DOC/<socket.h>.md)
3. [lock](DOC/overview.md)

```mermaid

sequenceDiagram
    participant Server
    participant SRVSOCKET
    participant STDIN
    participant CLI_1
    participant CLI_2

    Note over SRVSOCKET: (fd = 3)
    Note over STDIN: (fd = 0)
    Note over CLI_1: (fd = 4)
    Note over CLI_2: (fd = 5)

alt set_sever_socket()
    Note left of SRVSOCKET: creat <br/> struct sockaddr_in
    
    SRVSOCKET-->>Server: 
    Note left of Server: setsocket()
    Note left of Server: fcntl()
    Note left of Server: bind()
    Note left of Server: listen()
    Note left of SRVSOCKET: creat <br/> struct pollfd
    SRVSOCKET-->>Server: 
    Note left of Server: push(pollfd.fd = 3) in vector
    Note left of STDIN: creat <br/> struct pollfd
    participant STDIN
    STDIN-->>Server: 
    Note left of Server: push(pollfd.fd = 0) in vector
end
loop for (poll(), pollsize())
    
    alt accept_new_client()
        participant CLI_1
        Note left of CLI_1: creat <br/> struct pollfd
        Note left of CLI_1: connect()
        CLI_1-->>SRVSOCKET: 
        Note left of SRVSOCKET: accept()
        Note left of SRVSOCKET: fcntl()
        SRVSOCKET-->>Server:   
        Note left of Server: push(pollfd.fd = 1) in vector
        
    end
    Note left of Server: CLI_1 connected
    alt LOGIN PROCESS
        alt reciveNewData(fd)
            Note left of CLI_1: send(PASS)
            CLI_1-->>Server: 
            Note left of Server: recv(cmd)
            Note left of Server: parse_exec_cmd(cmd, 4)  
        end
        alt reciveNewData(fd)
            Note left of CLI_1: send(NICK)
            CLI_1-->>Server: 
            Note left of Server: recv(cmd)
            Note left of Server: parse_exec_cmd(cmd, 4)     
        end
        alt reciveNewData(fd)
            Note left of CLI_1: send(USER)
            CLI_1-->>Server: 
            Note left of Server: recv(cmd)
            Note left of Server: parse_exec_cmd(cmd, 4)      
        end
    end
    Note left of Server: CLI_1 loged in
    alt 
        CLI_2-->>Server: Add Client 2 [connect like CLI_1]
    end
    Note left of Server: CLI_2 connected
    Note left of Server: CLI_2 loged in
    alt reciveNewData(fd)
        Note left of CLI_1: send(cmd(PRIVMSG))
        CLI_1-->>+Server: 
        Note left of Server: recv(cmd)
        Note left of Server: parse_exec_cmd(cmd, 4) 
        Note left of Server: send(msg)
        Server-->>-CLI_2: 
        Note left of CLI_2: recv(msg)
    end
end
    
```

## Usage
``` bash
./ircserv <port number> <password>
```
After this, server is running.<br>
Now you should login by using nc(Netcat) tool.
```bash
nc localhost <port number>
```
Authenticate your client following below direction.
```bash
pass <password>
nick <nickname>
user <username> #it should be 4 arguments
```

## Example
#### Run
```bash
./ircserv 1234 hello_is_password
```
#### Connect Netcat
```bash
nc localhost 1234
```
#### Pass, Nick, User name
```bash
pass hello
nick jason
user jason 0 * jason
```

Check out on [Notion]() for the complete IRC project details.