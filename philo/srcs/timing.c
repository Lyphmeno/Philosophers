/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:55:44 by hlevi             #+#    #+#             */
/*   Updated: 2021/10/22 10:54:43 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	real_time(void)
{
	struct timeval	time;
	long			res;

	if (gettimeofday(&time, NULL))
		return (-1);
	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (res);
}

long	timed(t_data *data)
{
	struct timeval	time;
	long			res;

	if (gettimeofday(&time, NULL))
		return (-1);
	res = ((time.tv_sec - data->time.tv_sec) * 1000
			+ (time.tv_usec - data->time.tv_usec) / 1000);
	return (res);
}

int	mysleep(int t, t_data *data)
{
	long	stime;
	long	time;
	int		res;

	time = 0;
	stime = timed(data);
	while (time < t)
	{
		usleep(300);
		res = check_death(data);
		if (res)
			return (res);
		time = timed(data) - stime;
	}
	return (0);
}
