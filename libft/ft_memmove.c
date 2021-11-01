#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		s = src + (len - 1);
		d = dst + (len - 1);
		while (len > 0)
		{
			*d = *s;
			--d;
			--s;
			--len;
		}
	}
	return (dst);
}
