/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/07 15:04:00 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	double_swap(double *left, double *right)
{
	double	temp;

	temp = *left;
	*left = *right;
	*right = temp;
}