/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:29:48 by epacheco          #+#    #+#             */
/*   Updated: 2022/04/17 05:03:12 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	raise_error(int exit_code)
{
	if (exit_code == INPUT_ERROR)
		ft_putstr_fd("Argument count error. \
                    Did you pass the landscape file as a parameter?", 1);
	else if (exit_code == EXTENSION_MISMATCH)
		ft_putstr_fd("The landscape file must end with .fdf!", 1);
	else if (exit_code == FILE_DESCRIPTOR_ERROR)
		ft_putstr_fd("There was a problem with the file descriptor.", 1);
	else if (exit_code == NULL_VECTOR)
		ft_putstr_fd("Vector returned null.", 1);
	else if (exit_code == OUT_OF_BOUNDS)
		ft_putstr_fd("The point was out of the bounds!", 1);
	else if (exit_code == FDF_BUILD_ERROR)
		ft_putstr_fd("Build of FdF failed.\n", 1);
	else if (exit_code == IMAGE_BUILD_ERROR)
		ft_putstr_fd("Build of image failed\n", 1);
	else if (exit_code == POV_BUILD_ERROR)
		ft_putstr_fd("Build of pov failed.\n", 1);
	else if (exit_code == LANDSCAPE_BUILD_ERROR)
		ft_putstr_fd("Build of landscape failed.\n", 1);
	else
		error_extension(exit_code);
	exit(exit_code);
}

void	error_extension(int error_code)
{
	if (error_code == ALLOCATE_ERROR)
		ft_putstr_fd("Memory allocation failed!", 1);
	exit(error_code);
}

void	raise_exit_message(void)
{
	ft_putstr_fd("FdF closed successfully!", 1);
	exit(0);
}
