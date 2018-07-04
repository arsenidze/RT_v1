/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_fill_rotate_matrix.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:36:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 18:41:07 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"

void		vect3d_fill_rotateOX_matrix(t_vect3d m[3], double angel)
{
	double	cosA;
	double	sinA;

	cosA = cos(angel);
	sinA = sin(angel);
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = cosA;
	m[1][2] = -sinA;
	m[2][0] = 0;
	m[2][1] = sinA;
	m[2][2] = cosA;
}

void		vect3d_fill_rotateOY_matrix(t_vect3d m[3], double angel)
{
	double	cosA;
	double	sinA;

	cosA = cos(angel);
	sinA = sin(angel);
	m[0][0] = cosA;
	m[0][1] = 0;
	m[0][2] = sinA;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = -sinA;
	m[2][1] = 0;
	m[2][2] = cosA;
}

void		vect3d_fill_rotateOZ_matrix(t_vect3d m[3], double angel)
{
	double	cosA;
	double	sinA;

	cosA = cos(angel);
	sinA = sin(angel);
	m[0][0] = cosA;
	m[0][1] = -sinA;
	m[0][2] = 0;
	m[1][0] = sinA;
	m[1][1] = cosA;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
}
