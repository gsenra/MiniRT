/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:31:13 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/08 16:49:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color		fill_color(int r, int g, int b)
{
	t_color	fill;

	fill.r = r;
	fill.g = g;
	fill.b = b;
	return (fill);
}
