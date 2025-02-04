#include <stdio.h>

int main() {
	int age;
	int weight;
	
	printf("A sua idade: ");
	scanf("%d", &age);
	printf("O seu peso: ");
	scanf("%d", &weight);

	printf("Chamo-me Tomás, tenho %d anos e peso %d Kg.\n", age, weight);
	return 0;
}