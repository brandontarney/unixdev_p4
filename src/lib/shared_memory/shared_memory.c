/*
   * Library to handle shared memory
   *
   * @author brandon tarney
   * @date  5/17/2017
   */
#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "shared_memory.h"

  /*
   * CONNECT_SHM
   *
   *    This fcn has 2 arguments. the first argument serves as the key for the shared memory segment. The second argument contains the size (in bytes) of the shared memory to be allocated. The return value for this fcn is a pointer to the shared memory (created & attached by this fcn). On failure, returns NULL pointer

   *
   */
void * connect_shm(int key, int size)
{
        printf("connect_shm()\n");

        shmid = shmget (key, size, IPC_CREAT | 0666);
        if (shmid < 0)
        {                                                                                               
                perror ("shmget");
                exit(1);
        }

        shmAddr = shmat(shmid, NULL, 0 );
        if (shmAddr == (int *) -1)
        {
                perror ("shmat:first_int");
                exit (1);
        }

        printf("succesfully attached memory\n");
        return shmAddr;
}

  /*
   * DETACH_SHM
   *
   *    detaches the shared memory segment attached to the process via the argument addr. The associated shared memory segment is not deleted from the system. this fcn will return OK (0) on success & ERROR (-1) otherwise
   */
int detach_shm(void *addr)
{
        printf("detach_shm()\n");
        if (shmdt (shmAddr) < 0)
        {
                perror ("shmdt");
                exit (1);
        }
        return 0;
}


  /*
   * DESTROY_SHM
   *    detaches all shared memory segments (attached to the calling process by connect_shm()) associated with the argument key from the calling process. The shared memory segment is then subsquently deleted from the system. This fcn will return OK (0) on success, and ERROR (-1) otherwise
   *
   */
int destroy_shm(int key)
{
        printf("destroy_shm()\n");
        detach_shm(shmAddr);
        if (shmctl (shmid, IPC_RMID, 0) < 0)
        {
                perror ("shmctl");
                exit (1);
        }
        return 0;
}
