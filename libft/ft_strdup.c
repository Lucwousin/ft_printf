#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(str) + 1;
	ret = malloc(len * sizeof(char));
	if (ret)
		ft_memcpy(ret, str, len);
	return (ret);
}
