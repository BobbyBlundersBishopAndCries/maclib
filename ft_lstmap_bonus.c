/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:56:35 by mohabid           #+#    #+#             */
/*   Updated: 2024/10/28 14:56:39 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *result = NULL;
    t_list *current = NULL;

    if (!lst || !f)
        return (NULL);

    while (lst != NULL)
    {
        t_list *new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node)
        {
            if (del)
                ft_lstclear(&result, del);
            return (NULL);
        }

        new_node->content = f(lst->content);

        if (!new_node->content)
        {
            free(new_node);
            if (del)
                ft_lstclear(&result, del);
            return (NULL);
        }

        new_node->next = NULL;

        if (result == NULL)
            result = new_node;
        else
            current->next = new_node;

        current = new_node;
        lst = lst->next;
    }

    return (result);
}
