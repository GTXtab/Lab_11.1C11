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
    FILE* file = fopen(filename, "r"); // Відкриття файлу для читання
    if (file == NULL) {
        fprintf(stderr, "Не вдалося відкрити файл: %s\n", filename);
        return 0;
    }

    int totalCount = 0;
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) { // Зчитування рядка з файлу
        totalCount += countCommaDash(line); // Підрахунок груп у рядку
    }

    fclose(file); // Закриття файлу
    return totalCount;
}

int main() {
    SetConsoleCP(1251);         // Підтримка кирилиці у введенні
    SetConsoleOutputCP(1251);  // Підтримка кирилиці у виведенні

    const char* filename = "t.txt";

    int result = countCommaDashInFile(filename);
    if (result > 0) {
        printf("Знайдено %d груп ', -'.\n", result);
    }
    else {
        printf("Груп ', -' у файлі не знайдено.\n");
    }

    return 0;
}
