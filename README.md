# Project Summary


The client will communicate with remote NTP server.
UDP is the standard protocol for sending packets to NTP server on port 123. 


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
