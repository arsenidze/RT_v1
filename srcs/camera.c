/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:54:00 by amelihov          #+#    #+#             */
/*   Updated: 2018/04/19 14:34:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "errors.h"
#include <stdlib.h>

void			camera_clear(t_camera *camera)
{
	if (!camera)
		return ;
	free(camera);
}

static void		*camera_err_exit(t_camera *camera, char *err)
{
	camera_clear(camera);
	try_set_err(err);
	return (NULL);
}

t_camera		*camera_init(t_vect3d pos, t_vect3d dir, t_vect3d up)
{
	t_camera	*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		return (camera_err_exit(camera, CAMERA_INIT_MEM));
	camera->pos = pos;
	camera->dir = dir;
	camera->up = up;
	camera->left = VECT3D_CROSS(dir, up);
	return (camera);
}
