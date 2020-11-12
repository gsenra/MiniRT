/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:08:11 by lcouto            #+#    #+#             */
/*   Updated: 2020/11/12 15:20:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "../libft/libft.h"
# include "mlx_int.h"
# include "vector.h"
# include "elements.h"
# include "ray.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <ctype.h>
# include <stdio.h>

# define EPSILON 0.00001

/*
** Tracks how many of each parameter there is in a given .rt scene.
*/

typedef struct		s_qts
{
	int				reso;
	int				ambi;
	int				cam;
	int				lt;
	int				sp;
	int				pl;
	int				sq;
	int				cy;
	int				tr;
}					t_qts;

/*
** Holds values from the .rt file.
*/

typedef struct		s_rt
{
	t_qts			qts;
	t_reso			reso;
	t_ambi			ambi;
	t_cam			*cam;
	t_light			*light;
	t_sphere		*sphere;
	t_plane			*plane;
	t_square		*square;
	t_cylinder		*cylinder;
	t_triangle		*triangle;
}					t_rt;

/*
** Holds values needed for MiniLibX's functions.
*/

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*address;
	int				bpp;
	int				line_leng;
	int				endian;
}					t_mlx;

/*
** General parsing and error handling functions.
*/

void				init_rt(t_rt *rt);
void				init_sphere(t_rt *rt);
void				init_plane(t_rt *rt);
void				init_square(t_rt *rt);
void				init_cylinder(t_rt *rt);
void				init_triangle(t_rt *rt);
void				errormsg(int errornum);
void				*ec_malloc(size_t size);
void				*ec_calloc(size_t n, size_t size);
void				rt_identify(char *line, t_rt *rt);
int					get_index(char *line, int i);
int					get_index_nocomma(char *line, int i);
double				get_coord(char *line, int i);
int					get_color(char *line, int i);
t_color				fill_color(int r, int g, int b);

/*
** Window resolution parsing functions.
*/

void				get_resolution(char *line, t_rt *rt);

/*
** Ambient light and color parsing functions.
*/

void				get_ambient(char *line, t_rt *rt);
int					get_ambi_rgb(char *line, int check, int i, t_ambi *ambi);

/*
** Camera parsing functions.
*/

void				get_camera(char *line, t_rt *rt);
int					get_cam_view(char *line, int check, int i, t_cam *cam);
int					get_cam_pos(char *line, int check, int i, t_cam *cam);
int					get_cam_fov(char *line, int check, int i, t_cam *cam);

/*
** Light parsing functions.
*/

void				get_light(char *line, t_rt *rt);
int					get_light_pos(char *line, int check, int i, t_light *light);
int					get_light_color(char *line, int check, int i,
					t_light *light);

/*
** Sphere parsing functions.
*/

void				get_sphere(char *line, t_rt *rt);
int					get_sphere_center(char *line, int check, int i,
					t_sphere *light);
int					get_sphere_color(char *line, int check, int i,
					t_sphere *light);

/*
** Plane parsing functions.
*/

void				get_plane(char *line, t_rt *rt);
int					get_plane_pos(char *line, int check, int i, t_plane *light);
int					get_plane_color(char *line, int check, int i,
					t_plane *light);

/*
** Square parsing functions.
*/

void				get_square(char *line, t_rt *rt);
int					get_square_center(char *line, int check, int i,
					t_square *light);
int					get_square_color(char *line, int check, int i,
					t_square *light);
int					get_square_side(char *line, int check, int i,
					t_square *square);

/*
** Cylinder parsing functions.
*/

void				get_cylinder(char *line, t_rt *rt);
int					get_cylinder_pos(char *line, int check, int i,
					t_cylinder *light);
int					get_cylinder_color(char *line, int check, int i,
					t_cylinder *light);
int					get_cylinder_side(char *line, int check, int i,
					t_cylinder *cylinder);
int					get_cylinder_height(char *line, int check, int i,
					t_cylinder *cylinder);
int					get_cylinder_diameter(char *line, int check, int i,
					t_cylinder *cylinder);
int					get_cylinder_norm(char *line, int check, int i,
					t_cylinder *cylinder);

/*
** Triangle parsing functions.
*/

void				get_triangle(char *line, t_rt *rt);
int					get_triangle_p1(char *line, int check, int i,
					t_triangle *light);
int					get_triangle_p2(char *line, int check, int i,
					t_triangle *light);
int					get_triangle_p3(char *line, int check, int i,
					t_triangle *light);
int					get_triangle_color(char *line, int check, int i,
					t_triangle *light);

/*
** Free functions.
*/

void				free_lists(t_rt *rt);
void				free_camera(t_rt *rt);
void				free_light(t_rt *rt);
void				free_sphere(t_rt *rt);
void				free_plane(t_rt *rt);
void				free_square(t_rt *rt);
void				free_cylinder(t_rt *rt);
void				free_triangle(t_rt *rt);
void				free_intersecs(t_intersec *intersec);

/*
** Float utils
*/

int					double_equal(double a, double b);
double				radians_to_degrees(double rad);
double				degrees_to_radians(double degr);

/*
** Test functions.
*/

void				rt_window(t_rt *rt);
void				projectile_test(char *times);
void				matrix_test(int row, int col);
void				test_translation(double mx, double my, double mz,
					double px, double py, double pz);
void				test_scaling(double mx, double my, double mz,
					double px, double py, double pz);
void				test_rotation();
void				test_shearing(void);
void				test_chain_transform(void);
void				test_clock(t_rt *rt);
void				test_ray_position(void);
void				test_intersection(t_rt *rt);
void				test_transform_ray(void);
void				test_sphere_ray_transform(t_rt *rt);
void				test_canvas(t_rt *rt);

/*
** Render utilities.
*/

void				ft_pixelput(t_mlx *mlx, int x, int y, int color);
int					create_trgb(int t, int r, int g, int b);
int					close_wndw(int keycode, t_mlx *mlx);
int					close_program(void *ptr);

/*
** Core render functions.
*/

void				canvas(t_rt *rt);
void				raycaster(t_rt *rt, t_mlx *mlx);
void				render_sphere_transform(t_rt *rt);
t_tuple				sphere_normal(t_sphere *sphere, t_tuple point);
t_tuple				reflect(t_tuple in, t_tuple normal);

#endif
