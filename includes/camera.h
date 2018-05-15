/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:44:22 by amelihov          #+#    #+#             */
/*   Updated: 2018/04/19 14:33:30 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vect3d.h"
/*
# define CAMERA_SUCCESS 0
# define CAMERA_FAILURE 1
*/

typedef struct	s_camera
{
	t_vect3d	pos;	
	t_vect3d	dir;
	t_vect3d	up;
	t_vect3d	left;
}				t_camera;

t_camera		*camera_init(t_vect3d pos, t_vect3d dir, t_vect3d up);
void			camera_clear(t_camera *camera);

#endif
