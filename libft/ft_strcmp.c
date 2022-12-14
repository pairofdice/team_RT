/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:52:38 by jjuntune          #+#    #+#             */
/*   Updated: 2022/08/11 16:05:42 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	count;

	count = 0;
	while (s1[count] != '\0' && s2[count] != '\0' && s1[count] == s2[count])
		count++;
	return (((unsigned char *)s1)[count] - ((unsigned char *)s2)[count]);
}
