#include "Header.h"

tm* numbe() {
    const time_t timer = time(NULL);
    tm* u = localtime(&timer);
    printf("Введите время в формате - ЧЧ;ММ;CC\n");
    char* stroka = calloc(30, sizeof(char));
    scanf_s("%s", stroka);
    char* number;
    number = strtok(stroka, ":");
    int numbers[3];
    numbers[0] = atof(number);
    int  i = 1;
    while (number != NULL)
    {
        number = strtok(NULL, ":");
        if (number != NULL) {
            if (number[0] != '\r') {
                numbers[i] = atoi(number);
                i++;
            }
        }
        if (i > 3)
            break;
    }
    u->tm_hour = numbers[0];
    u->tm_min = numbers[1];
    u->tm_sec = numbers[2];
    return u;
}


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
        printf("Секундомер запущен: ");
        printf("%s\n", s);
    }
}

void* timers(tm* u) {

    if(u->tm_sec == 0)
        u->tm_sec += 1;
    while (1)
    {
        u->tm_sec -= 1;
        if (u->tm_sec == 0) {
            u->tm_sec = 59;
            u->tm_min -= 1;
            if (u->tm_min == 0) {
                u->tm_min = 59;
                u->tm_hour -= 1;
            }
        }
        char s[20] = { 0 };
        for (int i = 0; i < 20; i++) s[i] = 0;
        int length = strftime(s, 20, "%H:%M:%S", u);
        Sleep(1000);
        system("cls");
        printf("Таймер запущен: ");
        printf("%s\n", s);
    }
}

void* settime(tm* u)
{
    char s[20];
    while (1)
    {
        u->tm_sec += 1;
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
        printf("Время запущено: ");
        printf("%s\n", s);
    }
}

int main()
{
    system("chcp 1251 >null");
    DWORD choose = -1;
    Sleep(100);
    HANDLE hTread[4];
    printf("Выберите действие над часами\n1 - Запуск времени \n2 - настройка времени \n3 - секундомер\n4 - таймер\n");
    printf("0 - Остановить\n");

    char* f;
    const time_t timer = time(NULL);
    tm* u= localtime(&timer);

    while (1)
    {
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1:
            system("cls");   
            u = localtime(&timer);
            hTread[0] = CreateThread(NULL, 0, settime,u, NULL, NULL);
        break;
        case 2:
            u = numbe();
            hTread[1] = CreateThread(NULL, 0, settime, u, NULL, NULL);
        break;
        case 3:
            hTread[2] = CreateThread(NULL, 0, secondsmer, 0, NULL, NULL);
        break;
        case 4:
            u = numbe();
            hTread[3] = CreateThread(NULL, 0, timers, u, NULL, NULL); 
        break;
        default:
            for (size_t i = 0; i < 4; i++)
            {
                SuspendThread(hTread[i]);
                system("cls");
                printf_s("Выполнена завершение потока\n");
                printf("Выберите действие над часами\n1 - Запуск времени \n2 - настройка времени \n3 - секундомер\n4 - таймер\n");
                printf("0 - Остановить\n");
            }
        break;
        }       
    }
    
}

