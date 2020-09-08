/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:01:19 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/08 17:57:55 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	rt_identify(char *line, t_rt *rt)
{
	if (line[0] == 'R' && line[1] == ' ')
	{
		rt->qts.reso = rt->qts.reso + 1;
		if (rt->qts.reso > 1)
			errormsg(9);
		get_resolution(line, rt);
	}
	else if (line[0] == 'A' && line[1] == ' ')
	{
		rt->qts.ambi = rt->qts.ambi + 1;
		if (rt->qts.ambi > 1)
			errormsg(10);
		get_ambient(line, rt);
	}
	else if (line[0] == 'c' && line[1] == ' ')
		get_camera(line, rt);
	else if (line[0] == 'l' && line[1] == ' ')
		get_light(line, rt);
	else
		errormsg(2);
}
