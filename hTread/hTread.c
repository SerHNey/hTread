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
    int tm_mday;    // день месяца [1,31]
    int tm_mon;     // месяц года (январь = 0) [0,11]
    int tm_year;    // год (1900 год = 0)
    int tm_wday;    // день недели (вс = 0) [0,6]
    int tm_yday;    // день года (1 января = 0) [0,365]
    int tm_isdst;   // флаг перехода на летнее время (>0- вкл.)
}tm;

void* secondsmer() {
    tm* u;
    const time_t timer = NULL;
    u = localtime(&timer);
    char s[20] = { 0 };
    u->tm_hour = 0;
    
    while (1)
    {
        u->tm_sec+=1;
        if (u->tm_sec == 60) {
            u->tm_sec = 0;
            u->tm_min += 1;
            if (u->tm_min == 60) {
                u->tm_min = 0;
                u->tm_hour += 1;
            }
        }
        for (int i = 0; i < 20; i++) s[i] = 0;
        int length = strftime(s, 20, "%H:%M:%S", u);
        Sleep(1000);
        system("cls");
        printf("Секундомер\n");
        printf("%s\n", s);
    }
}
void* timers() {
    tm* u;
    const time_t timer = NULL;
    u = localtime(&timer);
    char s[20] = { 0 };

    while (1)
    {
        if(u->tm_hour != 0)


        for (int i = 0; i < 20; i++) s[i] = 0;
        int length = strftime(s, 20, "%H:%M:%S", u);
        Sleep(100);
        system("cls");
        printf("АСТАНИВИТЕСЬ\n");
        printf("%s\n", s);
    }
}
char* add(tm* u1)
{
    char s2[20] = { 0 };
    u1->tm_hour += 1;
    time_t next = mktime(u1);
    u1 = localtime(&next);
    strftime(s2, 20, "%H:%M:%S ", u1);
    printf("%s\n", s2);
    getchar();
    return (s2);
}

char* settime(tm* u)
{
    char s[20];
    char* tmp;
    for (int i = 0; i < 20; i++) s[i] = 0;
    int length = strftime(s, 20, "%H:%M:%S", u);
    tmp = (char*)malloc(sizeof(s));
    strcpy(tmp, s);
    return(tmp);
}

int main()
{
    system("chcp 1251 >null");


    //secondsmer();

    
    //tm* u;
    //char* f;
    //system("cls");
    //const time_t timer = NULL;
    //u = localtime(&timer);
    //f = settime(u);
    //puts(f);

    //return 0;

    //time_t time(time_t * t);
    //char choose = " ";
    //time_t now = time(NULL);
    //char* string_now = ctime(&now);
    //printf("%s\n", &now);
    DWORD choose = -1;
    Sleep(100);
    HANDLE hTread[4];
    tm timeE;
    timeE.tm_sec = time(NULL);
    printf("%ld\n", timeE.tm_sec);
    printf("Выберите действие над часами\n1 - пауза \n2 - настройка времени \n3 - секундомер\n4 - таймер\n5 - Запуск времени\n");
    printf("0 - Остановить\n");
    while (1)
    {
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1:
            
        break;
        case 2:

        break;
        case 3:
            hTread[0] = CreateThread(NULL, 0, secondsmer, 0, NULL, NULL);
        break;
        case 4:

        break;
        case 5:

        break;
        default:
            for (size_t i = 0; i < 4; i++)
            {
                TerminateThread(hTread[i], 1);
                SuspendThread(hTread[i]);
                system("cls");
                printf_s("Выполнена остановка\n");
                printf("Выберите действие над часами\n1 - пауза \n2 - настройка времени \n3 - секундомер\n4 - таймер\n5 - Запуск времени\n");
            }
        break;
        }       
    }
    
}


//int now_t() {
//    time_t now = time(NULL);
//    tm timeE;
//    timeE.tm_sec = time(NULL);
//}

