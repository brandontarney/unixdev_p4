/*
 * Proces to monitor the state of the data contained in the hsared memory and report certain statistics
 *
 * SHM format:

 array of 20 structs ->

 struct {
        int is_valid;
        float x;
        float y;
        };
 *
 * @author Brandon Tarney
 * @date    5/11/2017
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
 * Approximately each second, print a line of information to the screen about the contents of the shared memory, reporting the following:
 *  - Count of active array elements (isValid)
 *  - Average X value over the active elements
 *  - Average Y value over the active elements
 * Before monitor_shm exits, it shall detach (but not destroy) the shared memory segment
 */
main()
{
        printf("monitor_shm()\n");
        int key = 42;
        int shmSize = 100;

        dataPtr = (struct data *) connect_shm(key, shmSize);
        if (dataPtr == NULL)
        {
                printf("Shared memory failed to allocated, exiting\n");
                exit(-1);
        }
        sleep(1);
        int counter;
        for (counter = 0; counter < 3; counter++)
        {
                printf("isValid (%d), X (%f), Y (%f)\n",
                                dataPtr->isValid,
                                dataPtr->x,
                                dataPtr->y);
                sleep(1);
        }
        detach_shm(dataPtr);

        exit (0);
}
