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
    int tm_sec;     // ������� ����� ����� [0,59]
    int tm_min;     // ������ ����� ����� [0,59]
    int tm_hour;    // ���� ����� �������� [0,23]
}tm;
