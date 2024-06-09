#include <stdio.h>

void main_function () {
  char is_open[100] = { 0 };
  int pass, door;

  /* do the 100 passes */
  for (pass = 0; pass < 100; ++pass)
    for (door = pass; door < 100; door += pass+1)
      is_open[door] = !is_open[door];

  /* output the result */
  // for (door = 0; door < 100; ++door)
  //   printf("Door %d is %s\n", door+1, (is_open[door]? "Open" : "Closed"));
}

int main()
{
  for (int i = 0; i < 1; i++) { //120000000
    main_function();
  }

  return 0;
}
