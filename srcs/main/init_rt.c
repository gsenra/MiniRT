/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:16:27 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/23 20:42:45 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		init_polys(t_rt *rt)
{
	rt->sphere = NULL;
	rt->square = NULL;
	rt->plane = NULL;
	rt->cylinder = NULL;
	rt->triangle = NULL;
	// init_sphere(rt);
	// init_plane(rt);
	// // init_square(rt);
	// init_cylinder(rt);
	// init_triangle(rt);
}

static void		init_light(t_rt *rt)
{
	t_light	*baselight;

	baselight = (t_light *)ec_malloc(sizeof(t_light));
	baselight->pos.x = 0;
	baselight->pos.y = 0;
	baselight->pos.z = 0;
	baselight->pos.w = 0;
	baselight->light = 0;
	baselight->color.r = 0;
	baselight->color.g = 0;
	baselight->color.b = 0;
	baselight->intensity = create_rgba(1, 1, 1, 1);
	baselight->next = NULL;
	rt->light = baselight;
}

static void		init_qts(t_rt *rt)
{
	rt->qts = (t_qts) {0};
}

static void		init_camera(t_rt *rt)
{
	t_cam	*basecam;

	basecam = (t_cam *)ec_malloc(sizeof(t_cam));
	basecam->view.x = 0;
	basecam->view.y = 0;
	basecam->view.z = 0;
	basecam->pos.x = 0;
	basecam->pos.y = 0;
	basecam->pos.z = 0;
	basecam->pos.w = 0;
	basecam->fov = 0;
	basecam->origin = create_tuple(0, 0, 0, 1);
	basecam->next = NULL;
	rt->cam = basecam;
}

void			init_rt(t_rt *rt)
{
	t_reso	reso;
	t_ambi	ambi;

	init_qts(rt);
	reso.width = 0;
	reso.height = 0;
	ambi.light = 0.0;
	ambi.color.b = 0;
	ambi.color.r = 0;
	ambi.color.g = 0;
	rt->reso = reso;
	rt->ambi = ambi;
	init_camera(rt);
	init_light(rt);
	init_polys(rt);
}
