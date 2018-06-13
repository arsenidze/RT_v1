/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:15:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/01 16:19:16 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"
#include "vect3d.h"
t_color			trace_ray(t_scene *scene, t_vect3d ray_dir);

/*
**	0.86602540378 - 1 / (2 * tan(30deg))
**	30deg = half of FOV
*/
#define DIST_TO_PP (TEX_W * 0.86602540378)

static t_vect3d	get_ray_dir(t_camera *camera, int x, int y)
{
	t_vect3d	ray_dir;
	double		dir_factor;
	double		up_factor;
	double		left_factor;

	dir_factor = DIST_TO_PP;
	up_factor = -(y - TEX_H / 2);
	left_factor = (x - TEX_W / 2);
	ray_dir = VECT3D_MULL_ON_SCALAR(camera->dir, dir_factor)
			+ VECT3D_MULL_ON_SCALAR(camera->up, up_factor)
			+ VECT3D_MULL_ON_SCALAR(camera->left, left_factor);
	ray_dir = VECT3D_NORM(ray_dir);
	return (ray_dir);
}

void			render_scene(t_pixel *pixels, t_scene *scene)
{
	int			j;
	int			i;
	t_vect3d	ray_dir;
	t_color		color;

	j = 0;
	while (j < TEX_H)
	{
		i = 0;
		while (i < TEX_W)
		{
			ray_dir = get_ray_dir(scene->camera, i, j);
			color = trace_ray(scene, ray_dir);
			SET_PIXEL(pixels, i, j, color.value);
			i++;
		}
		j++;
	}
}
