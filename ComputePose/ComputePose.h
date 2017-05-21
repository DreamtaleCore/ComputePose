#pragma once
#include "DataReader.h"
#include "DataWriter.h"
#include "Filter.h"
#include <opencv2/opencv.hpp>

using namespace cv;

class ComputePose
{
public:
    ComputePose();
    ~ComputePose();

    void init(string in, string out);
    void run();
    void setComplementaryRate(float rate);

private:
    DataReader  _dataReader;
    DataWriter  _dataWriter;
    string      _filepathIn;
    string      _filepathOut;
    float       _complementaryRate;
};

