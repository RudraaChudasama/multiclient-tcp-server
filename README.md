# multiclient-tcp-server
Developed a multi-client TCP server in C on Linux to understand low-level client–server communication. Implemented socket creation, binding, listening, and handling multiple client connections concurrently. Gained hands-on experience with TCP/IP networking, Linux system calls, and server understanding.

# Multiclient TCP Server (Process-Based)

This project demonstrates a basic TCP server that can handle multiple
clients using process-based concurrency (`fork()`).

## Concepts Used
- TCP sockets
- Client–Server architecture
- fork() system call
- Linux process management

## How to Run
gcc server.c -o server
gcc client.c -o client

./server
./client

