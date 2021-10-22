/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:34:33 by hlevi             #+#    #+#             */
/*   Updated: 2021/10/21 18:57:19 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_forks(t_ph *ph, int nb, t_data *data)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ph[i].id = i + 1;
		ph[i].fork = i;
		pthread_mutex_init(&ph[i].fork_mutex, NULL);
		pthread_mutex_init(&ph[i].dinner_mutex, NULL);
		pthread_mutex_init(&ph[i].meals_mutex, NULL);
		ph[i].data = data;
		ph[i].last_eat = 0;
		ph[i].meal = 0;
		i++;
	}
	return (0);
}

t_ph	*set_forks(t_data *data)
{
	t_ph	*ph;

	ph = (t_ph *)malloc(sizeof(t_ph) * data->nphil);
	if (!ph)
		return (NULL);
	ft_memset(ph, 0, sizeof(ph) * data->nphil);
	if (init_forks(ph, data->nphil, data))
	{
		free(ph);
		ph = NULL;
	}
	return (ph);
}

int	launch(t_data *data)
{
	int	res;

	res = 0;
	data->ph = set_forks(data);
	if (!data->ph)
		return (-1);
	if (gettimeofday(&(data->time), NULL))
		return (-1);
	res = launch_threads(data);
	return (res);
}
