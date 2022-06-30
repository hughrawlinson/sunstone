#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <json_object.h>

void getReadFrom(char* filename, int argc, char *argv[]) {
  strcpy(filename, "./testinput.txt");

  for (int i = 0; i < argc; i++) {
    if (strncmp("--tty=", argv[i], strlen("--tty=")) == 0) {
      strcpy(filename, argv[i]+6);
    }
  }
}

int main(int argc, char *argv[]) {
  char filename[512];

  getReadFrom(filename, argc, argv);

  printf("%s\n", filename);

  FILE *fptr;
  fptr = fopen(filename, "rb");

  if (fptr == NULL) {
    printf("Failed to open %s. Errno: %d\n", filename, errno);

    exit(1);
  }

  bool started = false;
  bool finished = false;
  char* telegram[5000];

  json_object obj = json_object_new_object();

  while (!finished) {
    char line[1000];
    fscanf(fptr, "%[^\n]", line);

    if (!started) {
    } else {
    }

    finished = true;
    printf("%s\n", line);
  }

  printf("%s\n", obj);

  fclose(fptr);
  json_object_put(obj);
  exit(EXIT_SUCCESS);
}

