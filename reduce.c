#include <stdio.h>
#include <string.h>

void reduce(
	void *seq,
	void *res,
	size_t el_size,
	size_t count,
	void (*function)(void *first, void *second)) {
	char *seq_bytes = (char *)seq;
	char *res_bytes = (char *)res;
	//*res_bytes = *seq_bytes;
	memcpy(res_bytes, seq_bytes, 1);
	for (int i = 1; i < count; i++) {
		function(res_bytes, seq_bytes + i * el_size);
	}
}

void sum(void *first, void *second) {
	int *a = (int *)first;
	int *b = (int *)second;
	*a += *b;
}

int main() {
	int a[] = {1, 2, 3, 4, 5};
	int *b = &a[0];

	reduce(a, b, sizeof(int), 5, sum);
	//sum(b, &a[1]);
	printf("%d\n", *b);
	return 0;
}