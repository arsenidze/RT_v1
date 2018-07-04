/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:05:35 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 18:54:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vect3d.h"

void	camera_rotateOX(t_camera *camera, double angel)
{
	t_vect3d	matrixOX[3];

	vect3d_fill_rotateOX_matrix(matrixOX, angel);
	camera->dir = vect3d_mult_on_matrix(camera->dir, matrixOX);
	camera->up = vect3d_mult_on_matrix(camera->up, matrixOX);
	camera->left = vect3d_mult_on_matrix(camera->left, matrixOX);
}

void	camera_rotateOY(t_camera *camera, double angel)
{
	t_vect3d	matrixOY[3];

	vect3d_fill_rotateOY_matrix(matrixOY, angel);
	camera->dir = vect3d_mult_on_matrix(camera->dir, matrixOY);
	camera->up = vect3d_mult_on_matrix(camera->up, matrixOY);
	camera->left = vect3d_mult_on_matrix(camera->left, matrixOY);
}

void	camera_rotateOZ(t_camera *camera, double angel)
{
	t_vect3d	matrixOZ[3];

	vect3d_fill_rotateOZ_matrix(matrixOZ, angel);
	camera->dir = vect3d_mult_on_matrix(camera->dir, matrixOZ);
	camera->up = vect3d_mult_on_matrix(camera->up, matrixOZ);
	camera->left = vect3d_mult_on_matrix(camera->left, matrixOZ);
}
