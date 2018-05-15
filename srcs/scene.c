/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:55:45 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 16:10:51 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "errors.h"
#include "libft.h"
#include <stdlib.h>

void	scene_clear(t_scene *scene)
{
	int		i;

	if (!scene)	
		return ;
	if (scene->camera) 
		camera_clear(scene->camera);
	if (scene->objects)
	{
		i = -1;
		while (scene->objects[++i])
			object3d_delete(scene->objects[i]);
		free(scene->objects);
	}
	if (scene->lights)
	{
		i = -1;
		while (scene->lights[++i])
			light_clear(scene->lights[i]);
		free(scene->lights);
	}
	free(scene);
}

static void		*scene_err_exit(t_scene *scene, char *err)
{
	scene_clear(scene);
	try_set_err(err);
	return (NULL);
}

t_scene			*scene_init(t_camera *camera, t_object3d **objects,
				t_light **lights)
{
	t_scene	*scene;

	if (!(scene = malloc(sizeof(t_scene))))
		return (scene_err_exit(scene, SCENE_INIT_MEM));
	scene->camera = camera;
	scene->objects = objects;
	scene->lights = lights;
	return (scene);
}
