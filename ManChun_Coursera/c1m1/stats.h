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
 * @file stats.h
 * @brief Functions to provides statics on the array of the numbers
 *
 *
 * @author Man Chun Liew
 * @date 12 November 2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
typedef struct stats{
    uint8_t *numArray;
    uint8_t arrayLength;
    uint8_t median;
    uint8_t mean;
    uint8_t maximum;
    uint8_t minimum;
} stat;


void print_statistics(stat ArrayStats);
void print_array(uint8_t *arrayPointer, uint8_t arrayLength);
void sort_array(uint8_t *arrayPointer, uint8_t arrayLength);
uint8_t find_mean(uint8_t *arrayPointer, uint8_t arrayLength);
uint8_t find_minimum(uint8_t *arrayPointer, uint8_t arrayLength);
uint8_t find_maximum(uint8_t *arrayPointer, uint8_t arrayLength);
uint8_t find_median(uint8_t *arrayPointer, uint8_t arrayLength);
#endif /* __STATS_H__ */
