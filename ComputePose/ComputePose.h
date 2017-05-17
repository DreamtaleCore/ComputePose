#pragma once
#include "DataReader.h"
#include "DataWriter.h"
#include "Filter.h"

class ComputePose
{
public:
    ComputePose();
    ~ComputePose();

    void run();

private:
    DataReader _dataReader;
    DataWriter _dataWriter;
};

