/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:14:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 22:11:36 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "cylinder.h"
#include <stdlib.h>

#define SECOND_SCENE_NOBJECTS	1
#define SECOND_SCENE_NLIGHTS	1

#define CAMERA_NEW_POS	vect3d(500, 0, 0)
#define CAMERA_NEW_DIR	vect3d(-1, 0, 0)
#define CAMERA_NEW_UP	vect3d(0, 0, 1)

t_scene	*get_scene2(void)
{
	t_scene		*scene;
	t_camera	*camera;
	t_object	**objects;
	t_light		**lights;

	if (!(objects = malloc(sizeof(t_object *) * (SECOND_SCENE_NOBJECTS + 1))))
		return (NULL);
	objects[SECOND_SCENE_NOBJECTS] = NULL;
	if (!(lights = malloc(sizeof(t_light *) * (SECOND_SCENE_NLIGHTS + 1))))
		return (NULL);
	lights[SECOND_SCENE_NLIGHTS] = NULL;
	camera = camera_new(CAMERA_NEW_POS, CAMERA_NEW_DIR, CAMERA_NEW_UP);
	scene = scene_new(camera, objects, lights);
	objects[0] = object_new(
	VECT3D_3(vect3d(0.1, 0., 0.2), vect3d(0.3, 0.3, 0.), vect3d(0.1, 0., 0.)),
		PRIMITIVE(sphere, vect3d(0, 100, 0), 100));
	lights[0] = light_new(vect3d(0, -20, 0), VECT3D_3(vect3d(1, 1, 1),
		vect3d(1, 1, 1), vect3d(1, 1, 1)));
	scene = scene_new(camera, objects, lights);
	return (scene);
}
