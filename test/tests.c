#include <stdio.h>
#include <stdlib.h>
#include "../ft_printf.h"

int	main(void)
{
	ft_printf("abc = %22.2s, a = %c\n", "abc", 'a');
	printf("abc = %22.2s, a = %c\n", "abc", 'a');
}