#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
std::vector<T> mergeArrays(const T* arr1, size_t size1, const T* arr2, size_t size2) {
    std::vector<T> mergedArr;

    // Додаємо елементи з першого масиву
    for (size_t i = 0; i < size1; ++i) {
        if (std::find(mergedArr.begin(), mergedArr.end(), arr1[i]) == mergedArr.end()) {
            mergedArr.push_back(arr1[i]);
        }
    }

    // Додаємо елементи з другого масиву
    for (size_t i = 0; i < size2; ++i) {
        if (std::find(mergedArr.begin(), mergedArr.end(), arr2[i]) == mergedArr.end()) {
            mergedArr.push_back(arr2[i]);
        }
    }

    return mergedArr;
}

int main() {

    setlocale(LC_CTYPE, "uk_UA");
    // Приклад використання для масивів типу int
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 4, 5, 6, 7, 8 };

    auto mergedIntArr = mergeArrays(arr1, sizeof(arr1) / sizeof(arr1[0]), arr2, sizeof(arr2) / sizeof(arr2[0]));
    std::cout << "Об'єднаний масив (int): ";
    for (const auto& element : mergedIntArr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Приклад використання для масивів типу char*
    const char* arr3[] = { "яблуко", "банан", "вишня" };
    const char* arr4[] = { "банан", "апельсин", "манго" };

    auto mergedCharPtrArr = mergeArrays(arr3, sizeof(arr3) / sizeof(arr3[0]), arr4, sizeof(arr4) / sizeof(arr4[0]));
    std::cout << "Об'єднаний масив (char*): ";
    for (const auto& element : mergedCharPtrArr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}