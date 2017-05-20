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

//TODO make this app
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
        printf("Hello World");
        exit (0);
}
