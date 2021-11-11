#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ft_printf.h"
#include "../libft/libft.h"

char	*ok_ko(int ok)
{
	return (ok ? "[OK]" : "[KO]");
}

void	set_prec_sign(t_opts *opts, int precision, int sign)
{
	opts->precision = precision;
	opts->sign = sign;
}

const char	*create_format_string(int base, t_opts opts)
{
	int		size;
	char	*ret;
	char	*minwidth = opts.minwidth > 0 ? ft_itoa(opts.minwidth) : NULL;
	char	*precision = opts.precision >= 0 ? ft_itoa(opts.precision) : NULL;

	size = 2 + opts.pound + opts.zero + opts.left + opts.space + opts.sign + 1;
	if (minwidth)
		size += strlen(minwidth);
	if (precision)
		size += strlen(precision) + 1;
	ret = malloc(size);
	char	*s = ret;
	*s++ = '%';
	if (opts.pound)
		*s++ = '#';
	if (opts.zero)
		*s++ = '0';
	if (opts.left)
		*s++ = '-';
	if (opts.space)
		*s++ = ' ';
	if (opts.sign)
		*s++ = '+';
	if (minwidth)
		while (*minwidth)
			*s++ = *minwidth++;
	if (precision) {
		*s++= '.';
		while (*precision)
			*s++ = *precision++;
	}
	*s++ = base == 16 ? 'x' : 'd';
	*s++ = '\0';
	return (ret);
}

void	test_ltoa_base(long nbr, int base, t_opts opts)
{
	const char	*format_str = create_format_string(base, opts);
	char	*asprintf_output;
	int		asprintf_size = asprintf(&asprintf_output, format_str, nbr);

	char	*output = printf_ltoa_base(nbr, base, opts);
	printf("%s ltoa_base(%ld, %d, %d, %d): %s (%d)\n",
		ok_ko(strcmp(output, asprintf_output) == 0),
		nbr, base, opts.precision, opts.sign, output, (int) strlen(output)
	);
	printf("---- printf: %s (%d)\n", asprintf_output, asprintf_size);
	free(output);
}

void	set_opts(t_opts *opts, int pound, int zero, int left, int space, int sign, int minwidth, int precision)
{
	opts->pound = pound;
	opts->zero = zero;
	opts->left = left;
	opts->space = space;
	opts->sign = sign;
	opts->minwidth = minwidth;
	opts->precision = precision;
}

void	test_ltoa_bases(void)
{
	t_opts	opts;
	initialize_options(&opts);

	test_ltoa_base(123456,		16,	opts);
	test_ltoa_base(123456,		10,	opts);

	set_opts(&opts, 0, 0, 0, 0, 0, 0, 10);
	test_ltoa_base(123456,		16,	opts);
	test_ltoa_base(123456,		10,	opts);

	set_opts(&opts, 0, 0, 0, 0, 1, 0, -1);
	test_ltoa_base(123456,		16,	opts);
	test_ltoa_base(123456,		10,	opts);

	set_opts(&opts, 0, 1, 0, 0, 0, 10, -1);
	test_ltoa_base(123456,		16,	opts);
	test_ltoa_base(123456,		10,	opts);

	set_opts(&opts, 0, 1, 0, 0, 0, 10, -1);
	test_ltoa_base((unsigned) -123456,		16,	opts);
	test_ltoa_base(-123456,		10,	opts);

	set_opts(&opts, 0, 0, 0, 1, 0, 0, 10);
	test_ltoa_base(123456,		16,	opts);
	test_ltoa_base(123456,		10,	opts);

	set_opts(&opts, 0, 0, 0, 0, 1, 0, 10);
	test_ltoa_base(123456,		16,	opts);
	test_ltoa_base(123456,		10,	opts);
}

int	main(void)
{
	test_ltoa_bases();
//	t_opts opts;
//	initialize_options(&opts);
//
//	set_prec_sign(&opts, -1, 0);
//	test_ltoa_base(123456,		10,	opts,	"123456");
//	test_ltoa_base(123456,		16,	opts,	"1e240");
//
//	set_prec_sign(&opts, 10, 0);
//	test_ltoa_base(123456,		10,	opts,	"0000123456");
//	test_ltoa_base(123456,		16,	opts,	"000001e240");
//
//	set_prec_sign(&opts, -1, 1);
//	test_ltoa_base(123456,		10,	opts,	"+123456");
//	test_ltoa_base(123456,		16,	opts,	"+1e240");
//
//	set_prec_sign(&opts, -1, 0);
//	test_ltoa_base(-123456,	10,	opts,	"-123456");
//	test_ltoa_base(-123456,	16,	opts,	"-1e240");
//
//	set_prec_sign(&opts, 10, 0);
//	test_ltoa_base(-123456,	10,	opts,	"-0000123456");
//	test_ltoa_base(-123456,	16,	opts,	"-000001e240");
//
//	set_prec_sign(&opts, 10, 1);
//	test_ltoa_base(123456,		10,	opts,	"+0000123456");
//	test_ltoa_base(123456,		16,	opts,	"+000001e240");


	int a = printf("%#100.52X\n", -100);
	int b = ft_printf("%#100.52X\n", -100);
	ft_printf("printf: %d, ft_printf: %d\n", a, b);
}