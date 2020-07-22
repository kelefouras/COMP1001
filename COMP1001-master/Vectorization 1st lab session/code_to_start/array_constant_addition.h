#pragma once


#include <stdio.h>
#include <time.h>
#include <pmmintrin.h>
#include <process.h>
#include <chrono>
#include <iostream>
#include <immintrin.h>

//MVM initialization 
#define M 10000000
__declspec(align(64)) static float  V1[M], V2[M], test3[M]; //use static as they must be visible only in MVM.cpp file

void initialization_ConstAdd();

unsigned short int ConstAdd_default();
unsigned short int ConstAdd_SSE();
unsigned short int ConstAdd_AVX();
unsigned short int Compare_ConstAdd();
extern unsigned short int equal(float const a, float const b); //used extern as this is defined in MVM.h

#define EPSILON 0.01


