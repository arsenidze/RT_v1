/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:15:22 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:16:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_LIGHT_H
# define APPLY_LIGHT_H

#include "scene.h"
#include "color.h"
#include "intersection.h"

t_color	apply_light(t_scene *, t_intersection *);

#endif
