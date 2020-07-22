#pragma once


#include <stdio.h>
#include <time.h>
#include <pmmintrin.h>
#include <process.h>
#include <chrono>
#include <iostream>
#include <immintrin.h>

//MVM initialization 
#define M 64
__declspec(align(64)) static float  X1[M], X2[M], Y1[M], test2[M]; //use static as they must be visible only in MVM.cpp file

void initialization_Add();

unsigned short int Add_default();
unsigned short int Add_SSE();
unsigned short int Add_AVX();
unsigned short int Compare_Add();
extern unsigned short int equal(float const a, float const b); //used extern as this is defined in MVM.h

#define EPSILON 0.01


