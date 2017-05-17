#pragma once
#include <Eigen/Geometry>
#include <iostream>
#include <vector>

using namespace std;
using namespace Eigen;

class IFilter
{
public:
    IFilter();
    ~IFilter();

    bool process(Vector3f& result);
    virtual bool process();
    void addData(Vector3f data);

    void setWindowSize(int windowSize);
    int getWindowSize();
    Vector3f getResult();

protected:
    int                 _windowSize;
    vector<Vector3f>    _dataList;
    Vector3f            _result;
};

class AverageFilter : public IFilter
{
public:
    bool process();
};

class MedianFilter : public IFilter
{
public:
    bool process();
};
