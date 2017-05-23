/*
 * Process to write information into the shared memory according to the required structure at certain intervals
 *
 * SHM format:

 array of 20 structs ->

 struct {
        int isValid;
        float x;
        float y;
        };
 *
 
 * @author Brandon Tarney
 * @date    5/11/2017
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shared_memory.h"

struct data {
        int isValid;
        float x;
        float y;
};

struct data *dataPtr;

/*
 * MAIN
 *
 *  - call connect_shm() which should return a pointer to the shared memory area
 *  - write data to the shared memory 
 *      - wait some time in between writing to shared memory
 *  - call destroy_shm() to delete the shared memory segment from the system
 *  - Exit
 */
main()
{
        printf("SHM Start\n");
        int key = 42;
        int shmSize = 100;

        dataPtr = (struct data *) connect_shm(key, shmSize);
        if (dataPtr == NULL)
        {
                printf("Shared memory failed to allocated, exiting\n");
                exit(-1);
        }

        int counter;
        for (counter = 0; counter < 5; counter++)
        {
                if (counter%2 == 0)
                {
                        dataPtr->isValid = 1;
                }
                else
                {
                        dataPtr->isValid = 0;
                }
                dataPtr->x = counter * 0.5;
                dataPtr->y = counter / 0.5;
                sleep(1);
        }

        if (destroy_shm(key) == -1)
        {
                printf("Shared memory failed to detach, exiting\n");
                exit(-1);
        }
        exit (0);
}

