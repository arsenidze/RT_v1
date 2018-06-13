/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:59:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/12 22:51:47 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_DEFINES_H
# define ERRORS_DEFINES_H

# define DRAWER_NEW_MEM					"Not enough memory to init drawer"
# define DRAWER_NEW_SDL_INIT			(char *)SDL_GetError() 
# define DRAWER_NEW_SDL_CREATE_WINDOW 	(char *)SDL_GetError() 
# define DRAWER_NEW_SDL_CREATE_RENDERER	(char *)SDL_GetError() 
# define DRAWER_NEW_SDL_CREATE_TEXTURE 	(char *)SDL_GetError() 

# define SCENE_NEW_MEM					"Not enough memory to init scene"

# define CAMERA_NEW_MEM					"Not enough memory to init scene"

# define SCENES_INITIAL_FAIL			"Failed to init scenes"


#endif
