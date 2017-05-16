#include "DataReader.h"


DataReader::DataReader()
{
    mags.clear();
    gyrs.clear();
    accs.clear();
    lins.clear();
}

DataReader::~DataReader()
{
    mags.clear();
    gyrs.clear();
    accs.clear();
    lins.clear();
}

void DataReader::read(string path)
{
    fstream in;
    in.open(path, ios::in);
    if (in.is_open())
    {
        char headedr[512];
        // Eat the first line because it is data header
        in.getline(headedr, 512);
        while (!in.eof())
        {
            char line_buf[512];
            in.getline(line_buf, 512);
            string line(line_buf);
            // replace ',' with ' '
            for (auto &elem : line)
            {
                if (elem == ',')
                {
                    elem = ' ';
                }
            }

            Vector3f mag, gyr, acc, lin;
            stringstream ss(line);
            ss >> mag.x() >> mag.y() >> mag.z();
            ss >> gyr.x() >> gyr.y() >> gyr.z();
            ss >> acc.x() >> acc.y() >> acc.z();
            ss >> lin.x() >> lin.y() >> lin.z();

            mags.push_back(mag);
            gyrs.push_back(gyr);
            accs.push_back(acc);
            lins.push_back(lin);
        }

        in.close();
    }
    else
    {
        cout << "The file in " << path << " is not exist." << endl;
    }
}
