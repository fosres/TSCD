#include <stdio.h>

int main(void)
{
	printf("\e[38;5;196m"); //Red
	
	putchar(0xa);putchar(0xa);

	printf("Red: Non-printable ASCII characters\n\n");
	
	printf("\e[0m");

	printf("\e[38;5;208m"); //Orange

	printf("Orange: Printable (Alphabetic) Characters\n\n");

	printf("\e[0m");

	printf("\e[38;5;226m"); //Yellow

	printf("Yellow: Base 10 Numerical Digits\n\n");

	printf("\e[0m");

	printf("\e[38;5;40m");

	printf("Green: ASCII Whitespace Characters\n\n");

	printf("\e[0m");

	printf("\e[38;5;201m"); //Purple

	printf("Purple: Punctuation Characters\n\n");

	printf("\e[0m");

	printf("\e[38;5;244m");

	printf("Gray: NUL byte (00)\n\n");
	
	printf("\e[0m");

	return 0;
}
