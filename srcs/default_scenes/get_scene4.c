/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:13:55 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 22:47:35 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "cylinder.h"
#include "cone.h"
#include "plane.h"
#include <stdlib.h>

#define FOURTH_SCENE_NOBJECTS	1
#define FOURTH_SCENE_NLIGHTS	1

#define INVER_SQRT_TWO	0.70710678118

t_scene	*get_scene4(void)
{
	t_scene		*scene;
	t_camera	*camera;
	t_object	**objects;
	t_light		**lights;

	if (!(objects = malloc(sizeof(t_object *) * (FOURTH_SCENE_NOBJECTS + 1))))
		return (NULL);
	objects[FOURTH_SCENE_NOBJECTS] = NULL;
	if (!(lights = malloc(sizeof(t_light *) * (FOURTH_SCENE_NLIGHTS + 1))))
		return (NULL);
	lights[FOURTH_SCENE_NLIGHTS] = NULL;
	camera = camera_new(CAMERA_NEW_POS, CAMERA_NEW_DIR, CAMERA_NEW_UP);
	objects[0] = object_new(
	VECT3D_3(vect3d(0.1, 0., 0.2), vect3d(0.3, 0.3, 0.), vect3d(0.1, 0., 0.)),
		PRIMITIVE(sphere, vect3d(0, 100, 0), 100));
	lights[0] = light_new(vect3d(0, -20, 0), VECT3D_3(vect3d(1, 1, 1),
		vect3d(1, 1, 1), vect3d(1, 1, 1)));
	scene = scene_new(camera, objects, lights);
	return (scene);
}
