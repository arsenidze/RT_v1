/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:14:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 21:36:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "cylinder.h"
#include <stdlib.h>

#define SECOND_SCENE_NOBJECTS	1
#define SECOND_SCENE_NLIGHTS	0

#define CAMERA_NEW_POS	VECT3D(500, 0, 0)
#define CAMERA_NEW_DIR	VECT3D(-1, 0, 0)
#define CAMERA_NEW_UP	VECT3D(0, 0, 1)

t_scene	*get_scene2(void)
{
	t_scene		*scene;
	t_camera	*camera;
	t_object3d	**objects;
	t_light		**lights;

	if (!(objects = malloc(sizeof(t_object3d *) * (SECOND_SCENE_NOBJECTS + 1))))
		return (NULL);
	objects[SECOND_SCENE_NOBJECTS] = NULL;
	if (!(lights = malloc(sizeof(t_light *) * (SECOND_SCENE_NLIGHTS + 1))))
		return (NULL);
	lights[SECOND_SCENE_NLIGHTS] = NULL;

	camera = camera_new(CAMERA_NEW_POS, CAMERA_NEW_DIR, CAMERA_NEW_UP);

	objects[0] = object3d_new(
		(t_vect3d[3]){VECT3D(1, 0, 0), VECT3D(0, 0, 0), VECT3D(0, 0, 0)},
		PRIMITIVE(cylinder, VECT3D(0, 0, 0), VECT3D(0, 0, 1), 50));
//	lights[0] = light_new(VECT3D(100, -100, 0), 10);
	scene = scene_new(camera, objects, lights);
	return (scene);
}
