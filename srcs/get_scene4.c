/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:13:55 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/01 17:07:42 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "cylinder.h"
#include "cone.h"
#include "plane.h"
#include <stdlib.h>

#define FOURTH_SCENE_NOBJECTS	0
#define FOURTH_SCENE_NLIGHTS	0

#define INVER_SQRT_TWO	0.70710678118

t_scene	*get_scene4(void)
{
	t_scene		*scene;
	t_camera	*camera;
	t_object3d	**objects;
	t_light		**lights;

	if (!(objects = malloc(sizeof(t_object3d *) * (FOURTH_SCENE_NOBJECTS + 1))))
		return (NULL);
	objects[FOURTH_SCENE_NOBJECTS] = NULL;
	if (!(lights = malloc(sizeof(t_light *) * (FOURTH_SCENE_NLIGHTS + 1))))
		return (NULL);
	lights[FOURTH_SCENE_NLIGHTS] = NULL;
	camera = camera_new(CAMERA_NEW_POS, CAMERA_NEW_DIR, CAMERA_NEW_UP);
//	objects[0] = object3d_new(COLOR(0x00003333),
//		PRIMITIVE(sphere, VECT3D(0, 0, 0), 50));
//	objects[1] = object3d_new(COLOR(0x00220022),
//		PRIMITIVE(sphere, VECT3D(0, -200, 100), 50));
//	objects[2] = object3d_new(COLOR(0x00333300),
//		PRIMITIVE(plane, VECT3D(0, 0, -100),VECT3D(0, 0, 1)));

//	lights[0] = light_new(VECT3D(0, 0, 100), 10);
//	lights[1] = light_new(VECT3D(-20, -500, 300), 10);
	scene = scene_new(camera, objects, lights);
	return (scene);
}
