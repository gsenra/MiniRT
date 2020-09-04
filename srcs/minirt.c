/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:26:27 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/04 19:52:16 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_rt	rt;

	init_rt(&rt);
	if (argc == 1)
		errormsg(0);
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else if (argc > 2)
		errormsg(1);
	while (get_next_line(fd, &line) == 1)
	{
		rt_identify(line, &rt);
		free(line);
	}
	rt_window(&rt);
	return (0);
}
