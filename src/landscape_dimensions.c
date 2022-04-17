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
	int		width;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	width = (int)ft_split_count(line, ' ');
	free(line);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (width);
}

int	get_height(char *filename)
{
	int		fd;
	int		depth;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	depth = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		depth++;
		free(line);
	}
	close(fd);
	return (depth);
}
