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
// . == precision, followed by a decimal or * or *m$
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

t_opts	parse_options(const char **str, va_list args);

int	printchar(char c, t_opts opts);
int	printstr(const char *str, t_opts opts);

void	printf_pad(t_opts opts, int count);

#endif //FT_PRINTF_H
