/*
 *
 * This is a simple SNTP client made for education.
 *
 *  
 * The SNTP Message (packet) sent by the client to the server and 
 * the responses from the servers to the client use a common format:
 *   
 *  
 *                 1               2               3                4
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |LI | VN  |Mode |    Stratum    |     Poll      |   Precision   |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                          Root Delay (32)                      |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                       Root Dispersion (32)                    |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                    Reference Identifier (32)                  |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |        Reference Timestamp (integral part) (32)               |
 * |                            (fractional part) (32)             |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |        Originate Timestamp (integral part) (32)               |
 * |                            (fractional part) (32)             |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |         Receive Timestamp (integral part) (32)                |
 * |                           (fractional part) (32)              |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |         Transmit Timestamp (integral part) (32)               |
 * |                            (fractional part) (32)             |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 * Overall message is 48 byte long 
 *
 *
 * Read More: https://www.cisco.com/c/en/us/about/press/internet-protocol-journal/back-issues/table-contents-58/154-ntp.html
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <time.h>
#include <netinet/in.h>


typedef struct{
    
    uint8_t li_vn_mode;
    uint8_t stratum;
    uint8_t poll;
    uint8_t precision;
    
    uint32_t rootDelay;
    uint32_t rootDispertion;
    uint32_t refID;

    uint32_t refTm_s;
    uint32_t refTm_f;

    uint32_t origTm_s;
    uint32_t origTm_f;

    uint32_t rxTm_s;
    uint32_t rxTm_f;

    uint32_t txTm_s;
    uint32_t txTm_f;

}ntp_packet;

int main(void){
    // create the packet
    // setup the message with all zeros

    ntp_packet packet = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    memset( &packet, 0, sizeof( ntp_packet ) );

    // Set the first byte's bits to 00,011,011 for li = 0, vn = 3, and mode = 3. The rest will be left set to zero.

    *( ( char * ) &packet + 0 ) = 0x1b; // Represents 27 in base 10 or 00011011 in base 2.
}