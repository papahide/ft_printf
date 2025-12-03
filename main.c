#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char    c = 'A';
    char    *s = "Hola, mundo";
    int     d = -42;
    int     i = 1337;
	void    *p = &d;
    unsigned int u = -1;
    unsigned int x = 0xabcdef;
    unsigned int X = 0xabcdef;

    /* MI PRINTF */
    // ft_printf("MI PRINTF:\n");

    // ft_printf("%%c: %c\n", c);
    // ft_printf("%%s: %s\n", s);
    // ft_printf("%%p: %p\n", p);
    // ft_printf("%%d: %d\n", d);
    // ft_printf("%%i: %i\n", i);
    // ft_printf("%%u: %u\n", u);
    // ft_printf("%%x: %x\n", x);
    // ft_printf("%%X: %X\n", X);
    // ft_printf("%%%%: %%\n");

    printf("\nPRINTF ORIGINAL:\n");

    /* PRINTF ORIGINAL */
    printf("%%c: %c\n", c);
    printf("%%s: %s\n", s);
    printf("%%p: %p\n", p);
    printf("%%d: %d\n", d);
    printf("%%i: %i\n", i);
    printf("%%u: %u\n", u);
    printf("%%x: %x\n", x);
    printf("%%X: %X\n", X);
    printf("%%%%: %%\n");

    return 0;
}