#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

/**
 * This is just as fast for a count of 1 or 2.
 * The faster way is nearly constant, while this way gets way slower for bigger counts.
 *
 * For count = 512 this way takes 330 cycles, the other takes 4.
 * I just kept this so I can work around failed mallocs (lol)
 */
static void	printf_pad_slow(char c, int count)
{
	while (count > 0)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		--count;
	}
}

void	printf_pad(t_opts opts, int count)
{
	char *s;
	char c;
	int i;

	if (count <= 0)
		return ;
	c = ' ';
	if (opts.zero && !opts.left)
		c = '0';
	s = malloc(count);
	if (!s)
	{
		printf_pad_slow(c, count);
		return;
	}
	i = count;
	while (i > 0)
	{
		--i;
		s[i] = c;
	}
	write(STDOUT_FILENO, s, count);
	free(s);
}