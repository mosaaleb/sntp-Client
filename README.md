# Project Summary


## Introduction
This project is originally built for interviewing task as embedded software engineer position. The project demonstrates low level understanding of how networking works.


## Summary
The client will communicate with remote NTP server.
UDP is the standard protocol for sending packets to NTP server on port 123. 


> To do network I/O, the first thing a process must do is to call the socket system call, specifying the type of communication protocol desired.

```C++
#include <sys/types.h>
#include <sys/socket.h>
```

`socket.h` file containes `socket` function definition:
<br>
`int socket(int family, int type, int protocol);`
<br>
We gonna use `AF_INET` family, `SOCK_DGRAM` type, and `UDP` protocol.
The family is one of: 

    AF_UNIX     -- Unix internal protocols
    AF_INET     -- Internet protocols
    AF_NS       -- Xerox NS protocols
    AF_IMPLINK  -- IMP link layer


`socket.h` file also contains `connect` function definition to establish a connection with a server:
<br>
`int connect(int sockfd, struct socketaddr* servaddr, int addrlen);`
<br>
The `sockfd` is a socket descriptor that was returned by the socket system call. The second and third arguments are a pointer to a socket address and its size.
The connect system call does not return until the connection is established, or an error is returned to the process.

*Read More:*
[Socket System Calls](https://www.cs.hmc.edu/~mike/public_html/courses/cs125/FAQ/examples.html)


## SNTP message format

The SNTP Message (packet) sent by the client to the server and 
the responses from the servers to the client use a common format:
<pre>
                1               2               3                4
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |LI | VN  |Mode |    Stratum    |     Poll      |   Precision   |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |                          Root Delay (32)                      |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |                       Root Dispersion (32)                    |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |                    Reference Identifier (32)                  |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |        Reference Timestamp (integral part) (32)               |
 |                            (fractional part) (32)             |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |        Originate Timestamp (integral part) (32)               |
 |                            (fractional part) (32)             |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |         Receive Timestamp (integral part) (32)                |
 |                           (fractional part) (32)              |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |         Transmit Timestamp (integral part) (32)               |
 |                            (fractional part) (32)             |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

 Overall message is 48 byte long 

</pre>

## Basic Operation



| Timestamp Name        | ID   | When generated                 |
|:----------------------|:----:|:-------------------------------|
| Originate Timestamp   | T1   | time request sent by client    |
| Receive Timestamp     | T2   | time request receive by server |
| Transmit Timestamp    | T3   | time reply sent by server      |
| Destination Temestamp | T4   | time reply received by client  |


Timestamps are represented as a 64-bit fixed pointer number, in seconds relative to 0000 UT on 1 January 1900
