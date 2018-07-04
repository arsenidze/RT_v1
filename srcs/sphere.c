/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 11:25:10 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include <stdlib.h>
double			get_positive_root(double c[3]);

#define EPS 0.001

short		sphere_intersection(void *v_sphere, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_sphere	*sphere;
	double		coefficients[3];
	double		t;

	sphere = (t_sphere *)v_sphere;
	coefficients[0] = VECT3D_DOT(ray_dir, ray_dir);
	coefficients[1] = VECT3D_DOT(start, ray_dir)
						- VECT3D_DOT(sphere->pos, ray_dir); 
	coefficients[2] = VECT3D_DOT(start, start)
						- 2 * VECT3D_DOT(start, sphere->pos)
						+ VECT3D_DOT(sphere->pos, sphere->pos)
						- (sphere->radius * sphere->radius);
	t = get_positive_root(coefficients);
	if (t < 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + VECT3D_MULL_ON_SCALAR(ray_dir, t - EPS);
	return (1);
}

void		sphere_delete(void *sphere)
{
	free(sphere);
}

t_vect3d	sphere_get_normal(void *v_sphere, t_vect3d point)
{
	t_sphere	*sphere;
	t_vect3d	normal;

	sphere = (t_sphere *)v_sphere;
	normal = point - sphere->pos;
	normal = VECT3D_NORM(normal);
	//ychitivat' vnytur' ili iznutri
	return (normal);
}

//void		sphere_fill_coeff(t_object *obj, double c[3], t_vect3d start,
//				t_vect3d ray_dir)
//{
//	t_sphere	*sphere;
//
//	sphere = (t_sphere *)obj->sphere;
//	c[0] = VECT3D_DOT(ray_dir, ray_dir);
//	c[1] = VECT3D_DOT(start, ray_dir)
//			- VECT3D_DOT(sphere->pos, ray_dir); 
//	c[2] = VECT3D_DOT(start, start)
//			- 2 * VECT3D_DOT(start, sphere->pos)
//			+ VECT3D_DOT(sphere->pos, sphere->pos)
//			- (sphere->radius * sphere->radius);
//}

t_sphere	*sphere_new(t_vect3d pos, double radius)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->pos = pos;
	sphere->radius = radius;
	return (sphere);
}
