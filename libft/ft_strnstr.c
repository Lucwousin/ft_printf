#include "libft.h"

int	try_find(const char *str, const char *find, size_t n)
{
	while (n != 0 && *find)
	{
		if (*find != *str)
			return (0);
		++find;
		++str;
		--n;
	}
	return (*find == 0);
}

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	if (*find == '\0' || str == find)
		return ((char *) str);
	while (n > 0 && *str)
	{
		if (*str == *find)
			if (try_find(str, find, n))
				return ((char *) str);
		++str;
		--n;
	}
	return (NULL);
}
