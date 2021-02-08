#include "Comparator.h"
#include <fstream>
#include <iostream>

using namespace std;

Comparator::Comparator()
{
    tSimpleProfiler = TSimpleProfiler();
}

vector<string> Comparator::compareArr(vector<string> array_1, vector<string> array_2, int size_1, int size_2) // сравниваем два входных массива и создаем третий - результирующий
{
    tSimpleProfiler.BeginMeasure(); // определяем время начала работы алгоритма
    int size = 0; // указываем нулевую размерность результирующего массива, чтобы увеличивать её по мере необходимости
    vector <string> arrayRes(size);

    int k = 0;

    bool flag = true; // для проверки на повторную запись элемента в результирующий массив (если true - элемент еще не записан)

    for (int i = 0; i < size_1; i++) {
        for (int j = 0; j < size_2; j++) {
            if (array_1[i] == array_2[j]) {
                flag = true;
                for (int m = 0; m < arrayRes.size(); m++) {
                    if (arrayRes[m] == array_1[i]) { // если элемент уже записан в результирующий массив
                        flag = false;
                        break;
                    }
                }
                if (flag == true) { // если элемент ещё НЕ записан в результирующий массив
                    size++;
                    arrayRes.resize(size); // увеличиваем размерность результипующего массива для записи нового элемента
                    arrayRes[k] = array_1[i];
                    k++;
                }
            }
        }
    }
    tSimpleProfiler.EndMeasure();  // определяем время завершения работы алгоритма
    return arrayRes;
}

void Comparator::ArrayShow(vector<string> arrayRes) // вывод результирующего массива на экран (в консоль)
{
    cout << endl;
    cout << "Результирующий массив: ";
    for (int i = 0; i < arrayRes.size(); i++) {
        cout << arrayRes[i] << " "; // вывод элемента массива на экран          
    }
    cout << endl;
}

void Comparator::ArrayWriteToFile(vector<string> arrayRes) // запись результирующего массива в файл
{
    ofstream fileOut("ResultNIITP.txt"); // создаём объект класса ofstream для записи и связываем его с файлом ResultNIITP.txt, куда будет выводится результирующий массив
    if (!fileOut)
    {
        cout << "Файл ResultNIITP.txt не может быть открыт для записи\n"; // выводим сообщение об ошибке, возникшей при открытии файла
    }

    fileOut << "Результирующий массив: ";

    for (int i = 0; i < arrayRes.size(); i++) {
        fileOut << arrayRes[i] << " "; // запись элемента массива в файл
    }
    fileOut.close();
    cout << "Запись в файл ResultNIITP.txt была осуществлена.\n";
}
