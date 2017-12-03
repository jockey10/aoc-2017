# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define DROWS 16
# define DCOLS 16
# define BUF 255
# define LMAX 100000
# define LMIN 0

/**
 * Advent of Code 2017 - Day 2, part 1
 * -----------------------------------
 *
 * Takes a multi-dimensional array, and for each
 * row, calculates the local max and min. A checksum
 * is then calculated which is simply the sum of the
 * deltas for each row's local max and min.
 *
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
    int localmin=LMAX;
    int localmax = LMIN;
    for(j=0; j<DCOLS; j++) {
      int val = data[i][j];
      if (val < localmin) {
        localmin = val;
      }
      if (val > localmax) {
        localmax = val;
      }
    }
    checksum  += localmax - localmin;
  }

  printf("checksum is %d\n",checksum);
  return 0;
}
