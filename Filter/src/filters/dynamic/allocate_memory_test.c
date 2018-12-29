/*
 * allocate_memory_test.c
 *
 *  Created on: 27 dec. 2018
 *      Author: User
 */

#include "allocate_memory_test.h"


void allocate_memory_test(struct Test_Data* Data, uint32_t dim) {
	Data->vec_f32 = malloc(dim*sizeof(float32_t));
	Data->mat_f32 = malloc(2*dim*sizeof(float32_t));
}

void free_memory_test(struct Test_Data* Data) {
	free(Data->vec_f32);
	free(Data->mat_f32);
}
