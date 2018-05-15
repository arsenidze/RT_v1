/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 22:13:44 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include <stdlib.h>
double			get_positive_root(double c[3]);
double			square(double x);

#define EPS 0.001

short		cone_intersection(void *v_cone, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_cone	*cone;
	t_vect3d	x;
	t_vect3d	v;
	double		coefficients[3];
	double		t;

	cone = (t_cone *)v_cone;
	x = start - cone->pos;
	v = cone->axis;
	coefficients[0] = VECT3D_DOT(ray_dir, ray_dir)
					- square(VECT3D_DOT(ray_dir, v))
					* (1 + cone->k * cone->k);
	coefficients[1] = VECT3D_DOT(ray_dir, x)
					- VECT3D_DOT(ray_dir, v) * VECT3D_DOT(x, v)
					* (1 + cone->k * cone->k);
	coefficients[2] = VECT3D_DOT(x, x)
					- square(VECT3D_DOT(x, v))
					* (1 + cone->k * cone->k);
	t = get_positive_root(coefficients);
	if (t < 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + VECT3D_MULL_ON_SCALAR(ray_dir, t - EPS);
	return (1);
}

void		cone_delete(void *cone)
{
	free(cone);
}

t_vect3d	cone_get_normal(void *v_cone, t_vect3d point)
{
	t_cone	*cone;
	t_vect3d	v;
	t_vect3d	c;
	double		m;
	t_vect3d	normal;

	cone = (t_cone *)v_cone;
	v = cone->axis;
	c = cone->pos;
	m = (VECT3D_DOT(v, point) - VECT3D_DOT(v, c)) / VECT3D_DOT(v, v);
	normal = point - (c + VECT3D_MULL_ON_SCALAR(v, m * (1 + cone->k * cone->k)));
	normal = VECT3D_NORM(normal);
	//ychitivat' vnytur' ili iznutri
	return (normal);
}

t_cone	*cone_new(t_vect3d pos, t_vect3d axis, double k)
{
	t_cone	*cone;

	if (!(cone = malloc(sizeof(t_cone))))
		return (NULL);
	cone->pos = pos;
	cone->axis = axis;
	cone->k = k;
	return (cone);
}
