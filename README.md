# ft_irc
> Common core project at School 42 Paris by: abesombe - rgeny - ayzapata, students
>
> First project in C++

## Introduction
This project is about creating your own IRC server. You will use an actual IRC client to connect to your server and test it. Internet is ruled by solid standards protocols that allow connected computers to interact with each other.

## General guidelines
1. You have to turn in a Makefile which will compile your source files. It must not relink.
2. Try to always develop using the most C++ features you can (for example, choose <cstring> over <string.h>). You are allowed to use C functions, but always prefer their C++ versions if possible.
3. Any external library and Boost libraries are forbidden.
4. The executable will be run as follows: `./ircserv <port> <password>`
5. port: The port number on which your IRC server will be listening to for incoming IRC connections.
6. password: The connection password. It will be needed by any IRC client that tries to connect to your server.
7. Communication between client and server has to be done via TCP/IP (v4 or v6).
8. The server must be capable of handling multiple clients at the same time and never hang.
9. Forking is not allowed. All I/O operations must be non-blocking

<img width="900" alt="image" src="https://github.com/avanessazc/ft_irc/blob/main/ft_irc.png">
