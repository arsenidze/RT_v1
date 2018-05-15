/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:49:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/04/28 15:57:16 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vect3d.h"

typedef double	t_intensity;

typedef struct	s_light
{
	t_vect3d	pos;
	t_intensity	intensity;
}				t_light;

t_light			*light_new(t_vect3d pos, t_intensity intensity);
void			light_clear(t_light *light);

#endif
