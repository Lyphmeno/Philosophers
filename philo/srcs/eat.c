/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:59:10 by hlevi             #+#    #+#             */
/*   Updated: 2021/10/21 18:14:38 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	neat_count(int *count, t_ph ph, t_data *data)
{
	if (pthread_mutex_lock(&ph.meals_mutex))
		return (-1);
	if (ph.meal >= data->neat)
		(*count)++;
	if (pthread_mutex_unlock(&ph.meals_mutex))
		return (-1);
	return (0);
}

int	neat_done(t_ph *ph)
{
	t_data	*data;
	int		i;
	int		count;

	i = 0;
	count = 0;
	data = ph->data;
	while (i < data->nphil)
	{
		if (neat_count(&count, ph[i], data))
			return (-1);
		i++;
	}
	if (count == data->nphil)
	{
		if (pthread_mutex_lock(&data->dead_mutex))
			return (-1);
		data->dead = 1;
		if (pthread_mutex_unlock(&data->dead_mutex))
			return (-1);
	}
	return (0);
}

int	drop_forks(int current_ph, t_data *data)
{
	int		left;
	int		index;
	t_ph	*ph;

	ph = data->ph;
	left = left_philo(&index, current_ph, data);
	ph[index].fork = 1;
	if (pthread_mutex_unlock(&ph[index].fork_mutex))
		return (-1);
	if (left != -1)
	{	
		ph[left].fork = 1;
		if (pthread_mutex_unlock(&ph[left].fork_mutex))
			return (-1);
	}
	return (0);
}

int	eating(int current_ph, t_data *data)
{
	long	time;

	time = timed(data);
	if (time == -1)
		return (-1);
	if (pthread_mutex_lock(&data->ph[current_ph - 1].dinner_mutex))
		return (-1);
	data->ph[current_ph - 1].last_eat = time;
	if (pthread_mutex_unlock(&data->ph[current_ph - 1].dinner_mutex))
		return (-1);
	if (print_status(current_ph, "is eating", data))
		return (-1);
	if (mysleep(data->eat, data) == -1)
		return (-1);
	if (data->has_neat)
	{
		if (pthread_mutex_lock(&data->ph[current_ph - 1].meals_mutex))
			return (-1);
		data->ph[current_ph - 1].meal++;
		if (pthread_mutex_unlock(&data->ph[current_ph - 1].meals_mutex))
			return (-1);
		if (neat_done(data->ph))
			return (-1);
	}
	return (0);
}

int	take_forks(int current_ph, t_data *data)
{
	int		left;
	int		index;
	t_ph	*ph;

	ph = data->ph;
	left = left_philo(&index, current_ph, data);
	if (pthread_mutex_lock(&ph[index].fork_mutex))
		return (-1);
	ph[index].fork = 0;
	if (print_status(current_ph, "has taken a fork", data))
		return (-1);
	if (left != -1)
	{
		if (pthread_mutex_lock(&ph[left].fork_mutex))
			return (-1);
		ph[left].fork = 0;
		if (print_status(current_ph, "has taken a fork", data))
			return (-1);
	}
	else
		if (mysleep(data->die, data) == -1)
			return (-1);
	return (0);
}
