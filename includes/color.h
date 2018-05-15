/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:13:05 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/09 22:29:25 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RED	1
# define GREEN	2
# define BLUE	3
# define ALPHA	0

# define COLOR(c) (t_color)(unsigned int)c
# define COLOR_RGBA(r, g, b, a) (t_color)*(unsigned int *)(unsigned char[4]){a, r, g, b}

/*
**							UPDATE COMMENT
**								!!!
**	COLOR_MULL depends on red, green, blue, alpha chanells order
*/
//# define COLOR_MULL(c, m) ((t_color){(unsigned char *){c[0], c[1], c[2], c[3]}})
# define COLOR_MULL(c, m) COLOR_RGBA(c[RED]*m, c[GREEN]*m, c[BLUE]*m, c[ALPHA])

typedef union	u_color
{
	unsigned char	rgba[4];
	unsigned int	value;
}				t_color;

#endif
