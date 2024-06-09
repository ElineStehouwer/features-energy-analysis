#include <stdio.h>
#include <stdlib.h>
#include "../headers-dt/json.h"

void main_function(){
  JSON *array[100] = { json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0),
                         json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0), json_create_char(0)};
  
  JSON *is_open = json_create_vector(array, 100);
  JSON *pass = json_create_number(0);
  JSON *door = json_create_number(0);
  // int pass, door;

  /* do the 100 passes */
  // for (pass = 0; pass < 100; ++pass)
      // for (door = pass; door < 100; door += pass+1)
  for (json_assignment(pass, json_create_number(0)); json_lesser_than(pass, json_create_number(100)); json_increment(pass))
    for (json_assignment(door, pass); json_lesser_than(door, json_create_number(100)); json_assignment(door, json_add_numbers(door, json_add_numbers(pass, json_create_number(1))) ) )
        json_array_set(is_open, json_as_number(door), json_negate_number(json_array_get(is_open, json_as_number(door))));
        // is_open[door] = !is_open[door];

  /* output the result */
  // for (door = 0; door < 100; ++door)
  // for (json_assignment(door, json_create_number(0)); json_lesser_than(door, json_create_number(100)); json_increment(door))
  //   printf("Door %d is %s\n", json_as_number(json_add_numbers(door, json_create_number(1))), (json_as_bool(json_array_get(is_open, json_as_number(door)))? "Open" : "Closed"));
  json_destroy(is_open);
  json_destroy(pass);
  json_destroy(door);
}

int main()
{
  for (int i = 0; i < 1; i++) { //600000
    main_function();
  }
  
  return 0;
}
