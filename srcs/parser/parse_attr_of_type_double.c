/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attr_of_type_double.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:03:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 20:33:39 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "libft.h"

short	parse_attr_of_type_double(char *line, int *line_index,
		char *attr_name, double *res)
{
	char	*value;
	int		nchars;

	if (!(value = get_value_of_attr_with_name(line, line_index, attr_name)))
		return (PARSER_FAILURE);
	if (!parse_double(value, res, &nchars) || nchars > MAX_NDIGITS_DOUBLE
		|| *res > MAX_DOUBLE)
		return (PARSER_FAILURE);
	*line_index += nchars;
	if (!is_only_whitespaces(&line[*line_index], RIGHT_BRACKET))
		return (PARSER_FAILURE);
	return (PARSER_SUCCESS);	
}
