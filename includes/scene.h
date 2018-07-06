/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:51:12 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:20:58 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "object.h"
# include "light.h"

# define CAMERA_NEW_POS	vect3d(500, 0, 0)
# define CAMERA_NEW_DIR	vect3d(-1, 0, 0)
# define CAMERA_NEW_UP	vect3d(0, 0, 1)

typedef struct	s_scene
{
	t_camera	*camera;
	t_object	**objects;
	t_light		**lights;
}				t_scene;

t_scene			*scene_new(t_camera *camera, t_object **objects,
				t_light **lights);
void			scene_delete(t_scene *scene);

#endif
