/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_intersect_smth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:08:51 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 17:41:19 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "vect3d.h"
#include "object3d.h"
#include "intersection.h"

//short	is_intersect_obj(t_vect3d, t_vect3d, t_object3d *, t_vect3d *);

#define IS_INTERSECT_OBJ(s, r, o, i) o->intersection(o->primitive,s,r,i)

/*
**	function 'is_intersect_smth' don't fill 'normal' field in 
**	out 'intersection' parameter for optimization purpose.
*/
short	is_intersect_smth(t_scene *scene, t_vect3d start, t_vect3d ray_dir,
		t_intersection *intersection)
{
	int			i;
	t_object3d	*curr_object;
	t_vect3d	intersect_point;

	i = 0;
	while (scene->objects[i])
	{
		curr_object = scene->objects[i];
		if (IS_INTERSECT_OBJ(start, ray_dir, curr_object, &intersect_point))
		{
			intersection->orig = start;
			intersection->dest = intersect_point;
			intersection->ray_dir = ray_dir;
			intersection->hit_object = curr_object;
			return (1);
		}
		i++;
	}
	return (0);
}
