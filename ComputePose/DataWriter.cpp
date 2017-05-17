#include "DataWriter.h"



DataWriter::DataWriter()
{
}


DataWriter::~DataWriter()
{
    if (_file.is_open())
    {
        _file.close();
    }
}

void DataWriter::init(string filename)
{
    _file.open(filename, ios::in);
    if (_file.is_open())
    {
        _file.clear();
    }
    _file.open(filename, ios::out);
}

void DataWriter::writeLine(string line)
{
    _file << line << endl;
}
