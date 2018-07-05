/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:11:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 20:13:19 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT3D_H
# define VECT3D_H

# include <math.h>

typedef double	t_vect3d __attribute__((vector_size(sizeof(double)*3)));

# define X 0
# define Y 1
# define Z 2

# define VECT3D(x, y, z) (t_vect3d){(x), (y), (z)}
# define VECT3D_MULT_ON_SCALAR(v, a) ((v) * VECT3D(a, a, a))
# define VECT3D_DIV_ON_SCALAR(v, a) ((v) / VECT3D(a, a, a))
# define VECT3D_LEN(v) (sqrt(VECT3D_SQ_LEN(v)))
# define VECT3D_NORM(v) VECT3D_DIV_ON_SCALAR((v), VECT3D_LEN(v))
# define VECT3D_SQ_LEN(v) ((v)[X] * (v)[X] + (v)[Y] * (v)[Y] + (v)[Z] * (v)[Z])
# define VECT3D_DOT(v1, v2) (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z])
# define VECT3D_CROSS(v1, v2) VECT3D(v1[Y] * v2[Z] - v1[Z] * v2[Y], \
									v1[Z] * v2[X] - v1[X] * v2[Z], \
									v1[X] * v2[Y] - v1[Y] * v2[X])
# define VECT3D_COS(v1, v2) (VECT3D_DOT(v1, v2) / (VECT3D_LEN(v1) * VECT3D_LEN(v2)))
# define VECT3D_COS_NORMED(v1, v2) VECT3D_DOT(v1, v2)
# define VECT3D_APPLY(v,f,...) VECT3D(f(v[X],__VA_ARGS__),f(v[Y],__VA_ARGS__),f(v[Z],__VA_ARGS__))
//t_vect3d		vect3d_cross(t_vect3d v1, t_vect3d v2);
short		vect3d_is_in_range(t_vect3d v, double a, double b);
short		vect3d_is_in_range_abs(t_vect3d v, double a, double b);
t_vect3d	vect3d_mult_on_matrix(t_vect3d v, t_vect3d m[3]);
void		vect3d_fill_rotateOX_matrix(t_vect3d m[3], double angel);
void		vect3d_fill_rotateOY_matrix(t_vect3d m[3], double angel);
void		vect3d_fill_rotateOZ_matrix(t_vect3d m[3], double angel);

//t_vect3d	vect3d(double x, double y, double z); (t_vect3d){(x), (y), (z)}
//t_vect3d	vect3d_mult_on_scalar(v, a) ((v) * VECT3D(a, a, a))
//t_vect3d	vect3d_div_on_scalar(v, a) ((v) / VECT3D(a, a, a))
//double		vect3d_len(v) (sqrt(VECT3D_SQ_LEN(v)))
//t_vect3d	vect3d_norm(v) VECT3D_DIV_ON_SCALAR((v), VECT3D_LEN(v))
//double		vect3d_sq_len(v) ((v)[X] * (v)[X] + (v)[Y] * (v)[Y] + (v)[Z] * (v)[Z])
//t_vect3d	vect3d_dot(v1, v2) (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z])
//t_vect3d	vect3d_cross(v1, v2) VECT3D(v1[Y] * v2[Z] - v1[Z] * v2[Y], \
//									v1[Z] * v2[X] - v1[X] * v2[Z], \
//									v1[X] * v2[Y] - v1[Y] * v2[X])
# define VECT3D_COS(v1, v2) (VECT3D_DOT(v1, v2) / (VECT3D_LEN(v1) * VECT3D_LEN(v2)))
# define VECT3D_COS_NORMED(v1, v2) VECT3D_DOT(v1, v2)

#endif
