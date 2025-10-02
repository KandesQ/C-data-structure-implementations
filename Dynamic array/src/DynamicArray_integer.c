//
//  DynamicArray_integer.c
//
//  Dynamic array
//
//  The realization of DynamicArray to store
//  integers
//
//
//  Created by Fedor Kapranov, 5.10.2025
//

// TODO: rename DynamicArray to DynamicList

#include <stdio.h>

#include "DynamicArray.h"


/**
 * The file for working with DynamicArray as
 * an integer array
 */


 #define INITIAL_CAPACITY_INT 50 


 DynamicArray* DynamicArray_init_integer() 
 {
    DynamicArray* dynamic_array = (DynamicArray*) malloc(sizeof(DynamicArray));
    if (dynamic_array == NULL) return NULL;

    dynamic_array->size = 0;
    dynamic_array->_capacity = INITIAL_CAPACITY_INT;

    dynamic_array->data_type = INTEGER;
    dynamic_array->_inner_array = malloc(dynamic_array->_capacity * sizeof(int));
    if (dynamic_array->_inner_array == NULL) {
        free(dynamic_array);
        return NULL;
    }

    return dynamic_array;
}


static int _DynamicArray_expand_integer_inner_array(DynamicArray* integer_array);

int DynamicArray_add_integer(DynamicArray* integer_array, int el) 
{
    if (integer_array->size == integer_array->_capacity) {
        int expand_status = _DynamicArray_expand_integer_inner_array(integer_array);
        if (expand_status != 0) return -1;
    }

    ((int*) integer_array->_inner_array)[integer_array->size] = el;
    integer_array->size++;

    return 0;
}

// TODO: implement pop method

// TODO: implement insert method

// TODO: implement remove method

void DynamicArray_print_integer(DynamicArray* array)
{
    printf("Integer array: ");
    printf("[");
    for (size_t i = 0; i < array->size; i++)
    {   
        printf("%i", ((int*) array->_inner_array)[i]);
        
        if (i != array->size - 1) printf(", ");
    }
    printf("]\n");
}


int DynamicArray_destroy_integer(DynamicArray* array)
{
    free((array)->_inner_array);
    (array)->_inner_array = NULL;

    return 0;
}


static int _DynamicArray_copy_integer_inner_array(const int* src, size_t src_size, int* dest);

static int _DynamicArray_expand_integer_inner_array(DynamicArray* integer_array) 
{
    size_t new_capacity = integer_array->_capacity * 2;
    
    void* new_inner_array = malloc(new_capacity * sizeof(int));
    if (new_inner_array == NULL) return -1;

    _DynamicArray_copy_integer_inner_array((int*) integer_array->_inner_array, integer_array->size, (int*) new_inner_array);

    free(integer_array->_inner_array);

    integer_array->_inner_array = new_inner_array;
    integer_array->_capacity = new_capacity;

    return 0;
}

static int _DynamicArray_copy_integer_inner_array(const int* src, size_t src_size, int* dest)
{
    for (size_t i = 0; i < src_size; i++)
    {
        dest[i] = src[i];
    }
    
    return 0;
}
