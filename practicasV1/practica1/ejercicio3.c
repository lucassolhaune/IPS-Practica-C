#include <stdio.h>
#include <malloc.h>

void invertedNum(int *pointNum) {
	for (int i = 10; i > 0; i--) {
		pointNum--;
		printf("%d\n", *pointNum);
	}
}

int main() {

	int *pnum = (int*)malloc(10 * sizeof(int));
	int *originPointer = pnum;

	printf("Ingrese 10 numeros:\n");

	for(int i = 1; i <= 10; i++) {
		scanf("%d", pnum);
		pnum++;
	}

	printf("Numeros inversos:\n");
	invertedNum(pnum);

	pnum = originPointer;
	free(pnum);
	pnum = NULL;

	return 0;
}
