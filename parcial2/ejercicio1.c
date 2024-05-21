#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct red {
	char *ipDirec;
	char *mask;
}Red;


char *numRed(Red *red);


int main() {

	Red *red1;
	char *redNum;

	red1 = (Red *)malloc(sizeof(Red));
	red1->ipDirec = (char *)malloc(15 * sizeof(char));
	red1->mask = (char *)malloc(13 * sizeof(char));

	red1->ipDirec = "192.168.146.222";
	red1->mask = "255.255.255.0";

	printf("\nDireccion IP: %s\n", red1->ipDirec);
	printf("\nLa mascara es: %s\n", red1->mask);

	redNum = numRed(red1);

	printf("\nEl numero de red es: %s\n", redNum);

	free(red1);
	free(red1->ipDirec);
	free(red1->mask);

	return 0;

}


char *numRed(Red *red) {
	char *redNum;
	redNum = (char *)malloc(13 * sizeof(char));

	for(int i = 0; i < 12; i++) {
		redNum[i] = red->ipDirec[i];
	}

	redNum[12] = '0';

	return redNum;
}
