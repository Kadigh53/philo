/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:39:13 by kadigh            #+#    #+#             */
/*   Updated: 2023/05/10 23:36:40 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *test(void *arg){
    printf("first\n");
    int i=0;
    while (i<10000){
        printf("first\n");
        i++;
    }
}
void    *test2(void *arg){
    // pthread_t thr= (pthread_t )(arg);
    // if (pthread_join((pthread_t)arg,NULL))
    // {
    //     printf("klo\n");
    //     exit(1);
    // }
    printf("Second thread \n");
    int i=0;
    while (i<10000){
        printf("Second thread\n");
        i++;
    }
}
void    *test3(void *arg){
    printf("THird thread \n");
    int i=0;
    while (i<1000){
        printf("THird thread\n");
        i++;
    }
}


int main(){
    // pthread_t thread,thread2,thread3;

    // pthread_create(&thread,NULL,test,NULL);
    // pthread_create(&thread2,NULL,test2,&thread);
    // pthread_join(thread,NULL);
    // // pthread_detach(thread2);
    
    
    // pthread_join(thread2,NULL);
    // printf("\n\n\n\n\n\n");
    // pthread_create(&thread3,NULL,test3,NULL);
    // pthread_join(thread3,NULL);


    // struct timeval tv;
    // if (gettimeofday(&tv, NULL) == -1) {
    //     perror("gettimeofday");
    //     return 1;
    // }
    // printf("Current time: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    // // usleep(1000000);
    // gettimeofday(&tv, NULL);
    // printf("Current time: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    // return 0;

}
// 2023-(tv.tv_sec/(3600*24*365)),