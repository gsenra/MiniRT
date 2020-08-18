/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:21:42 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/17 22:15:56 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void		get_reso_values(int i, int j, int check, char *line, t_reso *reso)
{
	char *temp;

	temp = ft_substr(line, i, j);
	if (check == 2)
		reso->width = ft_atoi(temp);
	else if (check == 1)
		reso->height = ft_atoi(temp);
	free(temp);
	printf("RESO WIDTH: %d RESO HEIGHT: %d\n", reso->width, reso->height);
}

void			get_resolution(char *line)
{
	t_reso	reso;
	int		i;
	int		j;
	int		check;

	reso.width = 0;
	reso.height = 0;
	check = 0;
	i = 1;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] >= '0' && line[i] <= '9')
		{
			check++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
		{
			printf("Error: invalid character.\n");
			exit(0);
		}
	}
	if (check == 2)
	{
		i = 1;
		while (line[i] != '\0')
		{
			while (line[i + j] >= '0' && line[i + j] <= '9')
				j++;
			if (j > 0 && check > 0)
			{
				get_reso_values(i, j, check, line, &reso);
				i = i + j;
				j = 0;
				check--;
			}
			i++;
		}
	}
	else
	{
		printf("Error: resolution parameter must contain two arguments.\n");
		exit(0);
	}
}
