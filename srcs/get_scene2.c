/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:14:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 17:01:38 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "cylinder.h"
#include <stdlib.h>

#define SECOND_SCENE_NOBJECTS	1
#define SECOND_SCENE_NLIGHTS		1

#define CAMERA_INIT_POS	VECT3D(500, 0, 0)
#define CAMERA_INIT_DIR	VECT3D(-1, 0, 0)
#define CAMERA_INIT_UP	VECT3D(0, 0, 1)

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

	camera = camera_init(CAMERA_INIT_POS, CAMERA_INIT_DIR, CAMERA_INIT_UP);

	objects[0] = object3d_new(COLOR(0x00003300),
				PRIMITIVE(sphere, VECT3D(0, 0, 0), 100));
	//objects[0] = new_cylinder(VECT3D(0, 0, 0), VECT3D(0, 0, 1),
	//			COLOR(0x0000FF00), 30);
	lights[0] = light_new(VECT3D(200, 0, 0), 10);
//	lights[0] = NULL;
	scene = scene_init(camera, objects, lights);
	return (scene);
}
