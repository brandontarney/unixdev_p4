/*
 * Process to write information into the shared memory according to the required structure at certain intervals
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
        printf("Hello World");
        exit (0);
}
