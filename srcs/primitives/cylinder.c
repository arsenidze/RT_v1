/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 22:14:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include <stdlib.h>
double			get_positive_root(double c[3]);
double			square(double x);

#define EPS 0.001

short		cylinder_intersection(void *v_cylinder, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_cylinder	*cylinder;
	t_vect3d	x;
	t_vect3d	v;
	double		coefficients[3];
	double		t;

	cylinder = (t_cylinder *)v_cylinder;
	x = start - cylinder->pos;
	v = cylinder->axis;
	coefficients[0] = VECT3D_DOT(ray_dir, ray_dir)
					- square(VECT3D_DOT(ray_dir, v));
	coefficients[1] = VECT3D_DOT(ray_dir, x)
					- VECT3D_DOT(ray_dir, v) * VECT3D_DOT(x, v);
	coefficients[2] = VECT3D_DOT(x, x)
					- square(VECT3D_DOT(x, v))
					- (cylinder->radius * cylinder->radius);
	t = get_positive_root(coefficients);
	if (t < 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + VECT3D_MULT_ON_SCALAR(ray_dir, t - EPS);
	return (1);
}

void		cylinder_delete(void *cylinder)
{
	free(cylinder);
}

t_vect3d	cylinder_get_normal(void *v_cylinder, t_vect3d point)
{
	t_cylinder	*cylinder;
	t_vect3d	v;
	t_vect3d	c;
	double		m;
	t_vect3d	normal;

	cylinder = (t_cylinder *)v_cylinder;
	v = cylinder->axis;
	c = cylinder->pos;
	m = (VECT3D_DOT(v, point) - VECT3D_DOT(v, c)) / VECT3D_DOT(v, v);
	normal = point - (c + VECT3D_MULT_ON_SCALAR(v, m));
	normal = VECT3D_NORM(normal);
	//ychitivat' vnytur' ili iznutri
	return (normal);
}

t_cylinder	*cylinder_new(t_vect3d pos, t_vect3d axis, double radius)
{
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (NULL);
	cylinder->pos = pos;
	cylinder->axis = axis;
	cylinder->radius = radius;
	return (cylinder);
}
