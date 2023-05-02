#include <stdio.h>
#include <string.h>

void overflow(char *input_str) {
	char buff[12];
	strcpy(buff, input_str);
	puts(input_str);
}

int main(char* argv[], int argc) {
	char rand_str[] = "aaaabbbb" "\x6c\x73\x20\x2d\x6c\x61" "ddeeee";
	overflow(rand_str);
	return 0;
}
