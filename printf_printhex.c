/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_printhex.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/18 17:55:07 by lsinke        #+#    #+#                 */
/*   Updated: 2021/12/18 17:55:07 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_internal.h"
#include "libft/libft.h"
#include <unistd.h>

static void	add_alt(char *str)
{
	str[0] = '0';
	str[1] = 'x';
}

int	printhex(unsigned long n, t_opts opts, int capitalize, int pointer)
{
	char	*nbr_str;
	int		length;

	if (n == 0 && !pointer)
		opts.pound = 0;
	nbr_str = ul_to_hex(n, opts);
	if (!nbr_str)
		return (0);
	if (opts.pound)
		add_alt(nbr_str);
	if (capitalize)
		ft_strtoupper(nbr_str);
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

int	printptr(void *p, t_opts opts)
{
	opts.pound = 1;
	return (printhex((unsigned long) p, opts, 0, 1));
}
