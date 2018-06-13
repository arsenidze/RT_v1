/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:13:05 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/01 16:21:14 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RED	2
# define GREEN	1
# define BLUE	0
# define ALPHA	3

# define COLOR(c) (t_color)(unsigned int)c
# define COLOR_RGBA(r, g, b, a) (t_color)*(unsigned int *)(unsigned char[4]){b, g, r, a}

/*
**							UPDATE COMMENT
**								!!!
**	COLOR_MULL depends on red, green, blue, alpha chanells order
*/
//# define COLOR_MULL(c, m) ((t_color){(unsigned char *){c[0], c[1], c[2], c[3]}})
//# define COLOR_MULL(c, m) COLOR_RGBA(c[RED]*m, c[GREEN]*m, c[BLUE]*m, c[ALPHA])

typedef union	u_color
{
	unsigned char	rgba[4];
	unsigned int	value;
}				t_color;

#endif
