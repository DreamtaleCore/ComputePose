#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

class DataReader
{
public:
    DataReader();
    ~DataReader();

    void read(string path);

    vector<Vector3f> mags;
    vector<Vector3f> gyrs;
    vector<Vector3f> accs;
    vector<Vector3f> lins;

    int counter;
};

