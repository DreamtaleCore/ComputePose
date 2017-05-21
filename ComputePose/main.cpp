#include "ComputePose.h"

namespace test
{
    void testDataRead()
    {
        DataReader dr;
        dr.read("data/simple_data.csv");

        cout << dr.counter << endl;
    }

    void generate()
    {
        ComputePose cp;
        cp.init("data/simple_data.csv", "data/simple_pose.csv");
        cp.run();
    }

    void contactImage() 
    {
        Mat src1, src2, src3;
        src1 = imread("data/img/1.png");
        src2 = imread("data/img/2.png");
        src3 = imread("data/img/3.png");

        resize(src1, src1, Size(750, 1100));
        resize(src2, src2, Size(750, 1100));
        resize(src3, src3, Size(750, 1100));

        imshow("src1", src1);
        waitKey();

        Mat tmp, dst;
        
        hconcat(src1, src2, tmp);
        hconcat(tmp, src3, dst);

        imshow("result", dst);
        waitKey();
        imwrite("data/img/result.png", dst);
    }
}

int main()
{

    // test::testDataRead();
    // test::generate();
    test::contactImage();

    cout << "Completed!" << endl;
    getchar();
    return 0;
}
