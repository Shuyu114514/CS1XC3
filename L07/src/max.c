/*******************************************************************************
*
* Purpose: Prints the maximum number of any number of int command-line 
* arguments that are provided.  So if this program is run with:
*   ./max 5 10 20 25 15
* then we can expect it to print 25.
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(int argc, char *argv[])
{

  //int m;
  //scanf("%d", &m);
  
  int temp[argc-1];
  for (int i=0; i<argc; i++){
      temp[i] = atoi(argv[i]);
  }
  printf("%d\n", max(temp, argc));

  return 0;
}