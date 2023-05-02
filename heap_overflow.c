#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 16

int global_var;

// Function to get the value of the ESP register
unsigned int get_esp_value() {
    return (unsigned int) __builtin_frame_address(0);
}

int main(int argc, char *argv[]) {
    char *heap_buf, *wbuf; // Pointers to heap-allocated buffers
    char auto_buf1[BUFSIZE], auto_buf2[BUFSIZE]; // Automatic (stack-allocated) buffers
    unsigned int diff; // Difference between heap-allocated buffers
    static char static_buf[BUFSIZE]; // Static (global) buffer

    // Allocate memory for heap buffers and calculate the difference between them
    heap_buf = (char *) malloc(BUFSIZE);
    wbuf = (char *) malloc(BUFSIZE);
    diff = (unsigned int) wbuf - (unsigned int) heap_buf;

    // Print the addresses of various variables
    fprintf(stdout, "Global variable      = %u\n", &global_var);
    fprintf(stdout, "ESP value            = %u\n", get_esp_value);
    fprintf(stdout, "Static buffer        = %u\n", static_buf);
    fprintf(stdout, "Heap buffer          = %u\n", heap_buf);
    fprintf(stdout, "Writable buffer      = %u\n", wbuf);
    fprintf(stdout, "Heap-Writable diff   = %d\n", diff);
    fprintf(stdout, "Auto buffer 1        = %u\n", auto_buf1);
    fprintf(stdout, "Auto buffer 2        = %u\n", auto_buf2);

    // Get the value of the ESP register and print it as a pointer
    unsigned int pnt = get_esp_value();
    fprintf(stdout, "ESP value as pointer = %u\n", pnt);

    // Fill the writable buffer with 'W's and print it
    memset(wbuf, 'W', BUFSIZE - 1);
    wbuf[BUFSIZE - 1] = '\0';
    fprintf(stdout, "Before overwrite     = %s\n", wbuf);

    // Overwrite the heap buffer with 'B's and print the writable buffer again
    memset(heap_buf, 'B', (unsigned int) (diff + 8));
    fprintf(stdout, "After overwrite      = %s\n", wbuf);

    return 0;
}
