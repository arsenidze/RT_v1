/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 22:08:07 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include <stdlib.h>
//double			get_positive_root(double c[3]);
double			square(double x);

#define EPS 0.001

short		plane_intersection(void *v_plane, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_plane		*plane;
	t_vect3d	x;
	double		cos_between_ray_and_normal;
	double		t;

	plane = (t_plane *)v_plane;
	x = start - plane->pos;
	cos_between_ray_and_normal = VECT3D_DOT(ray_dir, plane->normal);
	if (cos_between_ray_and_normal == 0)
		return (0);
	t = -VECT3D_DOT(x, plane->normal) / cos_between_ray_and_normal;
	if (t <= 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + VECT3D_MULT_ON_SCALAR(ray_dir, t - EPS);
	return (1);
}

void		plane_delete(void *plane)
{
	free(plane);
}

t_vect3d	plane_get_normal(void *v_plane, t_vect3d point)
{
	t_plane		*plane;
//	double		cos_between_ray_and_normal;

	(void)point;
	plane = (t_plane *)v_plane;
//	cos_between_ray_and_normal = VECT3D_DOT(ray_dir, plane->normal);
//	if (cos_between_ray_and_normal < 0)
//		return (-plane->normal);
	return (plane->normal);
}

t_plane	*plane_new(t_vect3d pos, t_vect3d normal)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		return (NULL);
	plane->pos = pos;
	plane->normal = normal;
	return (plane);
}
