#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*nxt;

	nxt = *lst;
	while (nxt)
	{
		cur = nxt;
		nxt = cur->next;
		ft_lstdelone(cur, del);
	}
	*lst = NULL;
}
