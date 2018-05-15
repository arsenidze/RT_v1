/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:52:17 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/03 22:14:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <stdlib.h>

void	light_clear(t_light *light)
{
	free(light);
}

t_light	*light_new(t_vect3d pos, t_intensity intensity)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		return (NULL);
	light->pos = pos;
	light->intensity = intensity;
	return (light);
}
