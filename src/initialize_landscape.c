/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_landscape.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_landscape	*initialize_landscape(void)
{
	t_landscape	*landscape;

	landscape = malloc(sizeof(t_landscape));
	if (!landscape)
		return (NULL);
	fill_landscape_params(&landscape);
	return (landscape);
}

void	fill_landscape_params(t_landscape **landscape)
{
	(*landscape)->cartesian_plane = NULL;
	(*landscape)->horizontal_boundaries = 0;
	(*landscape)->vertical_boundaries = 0;
	(*landscape)->maximum_depth = 0;
	(*landscape)->minimum_depth = 0;
}
