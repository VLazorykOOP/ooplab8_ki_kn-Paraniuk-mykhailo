#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

// Загальний шаблон функції для будь-якого типу T
template <typename T>
void remove_min(std::vector<T>& vec) {
    if (vec.empty()) return;

    // Знаходимо мінімальне значення в масиві
    T min_val = *std::min_element(vec.begin(), vec.end());

    // Вилучаємо всі мінімальні значення з масиву
    vec.erase(std::remove(vec.begin(), vec.end(), min_val), vec.end());
}

// Спеціалізація шаблону для типу char*
template <>
void remove_min(std::vector<char*>& vec) {
    if (vec.empty()) return;

    // Знаходимо мінімальне значення (за лексикографічним порядком)
    char* min_val = vec[0];
    for (char* str : vec) {
        if (strcmp(str, min_val) < 0) {
            min_val = str;
        }
    }

    // Вилучаємо всі мінімальні значення з масиву
    vec.erase(std::remove_if(vec.begin(), vec.end(), [&](char* str) {
        return strcmp(str, min_val) == 0;
        }), vec.end());
}

// Тестова функція
int main() {

    setlocale(LC_CTYPE, "uk_UA");
    std::vector<int> int_vec = { 3, 1, 2, 1, 4, 1 };
    remove_min(int_vec);
    for (int val : int_vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Ініціалізація вектора для char*
    char a[] = "банан";
    char b[] = "яблуко";
    char c[] = "виноград";
    std::vector<char*> char_vec = { a, b, a, c };
    remove_min(char_vec);
    for (char* str : char_vec) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}