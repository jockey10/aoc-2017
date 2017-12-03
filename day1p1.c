# include <stdio.h>
# include <unistd.h>

# define STDIN_FILENO 0
# define BUFFER_SIZE 2103
# define VALID_LENGTH 2102

/**
 * Advent of Code 2017 - Day 1
 * ---------------------------
 *
 * Takes a sequence of integers from stdin. If any integer
 * in the sequence matches the next, add the integer value
 * to a running sub-total.
 *
 * Note that the integer sequence represents a circular list.
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

  // iterate and sum if the values match
  int total = 0;
  for (i=0; i<VALID_LENGTH-1; i++) {
    int curr = nums[i];
    int next = nums[i+1];
    if (curr == next) {
      total += curr;
    }
  }

  // now test the last value in the circular list
  int last = nums[VALID_LENGTH-1];
  int first = nums[0];

  if (first == last) {
    total += first;
  }

  // print result
  printf("total is %d\n", total);
  return 0;
}
