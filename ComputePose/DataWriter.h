#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class DataWriter
{
public:
    DataWriter();
    ~DataWriter();

    void init(string filename);
    void writeLine(string line);

private:
    fstream _file;
};

