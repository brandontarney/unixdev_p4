/*
   * Library to handle shared memory
   *
   * @author brandon tarney
   * @date  5/17/2017
   */
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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
        return NULL;
}

  /*
   * DETACH_SHM
   *
   *    detaches the shared memory segment attached to the process via the argument addr. The associated shared memory segment is not deleted from the system. this fcn will return OK (0) on success & ERROR (-1) otherwise
   */
int detach_shm(void *addr)
{
        printf("detach_shm()\n");
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
        return 0;
}
