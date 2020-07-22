#pragma once


#include <stdio.h>
#include <time.h>
#include <pmmintrin.h>
#include <process.h>
#include <chrono>
#include <iostream>
#include <immintrin.h>

//MVM initialization 
#define N_IF 512
__declspec(align(64)) static float array1[N_IF], array2[N_IF], testt[N_IF]; //use static as they must be visible only in this file

void if_cond_init();
unsigned short int if_cond_default();
unsigned short int if_cond_SSE();
unsigned short int if_cond_AVX();
unsigned short int Compare_if_cond();


extern unsigned short int equal(float const a, float const b); //used extern as this is defined in MVM.h

#define EPSILON 0.01


