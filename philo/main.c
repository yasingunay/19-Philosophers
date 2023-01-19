/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:53:57 by ygunay            #+#    #+#             */
/*   Updated: 2023/01/19 16:25:28 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void* dine(void* arg) {
    t_philo* philosopher = (t_philo*) arg;
    printf("Philosopher %d is thinking\n", philosopher->id);
    while (1) {
        printf("Philosopher %d is hungry\n", philosopher->id);
        pthread_mutex_lock(&philosopher->left_fork);
        pthread_mutex_lock(&philosopher->right_fork);
        printf("Philosopher %d is eating\n", philosopher->id);
        sleep(1);
        pthread_mutex_unlock(&philosopher->left_fork);
        pthread_mutex_unlock(&philosopher->right_fork);
        sleep(1);
    }
    return NULL;
}

int main() {
    t_philo philosophers[NUM_PHILOSOPHERS];
    int i = 0;
    while (i < NUM_PHILOSOPHERS) {
        philosophers[i].id = i;
        pthread_mutex_init(&philosophers[i].left_fork, NULL);
        pthread_mutex_init(&philosophers[i].right_fork, NULL);
        i++;
    }
    i = 0;
    while (i < NUM_PHILOSOPHERS) {
        pthread_create(&philosophers[i].thread, NULL, dine, &philosophers[i]);
        i++;
    }
    i = 0;
    while (i < NUM_PHILOSOPHERS) {
        pthread_join(philosophers[i].thread, NULL);
        i++;
    }
    i = 0;
    while (i < NUM_PHILOSOPHERS) {
        pthread_mutex_destroy(&philosophers[i].left_fork);
        pthread_mutex_destroy(&philosophers[i].right_fork);
        i++;
    }
    return 0;
}