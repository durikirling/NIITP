#include "TSimpleProfiler.h"
#include <time.h> // для функции clock()

TSimpleProfiler::TSimpleProfiler()
{
    this->FBeginDateTime = 0;
    this->FEndDateTime = 0;
    this->FDuration = 0;
}

void TSimpleProfiler::BeginMeasure() { FBeginDateTime = clock(); }
void TSimpleProfiler::EndMeasure() { FEndDateTime = clock(); }
unsigned long int TSimpleProfiler::Duration() {
    FDuration = FEndDateTime - FBeginDateTime;
    return FDuration;
}