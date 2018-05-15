/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:21:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 17:24:55 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "scene.h"
#include "intersection.h"
short	is_intersect_smth(t_scene *, t_vect3d , t_vect3d, t_intersection *);

#define AMBIENT 	1.
#define DIFFUSE 	2.
#define SPECULAR	0.5

#define SPECULAR_POW	200

static double	get_diffuse_effect(t_light *light,
				t_intersection *intersection, t_vect3d ray_to_light,
				double sq_dist)
{
	double	cos_between_light_and_normal;

	(void)light;
	(void)sq_dist;
	cos_between_light_and_normal = VECT3D_COS_NORMED(ray_to_light,
			intersection->normal);
	if (cos_between_light_and_normal > 0)
	{
		return (DIFFUSE * cos_between_light_and_normal);
	}
	return (0);
}

static double	get_specular_effect(t_light *light,
				t_intersection *intersection, t_vect3d ray_to_light,
				double sq_dist)
{
	t_vect3d	bisector;
	double		cos_between_bisector_and_normal;

	bisector = ray_to_light + (-intersection->ray_dir);
	bisector = VECT3D_NORM(bisector);

	(void)light;
	(void)sq_dist;
	cos_between_bisector_and_normal = VECT3D_COS_NORMED(bisector,
			intersection->normal);
	if (cos_between_bisector_and_normal > 0)
	{
		return (SPECULAR * pow(cos_between_bisector_and_normal, SPECULAR_POW));
	}
	return (0);
}

t_color	apply_light(t_scene *scene, t_intersection *intersection)
{
	double 			total_light;
	int				i;
	t_vect3d		ray_to_light;
	double			sq_dist;
	t_intersection	tmp_intersection;

	total_light = AMBIENT;
	i = -1;
	while (scene->lights[++i])
	{
		ray_to_light = scene->lights[i]->pos - intersection->dest;;
		sq_dist = VECT3D_SQ_LEN(ray_to_light);
		ray_to_light = VECT3D_DIV_ON_SCALAR(ray_to_light, sqrt(sq_dist));
		if (is_intersect_smth(scene, intersection->dest, ray_to_light,
			&tmp_intersection))
		{
			if (VECT3D_SQ_LEN((scene->lights[i]->pos - tmp_intersection.orig))
			> VECT3D_SQ_LEN((tmp_intersection.dest - tmp_intersection.orig)))
				continue ;
		}
		intersection->normal = GET_NORMAL(intersection->hit_object,
								intersection->dest);
		total_light += get_diffuse_effect(scene->lights[i], intersection,
						ray_to_light, sq_dist);
		total_light += get_specular_effect(scene->lights[i], intersection,
						ray_to_light, sq_dist);
	}
	return (COLOR_MULL(intersection->hit_object->color.rgba, total_light));	
}
