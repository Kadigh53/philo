// #include <semaphore.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <stdlib.h>

// void *routine(void *arg)
// {
//     sem_t *fork_sem = (sem_t *)arg;

//     printf("* 1 *\n");
//     sem_wait(fork_sem);
//     printf("* 222 *\n");
//     sleep(2);
//     sem_post(fork_sem);
//     return NULL;
// }

// int main()
// {
//     int pid;
//     int i;
//     sem_t *forks_sem;

//     // Use a valid semaphore name starting with a forward slash
//     forks_sem = sem_open("/forks", O_CREAT | O_EXCL, 0700, 1);

//     if (forks_sem == SEM_FAILED) {
//         perror("sem_open");
//         return 1;
//     }

//     i = -1;
//     while (++i < 3) {
//         pid = fork();
//         if (pid == -1) {
//             printf("error\n");
//         } else if (pid == 0) {
//             routine(forks_sem);
//             exit(0);
//         }
//     }
//     while (wait(NULL) != -1);
    
//     // Close and unlink the semaphore
//     sem_close(forks_sem);
//     sem_unlink("/forks");

//     return 0;
// }
