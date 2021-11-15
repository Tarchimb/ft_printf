#include "ft_printf.h"
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
        write(1, "-2147483648", 11);
    else if (nb < 0)
    {
        nb *= -1;
        write(1, "-", 1);
    }
    if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    if (nb <= 9 && nb >= 0)
        ft_putchar(nb + '0');
}

int ft_printf(const char *s, ...)
{
    va_list argptr;
    int i;

    i = 0;
    va_start(argptr, s);
    while (s[i])
    {
        if (s[i] == '%')
        {
            if (s[i + 1] == 's')
            {
                char *string_type;
                string_type = (char *)va_arg(argptr, char *);
                while (*string_type)
                    ft_putchar(*string_type++);
                i += 2;
            }
            else if (s[i + 1] == 'c')
            {
                char    char_type;
                char_type = (char)va_arg(argptr, char);
                ft_putchar(char_type);
                i += 2;
            }
            if (s[i + 1] == 'd')
            {
                int int_type;
                int_type = (int)va_arg(argptr, int);
                //printf("(%d)", int_type);
                ft_putnbr(int_type);
                i += 2;
            }
        }
        else
        {
            if (s[i] == '\n')
                ft_putchar('\n');
            else
                ft_putchar(s[i]);
            i++;
        }
    }
    va_end(argptr);
    return (0);
}

int main()
{
    int     r;
    char    *i;
    char    *j;
    char    *k;
    char    c = 's';

    r = 45345;
    i = "salut";
    j = " tu vas bien?";
    k = " moi oui";
    ft_printf("string -->%s%s%s, %d , %c \n", i, j, k, r, c);
    printf("string -->%s%s%s, %d , %c \n", i, j, k, r, c);
}
