#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
int main(int argc, int *argv[])
{
int i;
int b_flag = 0;
int start = 0;
int end = 0;

for (i=1; i < argc; i++) {
if (strcmp((const char*) argv[i], "-b") == 0) {
  b_flag=1;
  start = atoi(argv[i+1]);
  end = atoi(argv[i+2]);
  break;
}
}
if (b_flag == 0 && argc > 1 && strcmp(argv[1], "-v") == 0) {
printf("This is a sample program.\n");
}
if (b_flag == 1) {
  for (i= start; i <= end; i++) {
    char command[100];
    sprintf(command, "adb shell locksettings clear %04d", i);
    system(command);
  }
}
  return 0;
}

