/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_printstr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/18 17:55:07 by lsinke        #+#    #+#                 */
/*   Updated: 2021/12/18 17:55:07 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf_internal.h"
#include <unistd.h>

int	printstr(const char *str, t_opts opts)
{
	size_t	length;

	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (opts.precision >= 0)
		length = ft_min(length, opts.precision);
	if (!opts.left)
		printf_pad(opts, opts.minwidth - length);
	write(STDOUT_FILENO, str, length);
	if (opts.left)
		printf_pad(opts, opts.minwidth - length);
	return (ft_max(length, opts.minwidth));
}
