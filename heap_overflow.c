#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUFSIZE 16

// Return the value of the ESP register
uintptr_t get_esp_value() {
    return (uintptr_t) __builtin_frame_address(0);
}

int main(int argc, char *argv[]) {
    char *heap_buf, *wbuf; // Pointers to heap-allocated buffers
    uintptr_t diff; // Difference between heap-allocated buffers

    // Allocate memory for heap buffers and calculate the difference between them
    heap_buf = (char *) malloc(BUFSIZE);
    wbuf = (char *) malloc(BUFSIZE);
    diff = (uintptr_t) wbuf - (uintptr_t) heap_buf;

    // Print the addresses of various variables
    printf("%-27s %-12s\n", "Variable", "Address");
    printf("------------------------------------------\n");
    printf("%-27s %-12p\n", "ESP value", (void *) get_esp_value);
    printf("%-27s %-12p\n", "Heap buffer", (void *) heap_buf);
    printf("%-27s %-12p\n", "Writable buffer", (void *) wbuf);
    printf("------------------------------------------\n\n");

    // Print the difference between the Heap buffer and the writable buffer
    printf("%s %u bytes\n", "Heap-Writable diff:", (unsigned int) diff);

    // Fill the writable buffer with 'W's and print it
    memset(wbuf, 'W', BUFSIZE - 1);
    printf("%-20s %-12s\n", "Writable Before Overwrite:", wbuf);

    // Overwrite the heap buffer with 'B's, overflowing into writable buffer
    // Print the writable buffer again
    memset(heap_buf, 'B', (uintptr_t) (diff + 8));
    printf("%-20s %-12s\n", "Writeable After overwrite:", wbuf);

    return 0;
}
