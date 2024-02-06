#pragma once
#include <cstdio> 

char* getString(int* len) {
    bool flag = true;
    *len = 0;                               // изначально строка пуста
    int capacity = 1;                       // ёмкость контейнера динамической строки (1, так как точно будет '\0')
    //char* s = (char*)malloc(sizeof(char));  // динамическая пустая строка

    char* s = new char[1];
    char* sPtr = s;
m1:
    char c = getchar(); // символ для чтения данных
    if ((*len == 0) && (flag)) {
        flag = false;
        goto m1;
    }

    // читаем символы, пока не получим символ переноса строки (\n)
    while (c != '\n') {
        s[(*len)++] = c; // заносим в строку новый символ

        // если реальный размер больше размера контейнера, то увеличим его размер
        if (*len >= capacity) {
            char* tmp = new char[*len];
            char* tmpPtr = tmp;
            for (int i = 0; i < *len; i++) {
                *tmpPtr = *sPtr;
                sPtr++;
                tmpPtr++;
            }
            delete s;
            capacity *= 2;          // увеличиваем ёмкость строки в два раза
            s = new char[capacity]; // создаём новую строку с увеличенной ёмкостью  
            sPtr = s;
            tmpPtr = tmp;
            for (int i = 0; i < capacity; i++) {
                *sPtr = *tmpPtr;
                tmpPtr++;
                sPtr++;
            }
            delete tmp;
            sPtr = s;
        }
        c = getchar(); // считываем следующий символ          
    }

    s[*len] = '\0'; // завершаем строку символом конца строки

    return s; // возвращаем указатель на считанную строку
}