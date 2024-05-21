#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>




int main() {
	*char string;
	string = (char*)malloc(20 * (sizeof(char)));

	printf("Ingrese una palabra o frase: ");

	free(string);
	return 0;
}