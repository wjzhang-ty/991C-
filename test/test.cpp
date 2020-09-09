#include <stdio.h> 
struct ks {
    int a;
    int* b;

} s[4], * p;
int  main() {
    int n = 1, i;
    for (i = 0; i < 4; i++) {
        s[i].a = n;
        s[i].b = &s[i].a;
        n = n + 2;
    }
    p = &s[0];
    p++;
    printf("%d, %d\n", (p++)->a, (++p)->a);
    return 0;
}