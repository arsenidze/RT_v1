/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:59:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/04/19 12:34:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_DEFINES_H
# define ERRORS_DEFINES_H

# define DRAWER_INIT_MEM					"Not enough memory to init drawer"
# define DRAWER_INIT_SDL_INIT				(char *)SDL_GetError() 
# define DRAWER_INIT_SDL_CREATE_WINDOW 		(char *)SDL_GetError() 
# define DRAWER_INIT_SDL_CREATE_RENDERER	(char *)SDL_GetError() 
# define DRAWER_INIT_SDL_CREATE_TEXTURE 	(char *)SDL_GetError() 

# define SCENE_INIT_MEM						"Not enough memory to init scene"

# define CAMERA_INIT_MEM					"Not enough memory to init scene"

#endif
