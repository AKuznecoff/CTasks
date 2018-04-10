#include<stdio.h>
int main(){
	int squares[9][10];
	for (int *ptr = &squares[0][0], i = 0; i < 9 * 10; i++){
		*(ptr + i) = (10 + i) * (10 + i);
	}

	for (int *ptr = &squares[0][0], i = -11; i < 9 * 10; i++){
		if (i == -11) printf("   ");
		else if (i < 0) {
			printf("%4d ", 10 + i);
			if (i == -1) printf("\n");
		}
		else {
			if (i % 10 == 0) printf("%d ", i + 10);
			printf("%4d ", *(ptr + i));
		}
		if (i % 10 == 9) printf("\n");
	}
	return 0;
}