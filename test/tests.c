#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ft_printf.h"

char	*ok_ko(int ok)
{
	return (ok ? "[OK]" : "[KO]");
}

void	test_ltoa_base(long nbr, int base, int precision, int sign, const char *expected)
{
	char	*output = printf_ltoa_base(nbr, base, precision, sign);
	printf("%s ltoa_base(%ld, %d, %d, %d): %s\n",
		ok_ko(strcmp(output, expected) == 0),
		nbr, base, precision, sign, output
	);
	free(output);
}

int	main(void)
{
	test_ltoa_base(123456,		10,	-1,	0,	"123456");
	test_ltoa_base(123456,		16,	-1,	0,	"1e240");
	test_ltoa_base(123456,		10,	10,	0,	"0000123456");
	test_ltoa_base(123456,		16,	10,	0,	"000001e240");
	test_ltoa_base(123456,		10,	-1,	1,	"+123456");
	test_ltoa_base(123456,		16,	-1,	1,	"+1e240");
	test_ltoa_base(-123456,	10,	-1,	0,	"-123456");
	test_ltoa_base(-123456,	16,	-1,	0,	"-1e240");
	test_ltoa_base(123456,		10,	10,	1,	"+000123456");
	test_ltoa_base(123456,		16,	10,	1,	"+00001e240");


	ft_printf("%%abc = %*.2s, a = %c\n", -22, "abc", 'a');
	printf("%%abc = %*.2s, a = %c\n", -22, "abc", 'a');

	printf("%12.4i\n", -100);
}