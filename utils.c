/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:30:23 by rispay-s          #+#    #+#             */
/*   Updated: 2025/03/11 12:30:23 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;
	int		c;

	i = 0;
	c = 0;
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (i < (count * size))
		{
			((unsigned char *)ptr)[i] = (unsigned char) c;
			i++;
		}
	}
	return (ptr);
}
