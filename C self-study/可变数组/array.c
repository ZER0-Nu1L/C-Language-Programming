#include "array.h" 

//typedef struct {
//	int * array;
//	int size;
//}Array;

Array array_create(int inti_size)
{
	
}
void array_free(Array *a);
int array_size(const Array *a);
int *array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);

