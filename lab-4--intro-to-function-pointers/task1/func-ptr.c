#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#include "process.h"
#include "util.h"

#define DEBUG 0			//change this to 1 to enable verbose output

//help: stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work

/**
 * Signature for an function pointer that can compare
 * You need to cast the input into its actual 
 * type and then compare them according to your
 * custom logic
 */
typedef int (*Comparer) (const void *a, const void *b);

/**
 * compares 2 processes
 * You can assume: 
 * - Process ids will be unique
 * - No 2 processes will have same arrival time
 */
int my_comparer_first(const void *this, const void *that){
	//TODO: IMPLEMENT ME!
  int first_num = *(((int*)this + 2) );
  int second_num = *(((int*)that + 2) );
  
  return(second_num - first_num);
}

int my_comparer_second(const void *this, const void *that){

  int first_num = *(((int*)this + 1) );
  int second_num = *(((int*)that + 1) );

  return(first_num - second_num);
}

int main(int argc, char *argv[])
{

  int count;
  int i;

  for(i=0; i<2; i++){
    if (argc < 2) {
		  fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
		  fflush(stdout);
		  return 1;
	  }  

	/*******************/
	/* Parse the input */
	/*******************/
	  FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error: Invalid filepath\n");
        fflush(stdout);
        return 1;
    }

	  Process *processes = parse_file(input_file);

	/*******************/
	/* sort the input  */
	/*******************/
	  Comparer process_comparer;

  if(count == 0){
    printf("\nThis is sorted by priority\n");
    process_comparer = &my_comparer_first;
  }
  else{
    printf("\nThis is is sorted by arrival time\n");
		process_comparer = &my_comparer_second;
  }

#if DEBUG
	      for (int i = 0; i < P_SIZE; i++) {
		      printf("%d (%d, %d) ",
				              processes[i].pid,
				              processes[i].priority, processes[i].arrival_time);
	      }
	      printf("\n");
#endif

	      qsort(processes, P_SIZE, sizeof(Process), process_comparer);

	/**************************/
	/* print the sorted data  */
	/**************************/

        for (int i = 0; i < P_SIZE; i++) {
              printf("%d (%d, %d)\n",
              processes[i].pid,
              processes[i].priority, processes[i].arrival_time);
        }
        fflush(stdout);
        fflush(stderr);

	/************/
	/* clean up */
	/************/
        free(processes);
        fclose(input_file);
	    count ++;
    }
        return 0;
}
