#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	if (c == '\0')
		return (ft_strchr(s, c));
	last = NULL;
	while (*s)
	{
		if (*s == (char) c)
			last = s;
		++s;
	}
	return ((char *) last);
}
