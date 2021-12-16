#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# include <stdarg.h>

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

void			initialize_options(t_opts *opts);
t_opts			parse_options(const char **str, va_list args);
void			parse_flags(const char **str, t_opts *opts);

int				printchar(char c, t_opts opts);
int				printstr(const char *str, t_opts opts);
int				printnbr(long n, t_opts opts);
int				printhex(unsigned long n, t_opts opts, int capitalize, int pointer);
int				printptr(void *p, t_opts opts);

/**
 * Return the absolute value of nbr, as an unsigned long
 */
unsigned long	to_uns(long nbr);

/**
 * Return the amount of characters needed to display number nbr in base base
 */
int				length_in_base(unsigned long nbr, int base);

/**
 * Write number nbr into the first length characters of str
 * converted to base base
 */
void			write_number(char *s, unsigned long n, int base, int length);
char			*printf_ltoa_base(long nbr, int base, t_opts opts);
char			*ul_to_hex(unsigned long nbr, t_opts opts);
void			printf_pad(t_opts opts, int count);

#endif //FT_PRINTF_FT_PRINTF_INTERNAL_H
