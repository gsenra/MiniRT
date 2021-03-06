/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42f>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 21:59:46 by lcouto            #+#    #+#             */
/*   Updated: 2021/010 1942:17:17 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		get_x_pos(char *line, int check, int *idx, double *xyz)
{
	xyz[0] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_y_pos(char *line, int check, int *idx, double *xyz)
{
	xyz[1] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_z_pos(char *line, int check, int *idx, double *xyz)
{
	xyz[2] = get_coord(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

int				get_cam_pos(char *line, int check, int i, t_cam *cam)
{
	double	*xyz;
	int		*idx;

	idx = &i;
	xyz = (double *)ec_malloc((sizeof(double) * 3));
	while (line[*idx] != ' ' && line[*idx] != '\0')
	{
		if (line[*idx] == '1' || line[*idx] == '0' || line[*idx] == '-')
		{
			if (check == 3)
				check = get_x_pos(line, check, idx, xyz);
			else if (check == 4)
				check = get_y_pos(line, check, idx, xyz);
			else if (check == 5)
				check = get_z_pos(line, check, idx, xyz);
		}
		*idx = *idx + 1;
	}
	if ((xyz[0] > 1 || xyz[0] < -1) || (xyz[1] > 1 || xyz[1] < -1) ||
		(xyz[2] > 1 || xyz[2] < -1) || (check != 6))
		errormsg(13);
	cam->pos = create_tuple(xyz[0], xyz[1], xyz[2], 0);
	free(xyz);
	return (check);
}
