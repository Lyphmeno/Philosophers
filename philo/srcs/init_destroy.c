/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:48:21 by hlevi             #+#    #+#             */
/*   Updated: 2021/10/21 18:56:12 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) <= 0)
		return (-1);
	return (0);
}

void	get_ph(int i, char *str, t_data *data)
{
	if (i == 1)
		data->nphil = ft_atoi(str);
	else if (i == 2)
		data->die = ft_atoi(str);
	else if (i == 3)
		data->eat = ft_atoi(str);
	else if (i == 4)
		data->sleep = ft_atoi(str);
	else if (i == 5)
	{
		data->has_neat = 1;
		data->neat = ft_atoi(str);
	}
}

int	init_philo(char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_valid(argv[i]))
			get_ph(i, argv[i], data);
		else
			return (-1);
		i++;
	}
	return (0);
}

void	destroy_all(t_data *data)
{
	int		i;
	t_ph	*ph;

	i = 0;
	ph = data->ph;
	pthread_mutex_destroy(&data->error_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	while (i < data->nphil)
	{
		pthread_mutex_destroy(&ph[i].fork_mutex);
		pthread_mutex_destroy(&ph[i].meals_mutex);
		pthread_mutex_destroy(&ph[i].dinner_mutex);
		i++;
	}
}

void	freexit(t_data *data)
{
	destroy_all(data);
	free(data->ph);
}
