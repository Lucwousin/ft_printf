/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nbr_to_str_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/18 17:55:07 by lsinke        #+#    #+#                 */
/*   Updated: 2021/12/18 17:55:07 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#define BASE_CHARS "0123456789abcdef"

unsigned long	to_uns(long nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

int	length_in_base(unsigned long nbr, int base, int precision)
{
	int	n;

	if (nbr == 0)
		return (precision != 0);
	n = 0;
	while (nbr != 0)
	{
		nbr /= base;
		++n;
	}
	return (n);
}

void	write_number(char *str, unsigned long nbr, int base, int length)
{
	int	base_index;

	while (length > 0)
	{
		--length;
		base_index = nbr % base;
		str[length] = BASE_CHARS[base_index];
		nbr /= base;
	}
}
