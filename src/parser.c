/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_landscape	*parse_landscape(char *filename)
{
	t_landscape	*landscape;
	int			fd;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		raise_error(FILE_DESCRIPTOR_ERROR);
	close(fd);
	landscape = initialize_landscape();
	if (!landscape)
		return (NULL);
	landscape->horizontal_boundaries = get_width(filename);
	landscape->vertical_boundaries = get_height(filename);
	landscape->cartesian_plane = build_cartesian_plane(landscape-> \
			horizontal_boundaries, landscape->vertical_boundaries);
	if (!landscape->cartesian_plane)
	{
		free(landscape);
		return (NULL);
	}
	parse_points(filename, landscape);
	centralize(landscape);
	return (landscape);
}
