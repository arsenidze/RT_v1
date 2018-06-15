/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:14:24 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 20:35:27 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		my_pow(int n, int degree)
{
	int	res;

	res = n;
	while (degree > 1)
	{
		res *= n;
		degree--;
	}
	return (res);
}

short	parse_double(char *value, double *res, int *nchars_occupied)
{
	int	i;
	int	int_part;
	int	fract_part;
	int	ndigits_int_part;
	int	ndigits_fract_part;

	i = 0;
	while (value[i] && IS_WHITESPACE(value[i]))
		i++;
	int_part = str_with_digits_to_int(&value[i], &ndigits_int_part);
	if (ndigits_int_part == 0 || ndigits_int_part > MAX_NDIGITS_INT
		|| int_part > MAX_INT)
		return (PARSER_FAILURE);
	i += ndigits_int_part;
	*nchars_occupied = i;
	*res = int_part;
	if (value[i] != '.')
		return (PARSER_SUCCESS);
	i += 1;
	fract_part = str_with_digits_to_int(&value[i], &ndigits_fract_part);
	*nchars_occupied = i + ndigits_fract_part;
	if (ndigits_fract_part == 0)
		return (PARSER_SUCCESS);
	if (ndigits_fract_part > MAX_NDIGITS_FRACT)
		return (PARSER_FAILURE);
	*res += fract_part / my_pow(10, ndigits_fract_part);
	return (PARSER_SUCCESS);
}