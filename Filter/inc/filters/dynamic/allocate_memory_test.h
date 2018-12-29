/*
 * allocate_memory_test.h
 *
 *  Created on: 27 dec. 2018
 *      Author: User
 */

#ifndef FILTERS_DYNAMIC_ALLOCATE_MEMORY_TEST_H_
#define FILTERS_DYNAMIC_ALLOCATE_MEMORY_TEST_H_

#include "test_dynamic_data.h"
#include <stdlib.h>

void allocate_memory_test(struct Test_Data* Data, uint32_t dim);
void free_memory_test(struct Test_Data* Data);

#endif /* FILTERS_DYNAMIC_ALLOCATE_MEMORY_TEST_H_ */
