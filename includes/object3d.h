/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:14:35 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 16:52:14 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT3D_H
# define OBJECT3D_H

# include "vect3d.h"
# include "color.h"
# include "primitive.h"

# define GET_NORMAL(obj, p) obj->get_normal(obj->primitive, p)

typedef struct	s_object3d
{
	void		*primitive;
	short		(*intersection)(void *primitive, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
	t_vect3d	(*get_normal)(void *primitive, t_vect3d point);
	void		(*delete_primitive)(void *primitive);
	t_color		color;
}				t_object3d;

/*
**	!!! Use PRIMITIVE macro on 'var_args' place !!!
*/
t_object3d		*object3d_new(t_color color, void *var_args[]);
void			object3d_delete(t_object3d *object3d);

#endif
