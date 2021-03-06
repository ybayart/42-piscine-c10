/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 03:55:35 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/20 21:42:52 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	no_args(char **argv)
{
	char	buf;

	while (read(0, &buf, 1) != 0)
	{
		if (errno != 0)
		{
			ft_putstr(basename(argv[0]), 2);
			ft_putstr(": stdin: ", 2);
			ft_putstr(strerror(errno), 2);
			ft_putchar('\n', 2);
			return ;
		}
	}
}

void	no_args_stdin(int size, char **args)
{
	int		i;
	char	c[1];
	char	*buf;

	buf = malloc(sizeof(char) * (size + 1));
	if (buf == NULL)
		return ;
	i = 0;
	while (read(0, c, 1) != 0)
		if (errno == 0)
		{
			if (i >= size)
				ft_swap_tail(buf, size);
			else
				i++;
			buf[i - 1] = c[0];
		}
		else
		{
			print_error(args, 1);
			return ;
		}
	i = -1;
	while (++i < size && buf[i])
		ft_putchar(buf[i], 1);
}
