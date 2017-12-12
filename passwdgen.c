#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int to_int (char * numString);
int power (int base, int exp);

int main (int argc, char * argv[]) {

  if (argc > 2) {
    printf("%s\n", "usage: passwdgen <integer_length>");
    return 0;
  }

  int passwdLen = 8;

  if (argc == 2) {

    int numLen = strlen(argv[1]);

    for (int i = 0; i < numLen; i++) {
      if (argv[1][i] > 57 || argv[1][i] < 48) {
        printf("%s\n", "usage: passwdgen <integer_length>");
        return 0;
      }
    }

    passwdLen = to_int (argv[1]);
  }
  
  srand(time(NULL));

  while(passwdLen > 0) {
    printf("%c", (rand () % 93) + 33);
    passwdLen--;
  }

  printf("%s\n", "");

  return 0;
}

int to_int (char * numString) {
  int returnVal =  0;
  int len = strlen(numString);

  for (int i = 0; i < len; i++) {
    returnVal += (int) (numString[len - i - 1] - 48) * power (10,i);
  }


  return returnVal;
}

int power (int base, int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
 }
