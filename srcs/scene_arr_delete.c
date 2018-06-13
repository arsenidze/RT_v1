/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_arr_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:06:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/01 17:06:16 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>
#include <stdio.h>
void	scene_arr_delete(t_scene **scenes)
{
	int		i;

	i = 0;
	while (scenes[i])
	{
		scene_delete(scenes[i]);
		i++;
	}
	free(scenes);
}
