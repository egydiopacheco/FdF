/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landscape_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_width(char *filename)
{
	int		fd;
	char	*line;
	int		width;
	int		new_width;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	width = (int)ft_split_count(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new_width = (int)ft_split_count(line, ' ');
		if (width != new_width)
			return (0);
		free(line);
	}
	close(fd);
	return (width);
}

int	get_depth(char *filename)
{
	int		fd;
	int		depth;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	depth = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_isprint(*line))
			depth++;
		free(line);
	}
	close(fd);
	return (depth);
}
