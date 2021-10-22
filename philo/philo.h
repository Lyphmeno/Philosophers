/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:25:14 by hlevi             #+#    #+#             */
/*   Updated: 2021/10/21 18:05:55 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nphil;
	int				die;
	int				eat;
	int				sleep;
	int				has_neat;
	int				neat;
	int				dead;
	int				error;
	struct timeval	time;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	error_mutex;
	struct s_ph		*ph;
}				t_data;

typedef struct s_ph
{
	int				id;
	int				fork;
	int				meal;
	long			last_eat;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	dinner_mutex;
	pthread_mutex_t	meals_mutex;
	struct s_data	*data;		
}				t_ph;

// UTILS
int			ft_isdigit(int c);
long		ft_atoi(const char *str);
void		*ft_memset(void *b, int c, size_t len);
int			left_philo(int *index, int current_ph, t_data *data);
// TIMING
long		real_time(void);
long		timed(t_data *data);
int			mysleep(int t, t_data *data);
// DEATH
int			kill_ph(int	current_ph, t_data *data);
int			check_death(t_data *data);
int			death_timer(int	current_ph, t_data *data);
int			check_all(t_data *data);
// INIT DESTROY
int			is_valid(char *str);
void		get_ph(int i, char *str, t_data *data);
int			init_philo(char **argv, t_data *data);
void		destroy_all(t_data *data);
void		freexit(t_data *data);
// LAUNCH
int			init_forks(t_ph *ph, int nb, t_data *data);
t_ph		*set_forks(t_data *data);
int			launch(t_data *data);
// THREADING
int			launch_threads(t_data *data);
pthread_t	*create_thread(t_data *data);
void		*routine_launch(void *elem);
void		*control(void *elem);
// ROUTINE
int			print_status(int current_ph, char *str, t_data *data);
int			sleep_think(int current_ph, t_data *data);
int			routine(int thid, t_data *data);
// EAT
int			neat_count(int *count, t_ph ph, t_data *data);
int			neat_done(t_ph *ph);
int			drop_forks(int current_ph, t_data *data);
int			eating(int current_ph, t_data *data);
int			take_forks(int current_ph, t_data *data);

#endif