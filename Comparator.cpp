#include "Comparator.h"
#include <fstream>
#include <iostream>

using namespace std;

Comparator::Comparator()
{
    tSimpleProfiler = TSimpleProfiler();
}

vector<string> Comparator::compareArr(vector<string> array_1, vector<string> array_2, int size_1, int size_2) // ���������� ��� ������� ������� � ������� ������ - ��������������
{
    tSimpleProfiler.BeginMeasure(); // ���������� ����� ������ ������ ���������
    int size = 0; // ��������� ������� ����������� ��������������� �������, ����� ����������� � �� ���� �������������
    vector <string> arrayRes(size);

    int k = 0;

    bool flag = true; // ��� �������� �� ��������� ������ �������� � �������������� ������ (���� true - ������� ��� �� �������)

    for (int i = 0; i < size_1; i++) {
        for (int j = 0; j < size_2; j++) {
            if (array_1[i] == array_2[j]) {
                flag = true;
                for (int m = 0; m < arrayRes.size(); m++) {
                    if (arrayRes[m] == array_1[i]) { // ���� ������� ��� ������� � �������������� ������
                        flag = false;
                        break;
                    }
                }
                if (flag == true) { // ���� ������� ��� �� ������� � �������������� ������
                    size++;
                    arrayRes.resize(size); // ����������� ����������� ��������������� ������� ��� ������ ������ ��������
                    arrayRes[k] = array_1[i];
                    k++;
                }
            }
        }
    }
    tSimpleProfiler.EndMeasure();  // ���������� ����� ���������� ������ ���������
    return arrayRes;
}

void Comparator::ArrayShow(vector<string> arrayRes) // ����� ��������������� ������� �� ����� (� �������)
{
    cout << endl;
    cout << "�������������� ������: ";
    for (int i = 0; i < arrayRes.size(); i++) {
        cout << arrayRes[i] << " "; // ����� �������� ������� �� �����          
    }
    cout << endl;
}

void Comparator::ArrayWriteToFile(vector<string> arrayRes) // ������ ��������������� ������� � ����
{
    ofstream fileOut("ResultNIITP.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ ResultNIITP.txt, ���� ����� ��������� �������������� ������
    if (!fileOut)
    {
        cout << "���� ResultNIITP.txt �� ����� ���� ������ ��� ������\n"; // ������� ��������� �� ������, ��������� ��� �������� �����
    }

    fileOut << "�������������� ������: ";

    for (int i = 0; i < arrayRes.size(); i++) {
        fileOut << arrayRes[i] << " "; // ������ �������� ������� � ����
    }
    fileOut.close();
    cout << "������ � ���� ResultNIITP.txt ���� ������������.\n";
}
