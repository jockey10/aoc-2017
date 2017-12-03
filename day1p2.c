# include <stdio.h>
# include <unistd.h>

# define STDIN_FILENO 0
# define BUFFER_SIZE 2103
# define VALID_LENGTH 2102
# define MIDPOINT 1051

/**
 * Advent of Code 2017 - Day 1, Part 2
 * -----------------------------------
 *
 * Takes a sequence of integers from stdin representing
 * a circular list. If any given integer matches the integer
 * halfway around the circular list, add it to a running
 * sub-total.
 */
int main() {
  // initialise array from stdin
  int nums[BUFFER_SIZE];
  int i = 0;
  char ch;
  while (read(STDIN_FILENO, &ch, 1) > 0) {
    nums[i] = ch - '0';
    i++;
  }

  //check the first-half of the list
  int total = 0;
  for (i=0; i<MIDPOINT; i++) {
    int curr = nums[i];
    int other = nums[MIDPOINT+i];
    if (curr == other) {
      total += curr;
    }
  }

  //check the second-half
  for (i=MIDPOINT; i<VALID_LENGTH-1; i++) {
    int curr = nums[i];
    int other = nums[i-MIDPOINT];
    if (curr == other) {
      total += curr;
    }
  }

  // print result
  printf("total is %d\n", total);
  return 0;
}
