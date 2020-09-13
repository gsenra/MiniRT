/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:06:37 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/13 17:27:44 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_light(t_light *head, t_light *new_light, t_rt *rt)
{
	t_light *current;

	current = head;
	new_light->next = NULL;
	if (rt->qts.lt == 0)
	{
		head->pos = new_light->pos;
		head->light = new_light->light;
		head->color = new_light->color;
		head->next = new_light->next;
		rt->qts.lt = rt->qts.lt + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_light *)ec_malloc(sizeof(t_light));
	current->next->pos = new_light->pos;
	current->next->light = new_light->light;
	current->next->color = new_light->color;
	current->next->next = new_light->next;
	rt->qts.lt = rt->qts.lt + 1;
}

static int		get_light_light(char *line, int check, int i, t_light *light)
{
	double	lumi;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] == '1' || line[i] == '0') && check == 3)
		{
			lumi = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	if (lumi > 1 || lumi < 0)
		errormsg(16);
	light->light = lumi;
	return (check);
}

static void		light_loop(char *line, int i, int check, t_light *light)
{
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (check == 0)
			{
				check = get_light_pos(line, check, i, light);
				i = get_index(line, i);
			}
			else if (check == 3)
			{
				check = get_light_light(line, check, i, light);
				i = get_index(line, i);
			}
			else if (check == 4)
			{
				check = get_light_color(line, check, i, light);
				i = get_index(line, i);
			}
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
}

void			get_light(char *line, t_rt *rt)
{
	int		i;
	int		check;
	t_light	*light;

	light = (t_light *)ec_malloc(sizeof(t_light));
	check = 0;
	i = 1;
	light_loop(line, i, check, light);
	push_light(rt->light, light, rt);
	free(light);
}
