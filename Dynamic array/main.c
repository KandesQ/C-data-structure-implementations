//
//  main.c
//
//  Dynamic array
//
//
//  Created by Fedor Kapranov, 5.10.2025
//

// TODO: rename DynamicArray to DynamicList

#include <stdlib.h>
#include <stdio.h>

#include "src/DynamicArray.h"



int main()
{
    // Constructors
    DynamicArray* integer_array = DynamicArray_init_integer();
    DynamicArray* float_array = DynamicList_init_float();
    DynamicArray* string_array = DynamicArray_init_string();


    // Add method
    DynamicArray_add_integer(integer_array, 1);
    DynamicArray_add_integer(integer_array, 242);
    DynamicArray_add_integer(integer_array, 523);
    DynamicArray_add_integer(integer_array, 753);
    DynamicArray_add_integer(integer_array, 173);

    DynamicList_add_float(float_array, 124.123);
    DynamicList_add_float(float_array, 63.1);
    DynamicList_add_float(float_array, 3.49);
    DynamicList_add_float(float_array, 52.1);
    DynamicList_add_float(float_array, 64.13);

    DynamicArray_add_string(string_array, "Ola");
    DynamicArray_add_string(string_array, "Hello");
    DynamicArray_add_string(string_array, "Guden tag");
    DynamicArray_add_string(string_array, "Privet");
    DynamicArray_add_string(string_array, "Nihao");


    // Print method
    DynamicArray_print_integer(integer_array);
    DynamicList_print_float(float_array);
    DynamicArray_print_string(string_array);


    // Pop method
    float popped_element = DynamicList_pop_float(float_array);
    printf("Popped float element: %.4f\n", popped_element);

    


    // Insert method

    // Remove method
    

    // Destroy method
    DynamicArray_destroy_integer(integer_array);
    free(integer_array);

    DynamicList_destroy_float(float_array);
    free(float_array);

    DynamicArray_destroy_string(string_array);
    free(string_array);

    return 0;
}