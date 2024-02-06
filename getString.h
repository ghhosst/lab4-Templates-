#pragma once
#include <cstdio> 

char* getString(int* len) {
    bool flag = true;
    *len = 0;                               // ���������� ������ �����
    int capacity = 1;                       // ������� ���������� ������������ ������ (1, ��� ��� ����� ����� '\0')
    //char* s = (char*)malloc(sizeof(char));  // ������������ ������ ������

    char* s = new char[1];
    char* sPtr = s;
m1:
    char c = getchar(); // ������ ��� ������ ������
    if ((*len == 0) && (flag)) {
        flag = false;
        goto m1;
    }

    // ������ �������, ���� �� ������� ������ �������� ������ (\n)
    while (c != '\n') {
        s[(*len)++] = c; // ������� � ������ ����� ������

        // ���� �������� ������ ������ ������� ����������, �� �������� ��� ������
        if (*len >= capacity) {
            char* tmp = new char[*len];
            char* tmpPtr = tmp;
            for (int i = 0; i < *len; i++) {
                *tmpPtr = *sPtr;
                sPtr++;
                tmpPtr++;
            }
            delete s;
            capacity *= 2;          // ����������� ������� ������ � ��� ����
            s = new char[capacity]; // ������ ����� ������ � ����������� ��������  
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
        c = getchar(); // ��������� ��������� ������          
    }

    s[*len] = '\0'; // ��������� ������ �������� ����� ������

    return s; // ���������� ��������� �� ��������� ������
}