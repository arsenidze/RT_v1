/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_ptr_arr.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 21:26:37 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 17:08:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PTR_ARR_H
# define SCENE_PTR_ARR_H

typedef struct s_scene	t_scene;

void					scene_ptr_arr_delete(t_scene **scenes);
t_scene					**get_default_scenes(void);
t_scene					**get_scenes_from_file(const char *file_name);

#endif
