/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief The implementation file of the c1m1 assignment
 *
 * This file includes all the required functions implementations in the c1m1 assignment
 *
 * @author Man Chun Liew
 * @date 10/11/2022
 *
 */



#include <stdio.h>
#include <stdint.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  // Create Struct
  stat Array;

  // Initialize the value
  Array.numArray = test;
  Array.arrayLength = SIZE;
  Array.maximum = 0x00;
  Array.minimum = 0xFF;
  Array.mean = 0x00;
  Array.median = 0x00;

  sort_array(Array.numArray, Array.arrayLength);
  print_array(Array.numArray, Array.arrayLength);
  
  Array.minimum = find_minimum(Array.numArray, Array.arrayLength);
  Array.maximum = find_maximum(Array.numArray, Array.arrayLength);
  Array.mean = find_mean(Array.numArray, Array.arrayLength);
  Array.median = find_median(Array.numArray, Array.arrayLength);

  //This part is to print out all the results.
  print_statistics(Array);
}

/* Add other Implementation File Code Here */

void print_statistics(stat Array){
  //Based on the requirements, all the output result must be in unsigned
  printf("Minimum: %u\n", Array.minimum);
  printf("Maximum: %u\n", Array.maximum);
  printf("Mean: %u\n", Array.mean);
  printf("Median: %u\n", Array.median);
}

void print_array(uint8_t *arrayPointer, uint8_t arrayLength){
  // Loop through the array and print it out

  printf("\n\n");
  printf("List of the Array: ");
  for(uint8_t i=0; i<arrayLength; i++){
    printf("%d ", arrayPointer[i]);  
  }
  printf("\n\n");
  return;
}

void sort_array(uint8_t *arrayPointer, uint8_t arrayLength){
  uint8_t i, j = 0, temp;

  // Sort Array
  for(i=0; i<arrayLength; i++){
    for(j=i+1; j<arrayLength; j++){
      if(arrayPointer[i]<arrayPointer[j]){
        temp = arrayPointer[i];
        arrayPointer[i]=arrayPointer[j];
        arrayPointer[j]=temp;
      }
    }
  }
}

uint8_t find_minimum(uint8_t *arrayPointer, uint8_t arrayLength){
  uint8_t minimum_value=0xFF;

  for (uint8_t i=0; i<arrayLength; i++){
    if (arrayPointer[i] < minimum_value){
      //will always compare to the number inside minimum_value, if location of i is smaller than previous number store inside the minimum_value than it will replace number on it.
      minimum_value = arrayPointer[i];
    }
  }

  return minimum_value;
}

uint8_t find_maximum(uint8_t *arrayPointer, uint8_t arrayLength){
  uint8_t maximum_value = 0x00; 
  uint8_t i; 

  for (i=0; i<arrayLength; i++){
    if(arrayPointer[i] > maximum_value){
      maximum_value = arrayPointer[i];
    }
  }
  
  return maximum_value;
}

uint8_t find_mean(uint8_t *arrayPointer, uint8_t arrayLength){
  uint32_t total_value=0x00, average = 0x00;

  for(uint32_t i=0; i<arrayLength; i++){
    total_value = total_value + arrayPointer[i];
  }

  average = total_value/arrayLength;

  return average;
}

uint8_t find_median(uint8_t *arrayPointer, uint8_t arrayLength){

  uint8_t median = 0x00;
  //To find the median, must sort all the number in sequence first then find the median
  sort_array(arrayPointer, arrayLength);
  
  if (arrayLength%2 == 0){
    median = (arrayPointer[(arrayLength-1)/2] + arrayPointer[arrayLength/2])/2.0;
  }else{
    median = arrayPointer[arrayLength/2];
  }

  return median;

}

