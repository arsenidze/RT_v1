/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userinput.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:12:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 19:35:43 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINPUT_H
# define USERINPUT_H

typedef unsigned char	t_byte;

typedef struct			s_userinput
{
	t_byte	quit;
	t_byte	scene_index;
	t_byte	object_index;
	int		step_in_pixels;
}						t_userinput;

#endif
