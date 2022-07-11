#include "philo.h"

t_philo     *ft_init()
{
    t_philo *philo;
    
    philo = malloc(sizeof(t_philo));
    philo->nop = 0;
    philo->ttd = 0;
    philo->tte = 0;
    philo->tts = 0;
    philo->nte = 0;
    return(philo);
}
int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void    ft_check(char   **argv)
{
    int     i = 1;
    int     j = 0;
    while(argv[i])
    {
        while(argv[i][j])
        {
            if(!ft_isalnum(argv[i][j]))
            {
                printf("error: not only digit");
                exit(EXIT_FAILURE);
            }
            j++;
        }
        j = 0;
        i++;
    }
}
int main(int argc,char **argv)
{
    t_philo *philo = NULL;

    philo = ft_init();
    if(argc == 5 || argc == 6)
    {
        if(argc == 5)
        {
            ft_check(argv);
            philo->nop = ft_atoi(argv[1]);
            philo->ttd = ft_atoi(argv[2]);
            philo->tte = ft_atoi(argv[3]);
            philo->tts = ft_atoi(argv[4]);
            if(philo->nop < 1 || philo->nop > 200 || philo->ttd < 60 || philo->tte < 60 || philo->tts < 60 || \
            (philo->nop > 2147483647 || philo->ttd > 2147483647 || philo->tte > 2147483647 || philo->tts > 2147483647))
            {
                printf("error: valeur incorrettes");
                exit(EXIT_FAILURE);
            }
        }
        else if(argc == 6)
        {
            philo->nte = ft_atoi(argv[5]);
            if(philo->nte > 2147483647)
            {
                printf("error: valeur incorrettes");
                exit(EXIT_FAILURE);
            }
        }
        printf("nop:%d  ttd:%d  tte:%d  tts:%d  nte:%d\n",philo->nop,philo->ttd,philo->tte, philo->tts, philo->nte);
    }
    else
    {
        printf("error: number of argument");
    }
}