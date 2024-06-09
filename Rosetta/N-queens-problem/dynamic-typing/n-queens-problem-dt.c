#include <stdio.h>
#include <stdlib.h>
#include "json.h"

typedef unsigned int uint;
// uint count = 0;
JSON* count;

// #define ulen sizeof(uint) * 8
#define ulen json_mul_numbers(json_create_size(sizeof(uint)), json_create_size(8))

/* could have defined as int solve(...), but void may have less
   chance to confuse poor optimizer */
void solve(JSON* n)
{
	// int cnt = 0;
	JSON* cnt = json_create_number(0);
	// const uint full = -(int)(1 << (ulen - n));
	JSON *full = json_create_number32(json_as_number(json_not_number(json_left_shift(json_create_number(1), json_sub_numbers(ulen, n))))); //here it is possible that i get an error, I'm not sure what type json_left_shift will return
	// register uint bits, pos, *m, d, e;
	JSON *bits = json_create_number32(0);
	JSON *pos = json_create_number32(0); 
	JSON *d = json_create_number32(0);
	JSON *e = json_create_number32(0);
	JSON *array [] = {json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), 
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0)};
	JSON * m = json_create_vector (array, 40);
	// uint b0, b1, l[32], r[32], c[32], mm[33] = {0};
	JSON *b0 = json_create_number32(0);
	JSON *b1 = json_create_number32(0);
	JSON *array1[] = {json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), 
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0)};
	JSON *l = json_create_vector(array1, 32);
	JSON *array2[] = {json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), 
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0)};
	JSON *r = json_create_vector(array2, 32);
	JSON *array3[] = {json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), 
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0)};
	JSON *c = json_create_vector(array3, 32);
	JSON *array4[] = {json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), 
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0), json_create_number32(0),
					  json_create_number32(0), json_create_number32(0), json_create_number32(0)};
	JSON *mm = json_create_vector(array4, 33);

	// n -= 3;
	json_assignment(n, json_sub_numbers(n, json_create_number(3)));
	/* require second queen to be left of the first queen, so
	   we ever only test half of the possible solutions. This
	   is why we can't handle n=1 here */
	// for (b0 = 1U << (ulen - n - 3); b0; b0 <<= 1) {
	for (json_assignment(b0, json_left_shift(json_create_number32(1), json_sub_numbers(ulen, json_add_numbers(n, json_create_number(3))))); json_greater_than(b0, json_create_number32(0)); json_assignment(b0, json_left_shift(b0, json_create_number(1)))){
		// for (b1 = b0 << 2; b1; b1 <<= 1) {
		for (json_assignment(b1, json_left_shift(b0, json_create_number32(2))); json_greater_than(b1, json_create_number32(0)); json_assignment(b1, json_left_shift(b1, json_create_number(1)))){
			// d = n;
			json_assignment(d, json_create_number32(json_as_number(n)));

			/* c: columns occupied by previous queens.
			   l: columns attacked by left diagonals
			   r: by right diagnoals */
			// c[n] = b0 | b1;
			json_array_set(c, json_as_number(n), json_or_numbers(b0, b1));
			// l[n] = (b0 << 2) | (b1 << 1);
			json_array_set(l, json_as_number(n), json_or_numbers(json_left_shift(b0, json_create_number(2)), json_left_shift(b1, json_create_number(1))));
			// r[n] = (b0 >> 2) | (b1 >> 1);
			json_array_set(r, json_as_number(n), json_or_numbers(json_right_shift(b0, json_create_number(2)), json_right_shift(b1, json_create_number(1))));

			/* availabe columns on current row. m is stack */
			// bits = *(m = mm + 1) = full & ~(l[n] | r[n] | c[n]);
			json_array_set(mm, 1, json_and_numbers(full, json_tilde(json_or_numbers(json_or_numbers(json_array_get(l, json_as_number(n)), json_array_get(r, json_as_number(n))), json_array_get(c, json_as_number(n))))));
			json_assignment(m, mm);
			json_increment(m);
			json_assignment(bits, json_and_numbers(full, json_tilde(json_or_numbers(json_or_numbers(json_array_get(l, json_as_number(n)), json_array_get(r, json_as_number(n))), json_array_get(c, json_as_number(n))))));
			while (json_greater_than(bits, json_create_number32(0))) {
				/* d: depth, aka row. counting backwards
				   because !d is often faster than d != n */
				while (json_greater_than(d, json_create_number32(0))) {	
					/* pos is right most nonzero bit */
					// pos = -(int)bits & bits;
					json_assignment(pos, json_and_numbers(json_not_number(json_create_number(json_as_number32(bits))), bits));

					/* mark bit used. only put current bits
					   on stack if not zero, so backtracking
					   will skip exhausted rows (because reading
					   stack variable is sloooow compared to
					   registers) */
					// if ((bits &= ~pos))
						// *m++ = bits | d;					
					json_assignment(bits, json_and_numbers(bits, json_tilde(pos))); //?????
					if (json_unequals(bits, json_create_number32(0))) {
						json_array_set(m, 0, json_or_numbers(bits, d));
						json_increment(m);
					}


					/* faster than l[d+1] = l[d]... */
					// e = d--;
					json_assignment(e, json_decrement(d));
					// l[d] = (l[e] | pos) << 1;
					json_array_set(l, json_as_number32(d), json_left_shift(json_or_numbers(json_array_get(l, json_as_number32(e)), pos), json_create_number32(1)));					
					// r[d] = (r[e] | pos) >> 1;
					json_array_set(r, json_as_number32(d), json_right_shift(json_or_numbers(json_array_get(r, json_as_number32(e)), pos), json_create_number32(1)));
					// c[d] =  c[e] | pos;
					json_array_set(c, json_as_number32(d), json_or_numbers(json_array_get(c, json_as_number32(e)), pos));

					// bits = full & ~(l[d] | r[d] | c[d]);
					json_assignment(bits, json_and_numbers(full, json_tilde(json_or_numbers(json_or_numbers(json_array_get(l, json_as_number32(d)), json_array_get(r, json_as_number32(d))), json_array_get(c, json_as_number32(d))))));	

					// if (!bits) break;
					if (json_equals(bits, json_create_number32(0))) break;
					// if (!d) { cnt++; break; }
					if (json_equals(d, json_create_number32(0))) { json_increment(cnt); break; }
				}
				/* Bottom of stack m is a zero'd field acting
				   as sentinel.  When saving to stack, left
				   27 bits are the available columns, while
				   right 5 bits is the depth. Hence solution
				   is limited to size 27 board -- not that it
				   matters in foreseeable future. */
				// d = (bits = *--m) & 31U;
				json_decrement(m);
				json_assignment(bits, json_array_get(m, 0));
				json_assignment(d, json_and_numbers(bits, json_create_number32(31U)));
				// bits &= ~31U;
				json_assignment(bits, json_and_numbers(bits, json_tilde(json_create_number32(31U))));
			}
		}
	}
	// count = cnt * 2;
	json_assignment(count, json_mul_numbers(cnt, json_create_number(2)));
}

void main_function() {
	count = json_create_number(0);
	//int nn;
	JSON* nn = json_create_number(0);
	json_assignment(nn, json_create_number(12));
	if ( json_greater_than(nn, json_create_number(27))) {
		fprintf(stderr, "Value too large, abort\n");
		exit(1);
	}

	/* Can't solve size 1 board; might as well skip 2 and 3 */
	if (json_lesser_than(nn, json_create_number(4))) count = json_create_number( (int) json_equals(nn, json_create_number(1)));
	else	    solve(nn);

	// printf("Solutions: ");
	// json_print(count);
	// printf("\n");
}

int main(int c, char **v)
{
	for (int i = 0; i < 1; i++) { //300
		main_function();
	}
	return 0;
}
