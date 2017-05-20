/*
 * Random Fortune Generator
 *
 * - exervice knowledge of popen() functino call, as well as experience with non-blocking or multiplexed I/O
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
 * - Execute a loop that runs at random intervals (1-8 seconds) the ~jcn/unix_class/fortune/fortune (dev4) and ~jcn/unix_class/fortunre_absaroka/fortunre (absaroka) command
 *      via the popen() function call
 * - Implemented delay must not be a busy wait & no delay before the first fortune is printed. The output of the fortune command will be placed (in the pipe created by popen()) to be read from your main program (and output to screen)
 * - To terminate th eloop, handle STDIN 'q' and exit. TO do this (non-blocking) ther eare several ways: make standard input non-blocking, use signal-driven I/O, or use multiplexed I/O using slsect()

main()
{
        printf("Hello World");
        exit (0);
}
