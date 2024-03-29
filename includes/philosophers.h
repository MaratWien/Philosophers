/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:10:05 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/16 18:09:52 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				count_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				each_philo_must_eat;
	int				dead;
	int				timing_eating;			
	struct timeval	time_start;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	msg;
	pthread_mutex_t	ate;
}	t_philo;

typedef struct s_all
{
	int				philo_index;
	int				left_fork;
	int				right_fork;
	int				eating_count;
	pthread_t		philo_thread;
	pthread_t		waiter;
	t_philo			*connect;
	struct timeval	eating_lats_time;

}	t_all;

int		error_msg(char *msg, int ret);

int		init_args(t_philo *data, int argc, char **argv);

void	pthread_actions(t_all *all, t_philo *data);

size_t	ft_strlen(char *str);
long	calc_time(t_philo *data);
void	print_msg(char *msg, t_philo *data, t_all *all);
int		ft_atoi(const char *str);
void	my_usleep(int wait, t_philo *data);

#endif