/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:35:36 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:37:58 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
///TO REMOVE
//

void	free_content(void *lst)
{
	t_list	*temp;

	temp = lst;
	temp->content = NULL;
	temp->next = NULL;
}

void	f(void *lst)
{
	t_list	*temp;

	temp = lst;
	temp->content = "x";
}

void	ft_print_list(t_list *lst)
{
	t_list	*current;

	current = lst;
	printf("%s\n", (char *)current -> content);
	if (current->next != NULL)
	{
		current = current->next;
		ft_print_list(current);
	}
}



int main()
{
	int i = 0;

	t_list * head;
	head = ft_lstnew("000");

	i = ft_lstsize(head);
	printf("node count: %d\n", i);
	t_list * new;
	new = (t_list *) malloc(sizeof(t_list));
	new -> content = "aaa";
	ft_lstadd_back(&head, new);
	
	t_list * new2;
	new2 = (t_list *) malloc(sizeof(t_list));	
	new2 -> content = "bbb";
	ft_lstadd_back(&head, new2);

	t_list * new3;
	new3 = (t_list *) malloc(sizeof(t_list));
	new3 -> content = "ccc";
	ft_lstadd_back(&head, new3);

	t_list * new4;
	new4 = (t_list *) malloc(sizeof(t_list));
	new4 -> content = "ddd";
	ft_lstadd_back(&head, new4);

	t_list * new5;
	new5 = (t_list *) malloc(sizeof(t_list));
	new5 -> content = "eee";
	ft_lstadd_back(&head, new5);

	i = ft_lstsize(head);
	printf("node count: %d\n", i);

	t_list * new6;
	new6 = (t_list *) malloc(sizeof(t_list));
	new6 -> content = "!";
	ft_lstadd_front(&head, new6);

	i = ft_lstsize(head);
	printf("node count: %d\n", i);

	ft_print_list(head);
	printf("\n");

	ft_lstiter(head, &f);
	ft_print_list(head);
//	ft_lstclear(&head, &free_content);
	
//	i = ft_lstsize(head);
//      printf("\nnode count: %d\n", i);
	
	return 0;
}*/
