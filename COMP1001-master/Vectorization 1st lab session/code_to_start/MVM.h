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
__declspec(align(64)) static float  X[M], Y[M], test1[M], A1[M][M]; //use static as they must be visible only in MVM.cpp file

void initialization_MVM();

unsigned short int MVM_default();
unsigned short int MVM_SSE();
unsigned short int MVM_AVX();
unsigned short int Compare_MVM();
unsigned short int equal(float const a, float const b);

#define EPSILON 0.01


