/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:36:57 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/27 19:01:54 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_intersec	*init_intersec_list(t_intersec *list)
{
	list->count = 0;
	list->t1 = 0;
	list->t2 = 0;
	list->qty = 0;
	list->next = NULL;
	return (list);
}

void		push_intersec(t_intersec *head, t_intersec *new)
{
	t_intersec *current;

	current = head;
	new->next = NULL;
	if (current->qty == 0)
	{
		current->count = new->count;
		current->t1 = new->t1;
		current->t2 = new->t2;
		current->poly = new->poly;
		current->next = NULL;
		current->qty = current->qty + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_intersec *)ec_malloc(sizeof(t_intersec));
	current->next->count = new->count;
	current->next->t1 = new->t1;
	current->next->t2 = new->t2;
	current->next->poly = new->poly;
	current->next->next = new->next;
	current->next->qty = current->qty + 1;
}

t_intersec	*intersec_hit(t_intersec *head)
{
	t_intersec	*hit;
	t_intersec	*tmp_intersec;
	t_intersec	*current;

	current = head;
	hit = NULL;
	while (current != NULL)
	{
		tmp_intersec = current;
		if (!hit && (tmp_intersec->t1 >= 0 || tmp_intersec->t2 >= 0))
			hit = tmp_intersec;
		else if (tmp_intersec->t1 >= 0 && tmp_intersec->t1 < hit->t1 &&
		tmp_intersec->t1 < hit->t2)
			hit = tmp_intersec;
		else if (tmp_intersec->t2 >= 0 && tmp_intersec->t2 < hit->t1 &&
		tmp_intersec->t2 < hit->t2)
			hit = tmp_intersec;
		current = current->next;
	}
	if (hit && hit->count == 0)
		hit = NULL;
	return (hit);
}