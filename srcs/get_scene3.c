/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:13:55 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/01 17:07:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "cylinder.h"
#include "cone.h"
#include "plane.h"
#include <stdlib.h>

#define THIRD_SCENE_NOBJECTS	0
#define THIRD_SCENE_NLIGHTS		0

#define INVER_SQRT_TWO	0.70710678118

t_scene	*get_scene3(void)
{
	t_scene		*scene;
	t_camera	*camera;
	t_object	**objects;
	t_light		**lights;

	if (!(objects = malloc(sizeof(t_object *) * (THIRD_SCENE_NOBJECTS + 1))))
		return (NULL);
	objects[THIRD_SCENE_NOBJECTS] = NULL;
	if (!(lights = malloc(sizeof(t_light *) * (THIRD_SCENE_NLIGHTS + 1))))
		return (NULL);
	lights[THIRD_SCENE_NLIGHTS] = NULL;
	camera = camera_new(CAMERA_NEW_POS, CAMERA_NEW_DIR, CAMERA_NEW_UP);
	//objects[0] = object_new(COLOR(0x00330000),
	//	PRIMITIVE(cone, VECT3D(0, 0, 0), VECT3D(0, 0, 1), 1));
	//lights[0] = light_new(VECT3D(100, -50, 20), 10);
	scene = scene_new(camera, objects, lights);
	return (scene);
}
