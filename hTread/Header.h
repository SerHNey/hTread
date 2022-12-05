#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <Windows.h>
typedef struct Tm
{
    int tm_sec;     // секунды после минут [0,59]
    int tm_min;     // минуты после часов [0,59]
    int tm_hour;    // часы после полуночи [0,23]
}tm;
