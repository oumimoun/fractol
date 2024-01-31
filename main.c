#include <stdlib.h>
#include <stdio.h>

void    func2(int *f)
{
    printf("second: %p\n", f);
}

void func1(int *f)
{
    printf("last: %p\n", f);
    func2(f);
}

int main(void)
{
    int b = 54;
    printf("first: %p\n", &b);
    func1(&b);
}