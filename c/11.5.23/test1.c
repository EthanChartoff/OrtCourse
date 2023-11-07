#include <stdio.h>

int x;
char *c[] = {"DOOR", "ME", "POINTERS", "BALIL"};
char **cp[] = {c+3, c+2, c+1, c};
char ***cpp = cp;

void main(void) {
	printf("%s\n", **++cpp); // c + 2 == "POINTERS"
	printf("%s\n", ++**cpp); // (c + 2)[1]
	printf("%s\n", cpp[-1]+3); // trash, warning
	printf("%c\n", cpp[-1][-1][-1]); // P
	scanf("%d", &x);
}
