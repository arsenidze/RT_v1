/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userinput.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:12:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 14:25:52 by amelihov         ###   ########.fr       */
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
	int		nscenes;
}						t_userinput;

#endif
