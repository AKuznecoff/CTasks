#include<stdio.h>
#include<math.h>

int main(){
	float a;
	float b;
	float c;
	scanf("%f %f %f", &a, &b, &c);
	if (a >= b + c || b >= a + c || c >= a + b)
		printf("Not valid\n");
	else if (fabsf(a*a - b*b - c*c) < 0.001 || fabsf(b*b - a*a - c*c) < 0.001 || fabsf(c*c - a*a - b*b) < 0.001 )
		printf("True\n");
	else
		printf("False\n");
	return 0;
}
