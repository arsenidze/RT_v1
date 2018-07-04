/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scenes_from_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:11:30 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 17:11:32 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_ptr_arr.h"
#include "errors.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
t_scene	*get_scene_from_file(const char *file_name);

static void				*get_scenes_from_file_failure(t_scene **scenes,
						char *err)
{
	scene_ptr_arr_delete(scenes);
	try_set_err(err);
	return (NULL);
}

t_scene					**get_scenes_from_file(const char *file_name)
{
	t_scene	**scenes;

	scenes = NULL;
	if (!(scenes = malloc(sizeof(t_scene *) * 2)))
		return (get_scenes_from_file_failure(scenes, strerror(errno)));
	scenes[1] = NULL;
	if (!(scenes[0] = get_scene_from_file(file_name)))
		return (get_scenes_from_file_failure(scenes, ""));
	return (scenes);
}
