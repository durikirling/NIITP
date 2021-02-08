#pragma once

#include <vector>
#include <string>
#include "TSimpleProfiler.h"

using namespace std;

class Comparator
{
public:
	TSimpleProfiler tSimpleProfiler;
	Comparator();
	vector<string> compareArr(vector <string> array_1, vector <string> array_2, int size_1, int size_2);
	void ArrayShow(vector <string> arrayRes);
	void ArrayWriteToFile(vector <string> arrayRes);
};