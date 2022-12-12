#pragma once

#include <stdio.h>
#include <time.h>
#include <pmmintrin.h>
#include <process.h>
#include <chrono>
#include <iostream>
#include <immintrin.h>

//MVM initialization 
#define M3 1024


void initialization_MVM();

unsigned short int MVM_default();
unsigned short int MVM_SSE();
unsigned short int MVM_SSE_without_fmadd();
unsigned short int MVM_AVX();
unsigned short int MVM_AVX_without_fmadd();
unsigned short int Compare_MVM();
extern unsigned short int equal(float const a, float const b);

#define EPSILON 0.0001


