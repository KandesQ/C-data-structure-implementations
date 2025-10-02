//
//  DynamicArray.h
//
//  Dynamic array
//
//  A study implementation of a structure called dynamic list
//  Supports only Integer, Float and String type
//
//
//  Created by Fedor Kapranov, 5.10.2025
//

// TODO: rename DynamicArray to DynamicList

#include <stddef.h>
#include <stdlib.h>

#ifndef DYNAMIC_ARRAY_H 
#define DYNAMIC_ARRAY_H



typedef struct 
{
    size_t size;
    enum {INTEGER, FLOAT, STRING} data_type;

    size_t _capacity;
    void* _inner_array;
} DynamicArray;

// TODO: rename DynamicArray to DynamicList


/**
 * DynamicArray constructor for integers
 * 
 * Success - returns a pointer to array that works with integers
 * Failure - returns NULL
 */
DynamicArray* DynamicArray_init_integer();

/**
 * DynamicArray constructor for float numbers
 * 
 * Success - returns a pointer to array that works with float numbers
 * Failure - returns NULL
 */
DynamicArray* DynamicList_init_float();

/**
 * DynamicArray constructor for strings
 * 
 * Success - returns a pointer to array that works with strings
 * Failure - returns NULL
 */
DynamicArray* DynamicArray_init_string();


/**
 * Add new element to the end of array
 * 
 * Params:
 *   array - array to add element
 *   el - adding element
 * 
 * Returns a completion status code:
 *   0 - successfully add new element
 *  -1 - couldn't add new element
 */
int DynamicArray_add_integer(DynamicArray* string_array, int el);

int DynamicList_add_float(DynamicArray* string_list, float el);

/**
 * The passed element doesn't free after function is done
 */
int DynamicArray_add_string(DynamicArray* string_array, const char* el);


/**
 * Pop an element from the end of array
 * 
 * Returns popped element if size is not 0. Otherwise, returns 0
 */
int DynamicArray_pop_integer(DynamicArray* integer_array);


/**
 * Pop an element from the end of array
 * 
 * Returns popped element if size is not 0. Otherwise, returns 0.0
 */
float DynamicList_pop_float(DynamicArray* float_list);


/**
 * Pop an element from the end of array
 * 
 * Returns popped element if size is not 0. Otherwise, returns emtpy string
 */
char* DynamicArray_pop_string(DynamicArray* string_array);


/**
 * Insert an element by index
 * 
 * Params:
 *   i - index of array
 *   el - inserting element
 *      
 * Returns completion status code:
 *   0 - successfully inserted new element
 *  -1 - couldn't insert new element
 */
int DynamicArray_insert_integer(size_t i, int el);

int DynamicArray_insert_float(size_t i, float el);

/**
 * The passed element doesn't free after function is done
 */
int DynamicArray_insert_string(size_t i, const char* el);


/**
 * Remove and return an element by specified index
 * 
 * Params:
 *   i - index of removable element
 */
int DynamicArray_remove_integer(size_t i);

float DynamicArray_remove_float(size_t i);

char* DynamicArray_remove_string(size_t i);


/**
 * Prints array in a pretty view
 */
void DynamicArray_print_integer(DynamicArray* integer_array);

void DynamicList_print_float(DynamicArray* float_list);

void DynamicArray_print_string(DynamicArray* string_array);

/**
 * Destroys struct and all inner dynamic variables
 * 
 * WARN: you must free space for dynamic array by yourself.
 * This method only frees inner resources
 * 
 * Returns:
 *   0 - if destroying was successfull
 *  -1 - if during destroying was failed
 */
int DynamicArray_destroy_integer(DynamicArray* array);

int DynamicList_destroy_float(DynamicArray* float_list);

int DynamicArray_destroy_string(DynamicArray* array);

#endif