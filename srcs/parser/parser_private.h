/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:31:07 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/13 16:56:40 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_PRIVATE_H
# define PRIVATE_PRIVATE_H

#include "parser.h"
#include "camera.h"
#include "object3d.h"
#include "light.h"
#include "vect3d.h"

#define PARSER_SUCCESS	1
#define PARSER_FAILURE	!PARSER_SUCCESS

/*
**	Length of identifiers
*/
#define ID_LEN(ID)	(sizeof(ID) - 1)

/*
**	Attribute identifiers
*/
#define AMBNT		"ambient"
#define DIFF		"diffuse"
#define SPEC		"specular"
#define RADIUS		"radius"
#define AXIS		"axis"
#define DIRECTION	"dir"
#define UP			"up"
#define PRIMIT		"primitive"
#define SLOPE		"slope"

#define LEFT_BRACKET	'['
#define RIGHT_BRACKET	']'

#define SEPARATOR		','

#define IS_WHITESPACE(c) ((c) == ' ' || (c) == '\t')
#define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')

#define MAX_NOBJECTS_NDIGITS	2
#define MAX_NLIGHTS_NDIGITS		2

t_camera	*parse_camera(char *line);
t_object3d	**parse_objects(char **lines, int nobjects_expected);
t_light		**parse_lights(char **lines, int nlights_expected);
t_object3d	*parse_object(char *line);
t_light		*parse_light(char *line);
t_object3d	*parse_sphere(char *line, t_vect3d components[3]);
t_object3d	*parse_cylinder(char *line, t_vect3d components[3]);
t_object3d	*parse_cone(char *line, t_vect3d components[3]);
t_object3d	*parse_plane(char *line, t_vect3d components[3]);

short		parse_attr_of_type_vect3d(char *line, int *line_index,
			char *attr_name, t_vect3d *res);
short		parse_attr_of_type_double(char *line, int *line_index,
			char *attr_name, t_vect3d *res);
//char		*get_err_at_line_msg(int line_num);
char		*get_value_of_attr_with_name(char *line, int *line_index,
			char *attr_name);
short		parse_vect3d(char *value, t_vect3d *res, int *nchars_occupied);
short		parse_integer(char *value, int *res, int *nchars_occupied);
short		parse_double(char *value, double *res, int *nchars_occupied);

short		skip_separator(char *line, int *line_index);
short		is_correct_eol(char *end_of_line);
short		is_valid_radius(double radius);
short		is_valid_slope(double slope);
short		is_only_whitespaces(char *line);
int			str_with_digits_to_int(char *str, int *ndigits);

#endif
