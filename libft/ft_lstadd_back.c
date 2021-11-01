#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = nw;
	}
	else
		*lst = nw;
}
