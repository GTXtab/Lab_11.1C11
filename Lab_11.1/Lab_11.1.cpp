#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int countCommaDash(const char* line) {
    int count = 0;
    for (int i = 1; line[i + 1] != '\0'; i++) {
        if (line[i - 1] == ',' && line[i + 1] == '-') {
            count++;
        }
    }
    return count;
}

int countCommaDashInFile(const char* filename) {
    FILE* file = fopen(filename, "r"); // ³������� ����� ��� �������
    if (file == NULL) {
        fprintf(stderr, "�� ������� ������� ����: %s\n", filename);
        return 0;
    }

    int totalCount = 0;
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) { // ���������� ����� � �����
        totalCount += countCommaDash(line); // ϳ�������� ���� � �����
    }

    fclose(file); // �������� �����
    return totalCount;
}

int main() {
    SetConsoleCP(1251);         // ϳ������� �������� � �������
    SetConsoleOutputCP(1251);  // ϳ������� �������� � ��������

    const char* filename = "t.txt";

    int result = countCommaDashInFile(filename);
    if (result > 0) {
        printf("�������� %d ���� ', -'.\n", result);
    }
    else {
        printf("���� ', -' � ���� �� ��������.\n");
    }

    return 0;
}
