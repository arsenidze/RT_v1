/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:51:12 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 16:07:57 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "object3d.h"
# include "light.h"

/*
# define SCENE_SUCCESS 0
# define SCENE_FAILURE 1
*/

typedef struct	s_scene
{
	t_camera	*camera;
	t_object3d	**objects;
	t_light		**lights;
}				t_scene;

t_scene			*scene_init(t_camera *camera, t_object3d **objects,
				t_light **lights);
void			scene_clear(t_scene *scene);

#endif
