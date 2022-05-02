/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_internal.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/18 17:55:07 by lsinke        #+#    #+#                 */
/*   Updated: 2021/12/18 17:55:07 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
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

t_opts			parse_options(const char **str, va_list *args);
void			parse_flags(const char **str, t_opts *opts);

/**
 * ===== CONVERSIONS =====
 * %c
 */
int				printchar(char c, t_opts opts);
/**
 * %%
 *
 * Uses printchar but sets minwidth to 0
 */
int				printpercent(t_opts opts);
/**
 * %s
 */
int				printstr(const char *str, t_opts opts);
/**
 * %diu
 */
int				printnbr(long n, t_opts opts);
/**
 * %xX
 *
 * This function is also used by printptr (%p).
 * @param cap Should the hex value be capitalized?
 * @param pointer Are we dealing with a pointer?
 * The pointer parameter is necessary because pointers always print 0x (even 0)
 */
int				printhex(unsigned long n, t_opts opts, int cap, int pointer);
/**
 * %p
 */
int				printptr(void *p, t_opts opts);

/**
 * Return the absolute value of nbr, as an unsigned long
 */
unsigned long	to_uns(long nbr);

/**
 * Return the amount of characters needed to display number nbr in base base
 */
int				length_in_base(unsigned long nbr, int base, int precision);

/**
 * Write number nbr into the first length characters of str
 * converted to base base
 */
void			write_number(char *s, unsigned long n, int base, int length);
char			*ul_to_hex(unsigned long nbr, t_opts opts);
void			printf_pad(t_opts opts, int count);

#endif //FT_PRINTF_INTERNAL_H
