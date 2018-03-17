#include<stdio.h>
#include<ctype.h>

int main(){
	char ch;
	int digits = 0;
	int latinSymbols = 0;
	while ((ch = getc(stdin)) != EOF){
			if (isdigit(ch))
				digits++;
			else if (isalpha(ch))
				latinSymbols++;
	}
	printf("Digits: %d\n", digits);
	printf("Latin symbols: %d\n", latinSymbols );
	return 0;
}
