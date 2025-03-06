// Folha 3
// Exercício 8.1.1
#include <stdio.h>

int main() {
	double fahr, celcius;
	double *pfahr = &fahr;
	double *pcelcius = &celcius;
	int lower, upper, step;
	int *plower, *pupper, *pstep;

	lower = 0;
	plower = &lower;
	upper = 300;
	pupper = &upper;
	step = 20;
	pstep = &step;

	*pfahr = *plower;
	while (1) {
		*pcelcius = (5.0/9.0) * (*pfahr - 32);
		printf("%3.0fºF %6.1fºC\n", *pfahr, *pcelcius);
		*pfahr += *pstep;
		if (*pfahr > *pupper) break;
	}

	return 0;
}