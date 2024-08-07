#include <stdio.h>

void printBinary(int num) {
	int i;
	// Iterating over each bit from the most significant bit to the least significant bit
	if (num < 9999 && num > -9999)
		printf("%d\t\t", num);
	else
		printf("%d\t", num);
	for (i = 31; i >= 0; i--)
	{
		// Print the opening bracket
		printf("[");
		// Print the bit at the ith position
		printf("%d", (num >> i) & 1);
		// Print the closing bracket
		printf("]");
		if (i % 8 == 0)
			printf(" ");
	}
	// Print a newline at the end for better readability
	printf("\n");
}

int main()
{
	printBinary(-2147483648);
	printBinary(-2147483647);
	printBinary(-2147483646);
	printBinary(-2147483645);
	printBinary(-2);
	printBinary(-1);
	printBinary(0);
	printBinary(1);
	printBinary(2);
	printBinary(2147483645);
	printBinary(2147483646);
	printBinary(2147483647);
	return 0;
}

/*

On utilise le type float pour stocker un nombre avec une virgule. On a aussi 4 octets :
float number = 42.75;

IEEE 754 standard
[0]
[1][0][0][0][0][1][0][0]
[0][1][0][1][0][1][1][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]
32 bits au total

🟡 Signe (1) 🟡 • 🟢 Exposant (8) 🟢 • 🔵 Mantisse (23) 🔵

Pour obtenir l'exposant, on ajoute 127 (2^7 - 1) à la valeur de l'exposant en binaire.
En partant de 42.75, on a :
42 = 101010 en binaire
0.75 = 0.11 en binaire
42.75 = 101010.11 en binaire

0.75 = (2^-1 * 1) + (2^-2 * 1) + (2^-3 * 0) + (2^-4 * 0) + ••• + (2^-23 * 0) = 0.11
0.75 = 1100 0000 0000 0000 0000 000

42 = (2^5 * 1) + (2^4 * 0) + (2^3 * 1) + (2^2 * 0) + (2^1 * 1) + (2^0 * 0) = 101010
42 = 1010 1000 0000 0000 0000 0000

42.75 sur 32 bits :
0 10000101 01010000000000000000000


*/