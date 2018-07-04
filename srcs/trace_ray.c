/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 22:41:22 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "color.h"
#include "vect3d.h"
#include "intersection.h"

//short	is_intersect_smth(t_scene *, t_vect3d, t_vect3d, t_intersection *);
short	find_closest_intersection(t_scene *, t_vect3d, t_vect3d, t_intersection *);
t_color	apply_light(t_scene *, t_intersection *);

#define BACKGROUND_COLOR COLOR(0x00000000)

t_color	trace_ray(t_scene *scene, t_vect3d ray_dir)
{
	t_intersection	intersection;
	t_color			res_color;

	if (find_closest_intersection(scene, scene->camera->pos, ray_dir,
		&intersection))
	{
		res_color = apply_light(scene, &intersection);
	//	res_color = intersection.hit_object->color;
		return (res_color);
	}
	return (BACKGROUND_COLOR);	
}
