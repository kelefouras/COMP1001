#pragma once


#include <stdio.h>
#include <time.h>
#include <pmmintrin.h>
#include <process.h>
#include <chrono>
#include <iostream>
#include <immintrin.h>

//initialization 
#define M2 10000000


void initialization_Add();

unsigned short int Add_default();
unsigned short int Add_SSE();
unsigned short int Add_AVX();
unsigned short int Compare_Add();
extern unsigned short int equal(float a, float b); //used extern as this is defined in array_constant_addition.h

#define EPSILON 0.01


