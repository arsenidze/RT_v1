/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:13:55 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/15 17:31:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "cylinder.h"
#include "cone.h"
#include "plane.h"
#include <stdlib.h>

#define FIRST_SCENE_NOBJECTS	1
#define FIRST_SCENE_NLIGHTS		1

#define CAMERA_INIT_POS	VECT3D(500, 0, 0)
#define CAMERA_INIT_DIR	VECT3D(-1, 0, 0)
#define CAMERA_INIT_UP	VECT3D(0, 0, 1)

#define INVER_SQRT_TWO	0.70710678118

t_scene	*get_scene1(void)
{
	t_scene		*scene;
	t_camera	*camera;
	t_object3d	**objects;
	t_light		**lights;

	if (!(objects = malloc(sizeof(t_object3d *) * (FIRST_SCENE_NOBJECTS + 1))))
		return (NULL);
	objects[FIRST_SCENE_NOBJECTS] = NULL;
	if (!(lights = malloc(sizeof(t_light *) * (FIRST_SCENE_NLIGHTS + 1))))
		return (NULL);
	lights[FIRST_SCENE_NLIGHTS] = NULL;

	camera = camera_init(CAMERA_INIT_POS, CAMERA_INIT_DIR, CAMERA_INIT_UP);

//	objects[0] = object3d_new(COLOR(0x00330000),
//							PRIMITIVE(sphere, VECT3D(0, 0, 0), 100));
	objects[0] = object3d_new(COLOR(0x00003300),
		PRIMITIVE(cone, VECT3D(0, 0, 0), 
		VECT3D(0, 0, 1), 1));
//	objects[0] = object3d_new(COLOR(0x00330000),
//		PRIMITIVE(plane, VECT3D(0, 0, -10), VECT3D(0, 0, 1)));
	lights[0] = light_new(VECT3D(0, 100, 0), 10);
//	lights[1] = light_new(VECT3D(0, -500, 300), 10);
//	lights[0] = NULL;
	scene = scene_init(camera, objects, lights);
	return (scene);
}
