#include  <stdio.h>

int filter(
    void *seq,
    void *res,
    size_t count,
    size_t item_size,
    int (*filter_func)(void *, void *)) {
    char *seq_bytes = (char *)seq;
    char *res_bytes = (char *)res;
    int res_count = 0;
    for (int i = 0; i < count; i++) {
        res_count += filter_func(seq_bytes + i * item_size, res_bytes + res_count * item_size);
    }
    return res_count;
}

int isEven(int number) {
    return (number + 1)% 2;
}

int filter_even(void *from, void *to) {
    int *from_bytes = (int *)from;
    int *to_bytes = (int *)to;
    //if (isEven(*from_bytes) != 0) {
    if (*from_bytes % 2 == 0){
        *to_bytes = *from_bytes;
        return 1;
    }
    return 0;
}    

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7,8, 9, 10};
    int b[10];
    int count = filter(a, b, 10, sizeof(int), filter_even);
    for(int i = 0; i < count; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}
