#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getReadFrom(char *filename, int argc, char *argv[]) {
  strcpy(filename, "./testinput.txt");

  int i;

  for (i = 0; i < argc; i++) {
    if (strncmp("--tty=", argv[i], strlen("--tty=")) == 0) {
      strcpy(filename, argv[i] + 6);
    }
  }
}

FILE *getTTYHandler(char filename[]) {
  FILE *fptr;
  fptr = fopen(filename, "rb");

  if (fptr == NULL) {
    printf("Failed to open %s. Errno: %d\n", filename, errno);

    exit(1);
  }
  return fptr;
}

void getFirstTelegram(FILE *fptr) {
  bool started = false;
  bool finished = false;
  /* char* telegram[5000]; */

  while (!finished) {
    char line[1000];
    fscanf(fptr, "%[^\n]", line);

    if (!started) {
    } else {
    }

    finished = true;
    printf("%s\n", line);
  }
}

int main(int argc, char *argv[]) {
  char filename[512];

  getReadFrom(filename, argc, argv);

  printf("%s\n", filename);

  FILE *fptr = getTTYHandler(filename);

  getFirstTelegram(fptr);

  fclose(fptr);
  exit(EXIT_SUCCESS);
}
