/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 22:28:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 23:02:07 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "scene.h"

/*
**	Identifiers in file
*/
#define SCENE_ID	"scene"
#define CAMERA_ID	"camera"
#define OBJECT_ID	"object"
#define LIGHT_ID	"light"

#define MAX_NOBJECTS	10
#define MAX_NLIGHTS		10

t_scene		*parser_parse_scene(char **lines);

#endif
