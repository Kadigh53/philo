/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:15:18 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/16 21:37:04 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int main() {
//     printf("\x1b[1;31mRed text\x1b[0m\n");
//     printf("\x1b[32mGreen text\x1b[0m\n");
//     printf("\x1b[33mYellow text\x1b[0m\n");
//     printf("\x1b[34mBlue text\x1b[0m\n");
//     printf("\x1b[35mMagenta text\x1b[0m\n");
//     printf("\x1b[36mCyan text\x1b[0m\n");
//     printf("\x1b[37mWhite text\x1b[0m\n");
//     printf("\x1b[1m\x1b[4m\x1b[31m\x1b[44mHello, world!\x1b[0m\n");
//     printf("\033[1mThis text is bold\033[0m\n");
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

// typedef struct list
// {
//     int *x;
// } t_list;

// typedef struct liist
// {
//     t_list *list;
//     int y;
// } liist;

// void f(liist **a)
// {
//     t_list *b;
//     b = (t_list *)malloc(sizeof(t_list));
//     (*a)->list = b;
//     (*a)->y = 12023;
//     b->x = &(*a)->y;
//     printf("%d", *(b->x));
// }
int main() {
    int *p;
    int a = 5;
    p = &a;
    printf("%d", *p);
}