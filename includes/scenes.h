/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:40:00 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/12 21:14:05 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_H
# define SCENES_H

#include "scene.h"

t_scene		**init_scenes_by_one_scene(t_scene *scene);
t_scene		**get_default_scenes(void);	
void		scenes_delete(t_scene **scenes);

#endif
