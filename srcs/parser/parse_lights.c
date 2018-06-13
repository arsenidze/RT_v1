/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:58:44 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/13 15:58:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "light_ptr_arr.h"
#include "errors.h"
#include "libft.h"

static t_light	**parse_lights_failure(t_light **lights, char *err)
{
	try_set_err(err);
	light_ptr_arr_delete(lights);
	return (NULL);
}

t_light			**parse_lights(char **lines, int nlights_expected)
{
	t_light		**lights;
	int			nlines;

	lights = NULL;
	nlines = ft_get_str_arr_size(lines);
	if (nlights_expected != nlines)
		return (parse_lights_failure(lights, PARSER_LIGHTS_NLINES));
	if (!(lights = malloc(sizeof(t_light *) * (nlights_expected + 1))))
		return (parse_lights_failure(lights, PARSER_MEM_FAIL));
	lights[nlights_expected] = NULL;
	i = 0;
	while (i < nlights_expected)
	{
		if (!(lights[i] = parse_light(lines[i])))
			return (parse_lights_failure(lights, PARSE_FAIL));
		i++;
	}
	return (lights);
}
