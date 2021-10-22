/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:17:11 by hlevi             #+#    #+#             */
/*   Updated: 2021/10/21 18:16:47 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*control(void *elem)
{
	int		ret;
	t_data	*data;

	data = (t_data *)elem;
	ret = check_all(data);
	if (ret == -1)
	{
		pthread_mutex_lock(&data->error_mutex);
		data->error = -1;
		pthread_mutex_unlock(&data->error_mutex);
	}
	return ((void *) &data->error);
}

void	*routine_launch(void *elem)
{
	int		ret;
	int		ret_1;
	t_ph	*ph;

	ph = (t_ph *)elem;
	ret_1 = 0;
	if (ph->id % 2 == 0)
		ret_1 = mysleep(10, ph->data);
	ret = routine(ph->id, ph->data);
	while (!ret)
		ret = routine(ph->id, ph->data);
	if (ret == -1 || ret_1 == -1)
	{
		pthread_mutex_lock(&ph->data->error_mutex);
		ph->data->error = -1;
		pthread_mutex_unlock(&ph->data->error_mutex);
	}
	return ((void *) &ph->data->error);
}

pthread_t	*create_thread(t_data *data)
{
	pthread_t	*thread;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->nphil);
	if (pthread_mutex_init(&data->dead_mutex, NULL))
	{
		free(thread);
		thread = NULL;
	}
	if (pthread_mutex_init(&data->error_mutex, NULL))
	{
		free(thread);
		thread = NULL;
	}
	return (thread);
}

int	launch_threads(t_data *data)
{
	int			i;
	int			*ret;
	static int	status = 0;
	pthread_t	*thread;
	pthread_t	thdcontrol;

	i = -1;
	thread = create_thread(data);
	if (!thread)
		return (-1);
	while (!status && ++i < data->nphil)
		if (pthread_create(thread + i, NULL, &routine_launch, data->ph + i))
			status = -1;
	if (pthread_create(&thdcontrol, NULL, &control, data))
		status = -1;
	while (--i >= 0)
		if (pthread_join(thread[i], (void **) &ret) || *ret == -1)
			status = -1;
	if (pthread_join(thdcontrol, NULL))
		status = -1;
	if (thread)
		free(thread);
	return (status);
}
