#pragma once


#include <stdio.h>
#include <time.h>
#include <pmmintrin.h>
#include <process.h>
#include <chrono>
#include <iostream>
#include <immintrin.h>

//MVM initialization 
#define M 1000000
#define EPSILON 0.01

void initialization();
unsigned short int default_routine();
unsigned short int SSE();
unsigned short int Compare();
unsigned short int equal(float a, float b);



