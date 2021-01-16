/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:37:20 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/16 16:33:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_plane(t_plane *head, t_plane *new_plane, t_rt *rt)
{
	t_plane *current;

	current = head;
	new_plane->next = NULL;
	if (rt->qts.pl == 0)
	{
		head->pos = new_plane->pos;
		head->norm = new_plane->norm;
		head->color = new_plane->color;
		head->next = new_plane->next;
		rt->qts.pl = rt->qts.pl + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_plane *)ec_malloc(sizeof(t_plane));
	current->next->pos = new_plane->pos;
	current->next->norm = new_plane->norm;
	current->next->color = new_plane->color;
	current->next->next = new_plane->next;
	rt->qts.pl = rt->qts.pl + 1;
}

static void		plane_loop(char *line, int i, int check, t_plane *plane)
{
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (check == 0)
			{
				check = get_plane_pos(line, check, i, plane);
				i = get_index(line, i);
			}
			else if (check == 3)
			{
				check = get_plane_norm(line, check, i, plane);
				i = get_index(line, i);
			}
			else if (check == 6)
			{
				check = get_plane_color(line, check, i, plane);
				i = get_index(line, i);
			}
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
}

void			get_plane(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_plane		*plane;

	plane = (t_plane *)ec_malloc(sizeof(t_plane));
	check = 0;
	i = 2;
	plane_loop(line, i, check, plane);
	push_plane(rt->plane, plane, rt);
	free(plane);
}
