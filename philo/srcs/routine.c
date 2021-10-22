/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:48:03 by hlevi             #+#    #+#             */
/*   Updated: 2021/10/21 17:58:44 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_status(int current_ph, char *str, t_data *data)
{
	long	time;

	time = timed(data);
	if (time == -1)
		return (-1);
	if (pthread_mutex_lock(&data->dead_mutex))
		return (-1);
	if (!data->dead)
		printf("%ld\t%d %s\n", time, current_ph, str);
	if (pthread_mutex_unlock(&data->dead_mutex))
		return (-1);
	return (0);
}

int	sleep_think(int current_ph, t_data *data)
{
	if (print_status(current_ph, "is sleeping", data))
		return (-1);
	if (mysleep(data->sleep, data) == -1)
		return (-1);
	if (print_status(current_ph, "is thinking", data))
		return (-1);
	return (0);
}

int	routine(int thid, t_data *data)
{
	int	ret;

	ret = 0;
	if (take_forks(thid, data))
		return (-1);
	if (data->nphil != 1 && eating(thid, data))
		return (-1);
	if (drop_forks(thid, data))
		return (-1);
	if (data->nphil == 1)
		ret = kill_ph(thid, data);
	if (ret)
		return (-1);
	if (data->nphil != 1 && sleep_think(thid, data))
		return (-1);
	ret = check_death(data);
	if (ret)
		return (ret);
	return (0);
}
