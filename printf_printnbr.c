/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_printnbr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/18 17:55:07 by lsinke        #+#    #+#                 */
/*   Updated: 2021/12/18 17:55:07 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_internal.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	add_signchar(char *str, int negative, int space)
{
	if (negative)
		str[0] = '-';
	else if (space)
		str[0] = ' ';
	else
		str[0] = '+';
}

static int	should_add_sign(long nbr, t_opts opts)
{
	return (opts.sign || opts.space || nbr < 0);
}

static char	*printf_ltoa(long nbr, t_opts opts)
{
	char	*str;
	int		num_length;
	int		add_sign;

	num_length = length_in_base(to_uns(nbr), 10, opts.precision);
	add_sign = should_add_sign(nbr, opts);
	num_length = ft_max(opts.precision, num_length);
	if (add_sign)
		num_length++;
	if (opts.precision >= 0 && opts.zero)
		opts.zero = 0;
	if (opts.zero)
		num_length = ft_max(opts.minwidth, num_length);
	str = malloc((num_length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[num_length] = '\0';
	write_number(str, to_uns(nbr), 10, num_length);
	if (add_sign)
		add_signchar(str, nbr < 0, opts.space);
	return (str);
}

int	printnbr(long n, t_opts opts)
{
	char	*nbr_str;
	size_t	length;

	nbr_str = printf_ltoa(n, opts);
	if (!nbr_str)
		return (0);
	length = ft_strlen(nbr_str);
	if (opts.zero)
		opts.zero = 0;
	if (!opts.left)
		printf_pad(opts, opts.minwidth - length);
	write(STDOUT_FILENO, nbr_str, length);
	if (opts.left)
		printf_pad(opts, opts.minwidth - length);
	free(nbr_str);
	return (ft_max(length, opts.minwidth));
}
