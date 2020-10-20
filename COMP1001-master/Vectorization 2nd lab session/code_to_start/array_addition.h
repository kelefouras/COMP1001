#pragma once


#include <stdio.h>
#include <time.h>
#include <pmmintrin.h>
#include <process.h>
#include <chrono>
#include <iostream>
#include <immintrin.h>

//initialization 
#define M2 64
static float  X1[M2], X2[M2], Y1[M2], test2[M2]; //use static as they must be visible only in array_addition.cpp file

void initialization_Add();

unsigned short int Add_default();
unsigned short int Add_SSE();
unsigned short int Add_AVX();
unsigned short int Compare_Add();
extern unsigned short int equal(float a, float b); //used extern as this is defined in array_constant_addition.h

#define EPSILON 0.01


