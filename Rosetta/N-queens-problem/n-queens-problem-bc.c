#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define setSafe(array, index, size, value) {\
    if (index < 0 || index >= size) {\
        fprintf(stderr, "Error: Index out of bounds\n");\
        exit(EXIT_FAILURE);\
    }\
    array[index] = value;\
}

#define getSafe(array, index, size) ({\
    if (index < 0 || index >= size) {\
        fprintf(stderr, "Error: Index out of bounds\n");\
        exit(EXIT_FAILURE);\
    }\
    array[index];\
})

void *getArrayValueSafe(void *array, size_t index, size_t size, size_t element_size) {
    if (index < 0 || index >= size) {
        fprintf(stderr, "Error: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    // Calculate the offset in bytes
    size_t offset = index * element_size;

    // Cast the void pointer to the appropriate type and add the offset
    void *address = (char *)array + offset;

    // Return the pointer to the element
    return address;
}

void setArrayValueSafe(void *array, size_t index, size_t size, size_t element_size, void *value) {

    // Check if the index is within bounds
    if (index < 0 || index >= size) {
        fprintf(stderr, "Error: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    // Calculate the offset in bytes
    size_t offset = index * element_size;

    // Cast the void pointer to the appropriate type and add the offset
    void *address = (char *)array + offset;

    // Copy the value to the memory location
    memcpy(address, value, element_size);
}

typedef unsigned int uint;
uint count = 0;

#define ulen sizeof(uint) * 8

/* could have defined as int solve(...), but void may have less
   chance to confuse poor optimizer */
void solve(int n)
{
	int cnt = 0;
	const uint full = -(int)(1 << (ulen - n));
	register uint bits, pos, *m, d, e;
	uint new_value;
	uint b0, b1, l[32], r[32], c[32], mm[33] = {0};
	n -= 3;
	/* require second queen to be left of the first queen, so
	   we ever only test half of the possible solutions. This
	   is why we can't handle n=1 here */
	for (b0 = 1U << (ulen - n - 3); b0; b0 <<= 1) {
		for (b1 = b0 << 2; b1; b1 <<= 1) {
			d = n;
			/* c: columns occupied by previous queens.
			   l: columns attacked by left diagonals
			   r: by right diagnoals */
			// c[n] = b0 | b1;
			new_value = b0 | b1;
			// setArrayValueSafe(c, n, 32, sizeof(uint), &new_value);
			setSafe(c, n, 32, new_value);
			// l[n] = (b0 << 2) | (b1 << 1);
			new_value = (b0 << 2) | (b1 << 1);
			// setArrayValueSafe(l, n, 32, sizeof(uint), &new_value);
			setSafe(l, n, 32, new_value);
			// r[n] = (b0 >> 2) | (b1 >> 1);
			new_value = (b0 >> 2) | (b1 >> 1);
			// setArrayValueSafe(r, n, 32, sizeof(uint), &new_value);
			setSafe(r, n, 32, new_value);

			/* availabe columns on current row. m is stack */
			bits = *(m = mm + 1) = full & ~(l[n] | r[n] | c[n]);

			while (bits) {
				/* d: depth, aka row. counting backwards
				   because !d is often faster than d != n */
				while (d) {
					/* pos is right most nonzero bit */
					pos = -(int)bits & bits;

					/* mark bit used. only put current bits
					   on stack if not zero, so backtracking
					   will skip exhausted rows (because reading
					   stack variable is sloooow compared to
					   registers) */
					if ((bits &= ~pos))
						*m++ = bits | d;

					/* faster than l[d+1] = l[d]... */
					e = d--;
					// l[d] = (l[e] | pos) << 1;
					new_value = (l[e] | pos) << 1;
					// setArrayValueSafe(l, d, 32, sizeof(uint), &new_value);
					setSafe(l, d, 32, new_value);
					// r[d] = (r[e] | pos) >> 1;
					new_value = (getSafe(r, e, 32) | pos) >> 1;
					// setArrayValueSafe(r, d, 32, sizeof(uint), &new_value);
					setSafe(r, d, 32, new_value);
					// c[d] =  c[e] | pos;
					new_value = (getSafe(c, e, 32) | pos);
					// setArrayValueSafe(c, d, 32, sizeof(uint), &new_value);
					setSafe(c, d, 32, new_value);

					// bits = full & ~(l[d] | r[d] | c[d]);
					bits = full & ~(getSafe(l, d, 32) | getSafe(r, d, 32) | getSafe(c, d, 32));
					if (!bits) break;
					if (!d) { cnt++; break; }
				}
				/* Bottom of stack m is a zero'd field acting
				   as sentinel.  When saving to stack, left
				   27 bits are the available columns, while
				   right 5 bits is the depth. Hence solution
				   is limited to size 27 board -- not that it
				   matters in foreseeable future. */
				d = (bits = *--m) & 31U;
				bits &= ~31U;
			}
		}
	}
	count = cnt * 2;
}

void main_function(){
	int nn;
	nn = 12;

	if (nn > 27) {
		fprintf(stderr, "Value too large, abort\n");
		exit(1);
	}

	/* Can't solve size 1 board; might as well skip 2 and 3 */
	if (nn < 4) count = nn == 1;
	else	    solve(nn);

	// printf("Solutions: %d\n", count);
}

int main(int c, char **v)
{
	for (int i = 0; i < 1; i++) {//9000
		main_function();
	}
	return 0;
}
