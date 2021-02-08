// NIITP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

// ТЕСТОВОЕ ЗАДАНИЕ №4(2) "Длительность расчетов"

#include <iostream>
#include "Comparator.h"
#include "TSimpleProfiler.h"
#include <time.h> // для определения CLOCKS_PER_SEC

using namespace std;

bool InputCheck(int value) { // проверка ввода - только целые числа
    if (cin.fail())
    {
        cin.clear(); // обнуление всех битов состояния (возвращаем cin в "обычный" режим работы)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // удаление значения предыдущего ввода из входного буфера
        return false;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int size_1, size_2; // размерности входных массивов

    int firstValue, lastValue; // диапазон случайных чисел

    bool choice; // определение выбора заполнения входных массивов

    int myChoice; // выбор заполнения входных массивов

    while (true) {
        cout << "Выберите вариант заполнения входных массивов:\n"
            << "1. Вручную - можно ввести как числа, так и другие символы.\n"
            << "2. Автоматически - массивы будут заполнены случайными числами.\n\n"
            << "Выбор: ";

        cin >> myChoice;

        if (InputCheck(myChoice) && (myChoice == 1 || myChoice == 2)) {
            if (myChoice == 1)
                choice = true;
            else
                choice = false;
            cout << "---\n---\n";
            break;
        }
        cout << "Ошибка ввода, попробуйте снова. Введите 1 или 2.\n";
    }

    if (choice == false) {
        while (true) {
            cout << "Введите диапазон случайных чисел:\n"
                << "От:";
            cin >> firstValue;
            cout << "До:";
            cin >> lastValue;

            if (InputCheck(firstValue) && InputCheck(lastValue) && firstValue < lastValue) {
                lastValue = lastValue - firstValue + 1;
                cout << "---\n---\n";
                break;
            }
            cout << "Ошибка ввода, попробуйте снова. Введите числа, чтобы 'От:' было меньше 'До:'.\n";
        }
    }

    while (true) {
        cout << "Введите размерность первого массива: ";
        cin >> size_1;

        if (InputCheck(size_1) && size_1 > 15) {
            cout << "---\n---\n";
            break;
        }
        cout << "Ошибка ввода, попробуйте снова. Введите положительное число не менее 16.\n";
    }

    vector<string> array_1(size_1); // динамическое выделение памяти для первого входного массива

    if (choice == true) {
        cout << "Введите " << size_1 << " элементов: ";
        for (int i = 0; i < size_1; i++) {
            cin >> array_1[i];  // заполняем первый массив вручную
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // если было введено больше символов, чем указанная размерность массива
    }
    else {
        for (int i = 0; i < size_1; i++) {
            array_1[i] = to_string(firstValue + rand() % lastValue); // заполняем первый массив автоматически
        }
    }

   // cout << "---\n";

    while (true) {
        cout << "Введите размерность второго массива: ";
        cin >> size_2;

        if (InputCheck(size_2) && size_2 > 15) {
            cout << "---\n---\n";
            break;
        }
        cout << "Ошибка ввода, попробуйте снова. Введите положительное число не менее 16.\n";
    }

    vector<string> array_2(size_2); // динамическое выделение памяти для второго входного массива
  
    if (choice == true) {
        cout << "Введите " << size_2 << " элементов: ";
        for (int i = 0; i < size_2; i++) {
            cin >> array_2[i];  // заполняем второй массив вручную
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else {
        for (int i = 0; i < size_2; i++) {
            array_2[i] = to_string(firstValue + (rand() % lastValue)); // заполняем второй массив автоматически
        }
    }

    cout << "\n|||\n";

    Comparator comparator = Comparator();
    TSimpleProfiler tSimpleProfiler = TSimpleProfiler();

    cout <<"\nПодождите, идут вычисления...\n";

    vector <string> arrayRes = comparator.compareArr(array_1, array_2, size_1, size_2); // поиск общих элементов в двух входных массивах и запись в третий

    cout << endl;

    cout << "Входной массив №1: ";
    for (int i = 0; i < size_1; i++) {
        cout << array_1[i] << " "; // вывод элементов массива №1 на экран
    }

    cout << endl << endl;

    cout << "Входной массив №2: ";
    for (int i = 0; i < size_2; i++) {
        cout << array_2[i] << " "; // вывод элементов массива №2 на экран
    }

    cout << endl;

    if (arrayRes.size() == 0) // если массив пустой
        cout << "\nНе было найдено ни одного одинакового элемента. Выходной массив пустой.\n";
    else {
        comparator.ArrayShow(arrayRes); // вывод результирующего массива на экран
        cout << endl;
        comparator.ArrayWriteToFile(arrayRes); // запись результирующего массива в файл
        cout << endl;
        cout << "Продолжительность работы основного алгоритма: " << (double)comparator.tSimpleProfiler.Duration() / CLOCKS_PER_SEC << " секунд";
        cout << endl;
    }
}