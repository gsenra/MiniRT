/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:08:06 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/05 20:33:58 bygsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	rt_identify(char *line, t_rt *rt)
{
	if (line[0] == 'R' && line[1] == ' ')
	{
		rt->reso.qty = rt->reso.qty + 1;
		if (rt->reso.qty > 1)
			errormsg(9);
		get_resolution(line, rt);
	}
	else if (line[0] == 'A' && line[1] == ' ')
	{
		rt->ambi.qty = rt->ambi.qty + 1;
		if (rt->ambi.qty > 1)
			errormsg(10);
		get_ambient(line, rt);
	}
	else if (line[0] == 'c' && line[1] == ' ')
		get_camera(line);
	else
		errormsg(2);
}
