# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define DROWS 16
# define DCOLS 16
# define BUF 255

/**
 * Advent of Code 2017 - Day 2, part2
 * ----------------------------------
 *
 * Takes a multi-dimensional array, and for each row,
 * determines whether any integers divide evenly.
 *
 * A checksum is calculated which is the sum of the
 * quotients of any cleanly dividing integers found.
 */
int main(int argc, char * argv[] ) {

  FILE *handle;
  char buffer[BUF];

  int data[DROWS][DCOLS];

  //build the multidimensional array
  handle = fopen(argv[1],"r");
  int i = 0;
  while(fgets(buffer,BUF,(FILE*) handle)) {
    char* str = strtok(buffer," ");
    data[i][0] = atoi(str);
    int j = 1;
    while((str = strtok(NULL," ")) != NULL) {
      data[i][j] = atoi(str);
      j++;
    }
    i++;
  }

  //calculate the checksum
  int checksum = 0;
  int j;
  for(i=0; i<DROWS; i++) {
    for(j=0; j<DCOLS; j++) {
      int val = data[i][j];
      int x;
      for (x=0; x<DCOLS; x++) {
        int div = data[i][x];
        if ((div != val) && (val % div == 0))
          checksum += val/div;
      }
    }
  }

  printf("checksum is %d\n",checksum);
  return 0;
}
