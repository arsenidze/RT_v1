/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_initial_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:12:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 17:41:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "cylinder.h"
#include <stdlib.h>
t_scene	*get_scene1(void);
t_scene	*get_scene2(void);

static void		*scenes_initial_data_err_exit(t_scene **scenes)
{
	(void)scenes;
	return (NULL);
}

#define NSCENES 2

static t_scene	*get_scene(short i)
{
	static	t_scene *(*scenes_getters[NSCENES])(void) =
	{
		get_scene1,
		get_scene2
	};

	if (i < 0 || i >= NSCENES)
		return (NULL);
	return ((*scenes_getters[i])());
}

t_scene			**scenes_initial_data(void)
{
	int		i;
	t_scene	**scenes;

	if (!(scenes = malloc(sizeof(t_scene *) * (NSCENES + 1))))
		return (NULL);
	scenes[NSCENES] = NULL;
	i = 0;
	while (i < NSCENES)
	{
		scenes[i] = get_scene(i);
		if (!scenes[i])
			return (scenes_initial_data_err_exit(scenes));
		i++;
	}
	return (scenes);
}
