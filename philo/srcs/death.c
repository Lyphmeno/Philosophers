/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:11:00 by hlevi             #+#    #+#             */
/*   Updated: 2021/10/21 18:12:38 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	kill_ph(int	current_ph, t_data *data)
{
	long	time;

	pthread_mutex_lock(&data->dead_mutex);
	if (!data->dead)
	{
		data->dead = 1;
		time = timed(data);
		if (time == -1)
			return (-1);
		printf("%ld\t%d died\n", time, current_ph);
	}	
	pthread_mutex_unlock(&data->dead_mutex);
	return (0);
}

int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->dead_mutex);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->dead_mutex);
	return (0);
}

int	death_timer(int	current_ph, t_data *data)
{
	long	last_meal;
	long	time;

	time = timed(data);
	if (time == -1)
		return (-1);
	pthread_mutex_lock(&data->ph[current_ph - 1].dinner_mutex);
	last_meal = time - data->ph[current_ph - 1].last_eat;
	pthread_mutex_unlock(&data->ph[current_ph - 1].dinner_mutex);
	if (last_meal >= data->die)
		if (kill_ph(current_ph, data))
			return (-1);
	return (check_death(data));
}

int	check_all(t_data *data)
{
	int		i;
	int		res;

	res = 0;
	while (1)
	{
		i = -1;
		while (++i < data->nphil && res == 0)
			res = death_timer(i + 1, data);
		if (res)
			return (res);
		usleep(300);
	}
	return (0);
}
