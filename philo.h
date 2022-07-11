#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_philo
{
    int     nop;
    int     ttd;
    int     tte;
    int     tts;
    int     nte;
}       t_philo;


int		ft_atoi(const char *str);
int	ft_isalnum(int c);
t_philo     *ft_init();

#endif