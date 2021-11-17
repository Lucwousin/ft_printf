#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

//  %[flags][width][.precision][length modifier]conversion

// # == "alternate form"
//		This adds 0x or 0X in front of hexadecimal output
// 0 == zero padding
//		ignored if - is present
//		ignored for diouxX if . is present (int or unsigned int)
// - == left justification (padding to the right)
//   == (that's a space) add a space in front of positive numbers
// + == always add a sign character (+ or -) in front of signed numbers, overrides space
// width == decimal digit string without leading 0
//		if the value is shorter than the field with, pad with spaces
//		if the value is longer than this, expand the width
//		* means the next arg is the min width (so the one before the value)
// . == precision, followed by a decimal or *
//		if value is negative, ignore
//		if there's no int, precision is 0
//		* means the next arg is the precision (so the one before the value)

typedef struct s_printf_opts
{
	int	pound;
	int	zero;
	int	left;
	int	space;
	int	sign;
	int	minwidth;
	int	precision;
}		t_opts;

/**
 * Should segfault when format_string is null
 */
int		ft_printf(const char *format_string, ...);

void	initialize_options(t_opts *opts);
t_opts	parse_options(const char **str, va_list args);
void	parse_flags(const char **str, t_opts *opts);

int	printchar(char c, t_opts opts);
int	printstr(const char *str, t_opts opts);
int	printnbr(long n, t_opts opts);
int	printhex(unsigned long n, t_opts opts, int capitalize); // TODO: Check what printf("%#x", 0) prints also MAX/MIN LONG
int	printptr(void *p, t_opts opts); // TODO: Check what printf("%p", NULL) prints
// TODO: Norminette
/**
 * Return the absolute value of nbr, as an unsigned long
 */
unsigned long	to_uns(long nbr);

/**
 * Return the amount of characters needed to display number nbr in base base
 */
int	length_in_base(unsigned long nbr, int base);

/**
 * Write number nbr into the first length characters of str
 * converted to base base
 */
void	write_number(char *str, unsigned long nbr, int base, int length);
char	*printf_ltoa_base(long nbr, int base, t_opts opts);
char	*ul_to_hex(unsigned long nbr, t_opts opts);
void	printf_pad(t_opts opts, int count);

#endif //FT_PRINTF_H
