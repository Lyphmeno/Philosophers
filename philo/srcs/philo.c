/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:26:29 by hlevi             #+#    #+#             */
/*   Updated: 2021/10/21 18:56:18 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("Error\nWrong number of arg\n");
		return (-1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	if (init_philo(argv, &data))
	{
		printf("Error\nInit failed\n");
		return (-1);
	}
	if (launch(&data))
	{
		printf("Error\n");
		freexit(&data);
	}
	freexit(&data);
	return (0);
}
