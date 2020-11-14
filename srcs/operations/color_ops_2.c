/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:28:55 by lcouto            #+#    #+#             */
/*   Updated: 2020/11/14 14:35:09 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_rgba	normalize_color(int r, int g, int b)
{
	t_rgba	norm;

	norm.r = (double)r / 255;
	norm.g = (double)g / 255;
	norm.b = (double)b / 255;
	norm.a = 1;
	return (norm);
}

t_color	denorm_color(t_rgba norm)
{
	t_color	denorm;

	denorm.r = (int)(norm.r * 255);
	denorm.g = (int)(norm.g * 255);
	denorm.b = (int)(norm.b * 255);
	return (denorm);
}

t_rgba	create_rgba(double r, double g, double b, double a)
{
	t_rgba new;

	if ((r < 0 || r > 1) || (g < 0 || g > 1) ||
		(b < 0 || b > 1) || (a < 0 || a > 1))
		errormsg(36);
	new.r = r;
	new.g = g;
	new.b = b;
	new.a = a;
	return (new);
}

t_rgba	tuple_to_rgba(t_tuple tuple)
{
	t_rgba new;

	if ((tuple.x < 0 || tuple.x > 1) || (tuple.y < 0 || tuple.y > 1) ||
		(tuple.z < 0 || tuple.z > 1))
		errormsg(36);
	if (tuple.w != 0 && tuple.w != 1)
		errormsg(32);
	new.r = tuple.x;
	new.g = tuple.y;
	new.b = tuple.z;
	new.a = 1;
	return (new);
}
