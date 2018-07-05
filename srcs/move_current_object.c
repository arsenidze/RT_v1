/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_current_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 13:56:26 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 14:14:37 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "userinput.h"
#include "vect3d.h"
#include "sphere.h"

void	move_current_object(t_scene **scenes, t_userinput *userinput,
		t_vect3d step)
{
	((t_sphere*)(scenes[userinput->scene_index]
		->objects[userinput->object_index]
		->primitive))->pos += step;
}
