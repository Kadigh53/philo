/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 05:01:30 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/06 15:13:15 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_vars
{
	unsigned int	nbr_of_philos;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	unsigned int	nbrof_meals;
}	t_vars;

typedef struct	s_philo
{
	int			id;
	int			meals_count;
	u_int64_t	start_time;
	u_int64_t	last_meal_time;
	sem_t		*forks_sem;
	t_vars		*vars;
}	t_philo;

typedef struct s_data
{
	t_philo		*philos;
}	t_data;


void		init_args(int ac, char **av, t_vars *vars);
void		*ft_calloc(size_t count, size_t size);
void		ft_msleep(u_int64_t time);
u_int64_t	ft_gettime_inms(void);
int	ft_atoi(char *str);

#endif