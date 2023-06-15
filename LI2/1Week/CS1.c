// Problema C - Formatura

#include <stdio.h>
#include <assert.h>

int main () {
    int a, b, c;
    
    assert (scanf("%d",&a) == 1);
    assert (scanf("%d",&b) == 1);
    assert (scanf("%d",&c) == 1);

    if (a > b)
        if (b > c) printf("%d %d %d\n", c, b, a); // a > b > c
        else 
            if (a > c) printf("%d %d %d\n", b, c, a); // a > b e b < c e a > c, logo a > c > b
            else printf("%d %d %d\n", b, a, c); // a > b e b < c e a < c, logo c > a > b
    else
        if (b > c)
            if (a > c) printf("%d %d %d\n", c, a, b); // b > c e a > c e b >= a, logo b >= a > c
            else printf("%d %d %d\n", a, c, b); // b > c e b >= a e a < c, logo b > c > a
        else printf("%d %d %d\n", a, b, c); // b >= a e b <= c, logo c >= b >= a

    return 0;
}