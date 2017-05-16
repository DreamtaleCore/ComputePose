#include "DataReader.h"

namespace test
{
    void testDataRead()
    {
        DataReader dr;
        dr.read("data/simple_pose.csv");

        cout << dr.counter << endl;
    }
}

int main()
{

    test::testDataRead();

    getchar();
    return 0;
}