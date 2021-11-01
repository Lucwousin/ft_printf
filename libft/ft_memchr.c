#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		cc;

	cc = c;
	p = s;
	while (n > 0)
	{
		if (*p == cc)
			return ((void *) p);
		++p;
		--n;
	}
	return (NULL);
}
