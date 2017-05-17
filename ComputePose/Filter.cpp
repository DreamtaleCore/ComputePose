#include "Filter.h"
#include <algorithm>
using namespace std;


IFilter::IFilter()
{
}


IFilter::~IFilter()
{
}

bool IFilter::process(Vector3f & result)
{
    bool ret = process();
    result = _result;
    return ret;
}

bool IFilter::process()
{
    return false;
}

void IFilter::addData(Vector3f data)
{
    _dataList.push_back(data);
}

void IFilter::setWindowSize(int windowSize)
{
    _windowSize = windowSize;
}

int IFilter::getWindowSize()
{
    return _windowSize;
}

Vector3f IFilter::getResult()
{
    return _result;
}

bool AverageFilter::process()
{
    if (_dataList.size() < _windowSize)
        return false;
    
    Vector3f sum(0, 0, 0);
    for (auto elem : _dataList)
    {
        sum += elem;
    }
    sum = sum / (float)_dataList.size();
    _dataList.erase(_dataList.begin(), _dataList.begin() + 1);

    _result = sum;
    return true;
}

bool MedianFilter::process()
{
    if (_dataList.size() < _windowSize)
        return false;

    vector<Vector3f> tmp = _dataList;
    sort(tmp.begin(), tmp.end(), [&](Vector3f a, Vector3f b) {return a.norm() < b.norm(); });
    _result = tmp[_windowSize / 2];

    _dataList.erase(_dataList.begin(), _dataList.begin() + 1);

    return true;
}
