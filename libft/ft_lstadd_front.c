#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *nw)
{
	if (nw)
		nw->next = *lst;
	*lst = nw;
}
