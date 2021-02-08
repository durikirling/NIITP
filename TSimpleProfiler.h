#pragma once
class TSimpleProfiler {
private:
    unsigned long int FBeginDateTime;
    unsigned long int FEndDateTime;
    unsigned long int FDuration;

public:
    TSimpleProfiler();
    void BeginMeasure();
    void EndMeasure();
    unsigned long int Duration();
};

