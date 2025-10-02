//
//  DynamicArray_float.c
//
//  Dynamic array
//
//  The realization of DynamicArray to store
//  float numbers
//
//
//  Created by Fedor Kapranov, 5.10.2025
//

// TODO: rename DynamicArray to DynamicList

#include "stdio.h"

#include "DynamicArray.h"


#define INITIAL_CAPACITY_FLOAT 50



DynamicArray* DynamicList_init_float() {
    DynamicArray* dynamic_array = (DynamicArray*) malloc(sizeof(DynamicArray));
    if (dynamic_array == NULL) return NULL;

    dynamic_array->size = 0;
    dynamic_array->_capacity = INITIAL_CAPACITY_FLOAT;

    dynamic_array->data_type = FLOAT;
    dynamic_array->_inner_array = malloc(dynamic_array->_capacity * sizeof(float));
    if (dynamic_array->_inner_array == NULL) {
        free(dynamic_array);
        return NULL;
    }

    return dynamic_array;
}


int _DynamicList_expand_float_inner_array(DynamicArray* float_array);

int DynamicList_add_float(DynamicArray* float_list, float el) {
    if (float_list->size == float_list->_capacity) {
        int expand_status = _DynamicList_expand_float_inner_array(float_list);
        if (expand_status != 0) return -1;
    }
    
    ((float*) float_list->_inner_array)[float_list->size] = el;
    float_list->size++;

    return 0;
}


static int _DynamicList_shrink_float(DynamicArray* float_list);

float DynamicList_pop_float(DynamicArray* float_list) {
    if (float_list->size == 0) {
        float default_value = -1;
        printf("Error in file: DynamicArray_float.c at DynamicArray_pop_float: attempt to pop element from empty array");
        printf(". Return default value %.4f", default_value);
        return default_value;
    }

    float popped_element = ((float*) float_list->_inner_array)[float_list->size - 1];
    float_list->size--;
    _DynamicList_shrink_float(float_list);

    return popped_element;
}

// TODO: implement insert method

// TODO: implement remove method

void DynamicList_print_float(DynamicArray* float_list)
{
    printf("Float array: ");
    printf("[");
    for (size_t i = 0; i < float_list->size; i++)
    {   
        printf("%.4f", ((float*) float_list->_inner_array)[i]);
        
        if (i != float_list->size - 1) printf(", ");
    }
    printf("]\n");
}


int DynamicList_destroy_float(DynamicArray* float_list) {
    free(float_list->_inner_array);
    float_list->_inner_array = NULL;

    return 0;
}


static void _DynamicList_copy_float_inner_array(const float* src, size_t src_size, float* dest);

/**
 * @brief Expands the array capacity by pointer
 *
 * @details Changes _inner_array to a new one that's twice as large as before
 * 
 * @param float_list - the original list
 * 
 * @retval 0 - success
 * @retval -1 - couldn't initialize new inner array
 * 
 * @warning Modifies the original list through a pointer
 */
int _DynamicList_expand_float_inner_array(DynamicArray* float_list)
{
    size_t new_capacity = float_list->_capacity * 2;

    void* new_inner_array = malloc(new_capacity * sizeof(float));
    if (new_inner_array == NULL) return -1;

    _DynamicList_copy_float_inner_array((float*) float_list->_inner_array, float_list->size, (float*) new_inner_array);

    float_list->_inner_array = new_inner_array;
    float_list->_capacity = new_capacity;

    return 0;
}

/**
 * @brief Places a copy of source list to a destination list
 * 
 * @param src - source list pointer
 * @param src_size - the size of source list
 * @param dest - destination list pointer
 * 
 * @warning Modifies destination list
 */
static void _DynamicList_copy_float_inner_array(const float* src, size_t src_size, float* dest)
{
    for (size_t i = 0; i < src_size; i++)
    {
        dest[i] = src[i];
    }
}

/**
 * @brief Shrinks list if its size is four times its capacity
 * 
 * @param float_list - the original list
 * 
 * @retval 0 - the list has been changed
 * @retval -1 - the list remain as it was
 * @retval 1 - coudn't allocate memory for new shrinked array
 * 
 * @warning Modifies the original list through a pointer
 */
static int _DynamicList_shrink_float(DynamicArray* float_list) {
    if (float_list->_capacity < 4 * float_list->size) return -1;

    // A half of old capacity is the new one
    size_t new_capacity = float_list->_capacity / 2;
    float* new_shrunk_inner_array = malloc(new_capacity * sizeof(float));
    if (new_shrunk_inner_array == NULL) return 1;

    _DynamicList_copy_float_inner_array(((float*) float_list->_inner_array), float_list->size, new_shrunk_inner_array);

    free(float_list->_inner_array);

    float_list->_inner_array = new_shrunk_inner_array;
    float_list->_capacity = new_capacity;

    return 0;
}
