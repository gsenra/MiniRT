/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_p1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:59:20 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/09/13 17:27:44 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		get_x_p1(char *line, int check, int *idx, double *xyz)
{
	xyz[0] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_y_p1(char *line, int check, int *idx, double *xyz)
{
	xyz[1] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_z_p1(char *line, int check, int *idx, double *xyz)
{
	xyz[2] = get_coord(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

int				get_triangle_p1(char *line, int check, int i,
t_triangle *triangle)
{
	double	*xyz;
	int		*idx;

	idx = &i;
	xyz = (double *)ec_malloc((sizeof(double) * 3));
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[*idx] >= '0' && line[*idx] <= '9') || line[*idx] == '-')
		{
			if (check == 0)
				check = get_x_p1(line, check, idx, xyz);
			else if (check == 1)
				check = get_y_p1(line, check, idx, xyz);
			else if (check == 2)
				check = get_z_p1(line, check, idx, xyz);
		}
		*idx = *idx + 1;
	}
	if (check != 3)
		errormsg(28);
	triangle->p1 = fill_coord(xyz[0], xyz[1], xyz[2]);
	free(xyz);
	return (check);
}
