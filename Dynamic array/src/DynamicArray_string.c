//
//  DynamicArray_string.c
//
//  Dynamic array 
//
//  The realization of DynamicArray to store
//  strings
//
//
//  Created by Fedor Kapranov, 5.10.2025
//

// TODO: rename DynamicArray to DynamicList

#include <stdio.h>
#include <string.h>

#include "DynamicArray.h"

/**
 * The file for working with DynamicArray as
 * an string array
 */


#define INITIAL_CAPACITY_STRING 50 


DynamicArray* DynamicArray_init_string() {
    DynamicArray* dynamic_array = (DynamicArray*) malloc(sizeof(DynamicArray));
    if (dynamic_array == NULL) return NULL;

    dynamic_array->size = 0;
    dynamic_array->_capacity = INITIAL_CAPACITY_STRING;

    dynamic_array->data_type = STRING;
    dynamic_array->_inner_array = malloc((dynamic_array->_capacity * sizeof(char*)));
    if (dynamic_array->_inner_array == NULL) {
        free(dynamic_array);
        return NULL;
    }

    return dynamic_array;
}


static int _expand_string_inner_array(DynamicArray* string_array);

static char* _get_copy_of_str(const char* str);

int DynamicArray_add_string(DynamicArray* string_array, const char* el) {
    if (string_array->size == string_array->_capacity) {
        int expand_status = _expand_string_inner_array(string_array);
        if (expand_status != 0) return -1;
    }

    char* el_copy = _get_copy_of_str(el);

    ((char**) string_array->_inner_array)[string_array->size] = el_copy;
    string_array->size++;

    return 0;
}

// TODO: implement pop method

// TODO: implement insert method

// TODO: implement remove method

void DynamicArray_print_string(DynamicArray* array)
{
    printf("String array: ");
    printf("[");
    for (size_t i = 0; i < array->size; i++)
    {   
        char* current_str = ((char**) array->_inner_array)[i];
        for (size_t j = 0; j < strlen(current_str); j++)
        {
            printf("%c", current_str[j]);
        }
        
        if (i != array->size - 1) printf(", ");
    }
    printf("]\n");
}


int DynamicArray_destroy_string(DynamicArray* array)
{
    for (size_t i = 0; i < array->size; i++)
    {
        free(((char**) array->_inner_array)[i]);
    }
    free(array->_inner_array);
    array->_inner_array = NULL;

    return 0;
}

static char* _get_copy_of_str(const char* str) {
    size_t str_len = strlen(str);
    char* str_copy = malloc((str_len + 1) * sizeof(char));
    if (str_copy == NULL) return NULL;

    for (size_t i = 0; i < str_len + 1; i++)
    {
        str_copy[i] = str[i];
    }

    return str_copy;
}

static int _copy_string_inner_array(const char** src, size_t src_size, char** dest);

static int _expand_string_inner_array(DynamicArray* string_array) {
    int new_capacity = string_array->_capacity * 2;
    void* new_inner_array = malloc(new_capacity * sizeof(char*));
    if (new_inner_array == NULL) return -1;

    _copy_string_inner_array((char**) string_array->_inner_array, string_array->size, (char**) new_inner_array);

    // TODO: free the _inner_array after assingning and make deep copy of strings

    string_array->_capacity = new_capacity;
    string_array->_inner_array = new_inner_array;
    
    return 0;
}

static int _copy_string_inner_array(const char** src, size_t src_size, char** dest)
{
    for (size_t i = 0; i < src_size; i++)
    {
        dest[i] = _get_copy_of_str(src[i]);
    }
    
    return 0;
}