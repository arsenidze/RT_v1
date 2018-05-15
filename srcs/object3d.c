/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:49:06 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 17:15:46 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object3d.h"
#include <stdlib.h>

t_object3d	*object3d_new(t_color color, void *var_arg[])
{
	t_object3d	*new_obj;

	if (!(new_obj = malloc(sizeof(t_object3d))))
		return (NULL);
	new_obj->color = color;
	if (!(new_obj->primitive = var_arg[0]))
		return (NULL);
	new_obj->intersection = var_arg[1];
	new_obj->get_normal = var_arg[2];
	new_obj->delete_primitive = var_arg[3];
	return (new_obj);
}

void		object3d_delete(t_object3d *object3d)
{
	if (!object3d)
		return ;
	object3d->delete_primitive(object3d->primitive);
	free(object3d);
}
