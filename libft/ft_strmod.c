#include "libft.h"

void	ft_strtoupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		++str;
	}
}

void	ft_strtolower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		++str;
	}
}
