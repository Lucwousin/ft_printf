#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*dp;
	const char	*sp;

	if (!dst && !src)
		return (NULL);
	dp = dst;
	sp = src;
	while (len > 0)
	{
		*dp = *sp;
		++dp;
		++sp;
		--len;
	}
	return (dst);
}
