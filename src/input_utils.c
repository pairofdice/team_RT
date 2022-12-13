/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:26:33 by mmakinen          #+#    #+#             */
/*   Updated: 2022/12/13 13:36:14 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/input.h"

t_matrix	matrix_translate_2(t_tuple tuple)
{
	return (matrix_translate(tuple.a[0], tuple.a[1], tuple.a[2]));
}

double	get_double(char *str)
{
	double	negative;
	double	num;
	int		len;

	negative = 1.0f;
	num = 0.0;
	len = 0;
	if (*str == '-')
	{
		negative = -1.0f;
		str++;
	}
	num = (double)ft_atoi(str);
	while (*str != '\0' && *str++ != '.')
		;
	while (str[len] != '\0' && ft_isdigit(str[len]))
		len++;
	if (len)
	{
		num += (double)(ft_atoi(str) / powf(10, len));
	}
	return (num * negative);
}

void	get_tuple(t_tuple *tuple, char *str)
{
	int	index;
	int	index_t;

	index = 0;
	index_t = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ' ' && str[index + 1] != '\0')
		{
			tuple->a[index_t++] = get_double(&str[index + 1]);
		}
		index++;
	}
}

/*prepare functions can't return FALSE as of yet, need a way identify errors*/
int	read_xml(t_xml_doc *doc, t_main *main)
{
	int			index;

	index = 0;
	while (index < doc->head->children.size)
	{
		if (!ft_strcmp(doc->head->children.list[index]->tag, "object"))
		{
			if (!prepare_object(doc->head->children.list[index], \
			&main->obj[main->obj_count++]))
				return (FALSE);
		}
		else if (!ft_strcmp(doc->head->children.list[index]->tag, "camera"))
		{
			if (!prepare_camera(doc->head->children.list[index], &main->cam))
				return (FALSE);
		}
		else if (!ft_strcmp(doc->head->children.list[index]->tag, "light"))
		{
			if (!prepare_light(doc->head->children.list[index], &main->light))
				return (FALSE);
		}
		index++;
	}
	return (TRUE);
}
