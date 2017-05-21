#include "ComputePose.h"



ComputePose::ComputePose()
{
    _complementaryRate = 0.98;
}


ComputePose::~ComputePose()
{
}

void ComputePose::init(string in, string out)
{
    _filepathIn = in;
    _filepathOut = out;
}

void ComputePose::run()
{
    _dataReader.read(_filepathIn);
    _dataWriter.init(_filepathOut);

    Vector3f gyro_pose;
    Vector3f opt_flag;
    opt_flag.x() = -1;
    opt_flag.y() = -1;
    opt_flag.z() = 1;
    Vector3f rlt_pose;
    Mat rlt_matrix;
    float t = 0.01;
    for (int i = 0; i < _dataReader.counter; i++)
    {
        Vector3f H = _dataReader.accs[i];
        Vector3f M = _dataReader.mags[i];
        Vector3f E = M.cross(H);

        E.normalize();
        M.normalize();
        H.normalize();
        Vector3f N = H.cross(E);

        Vector3f pose_1;
        pose_1.x() = atan2f(E.y(), N.y());
        pose_1.y() = asinf(-H.y());
        pose_1.z() = atan2f(-H.x(), H.z());
        
        Mat rmatrix_1 = (Mat_<float>(3, 3) <<
            E.x(), E.y(), E.z(),
            N.x(), N.y(), N.z(),
            H.x(), H.y(), H.z());

        if (i == 0)
        {
            _dataWriter.writeLine("src1_x,src1_y,src1_z,src2_x,src2_y,src2_z,rlt_x,rlt_y,rlt_z");
            gyro_pose = pose_1;
            rlt_pose = pose_1;
            rlt_matrix = rmatrix_1.clone();
        }
        else
        {
            Vector3f gyr;
            gyr.x() = opt_flag.x() * _dataReader.gyrs[i].z();
            gyr.y() = opt_flag.y() * _dataReader.gyrs[i].x();
            gyr.z() = opt_flag.z() * _dataReader.gyrs[i].y();  
            gyr = gyr * t;

            gyro_pose +=  gyr;
            rlt_pose +=  gyr;
            rlt_pose = rlt_pose * _complementaryRate + (1 - _complementaryRate) * pose_1;
        }

        stringstream ss; 
        ss  << pose_1.x()    << "," << pose_1.y()    << "," << pose_1.z()    << ","
            << gyro_pose.x() << "," << gyro_pose.y() << "," << gyro_pose.z() << ","
            << rlt_pose.x()  << "," << rlt_pose.y()  << "," << rlt_pose.z();
        _dataWriter.writeLine(ss.str());
    }
}

void ComputePose::setComplementaryRate(float rate)
{
    _complementaryRate = rate;
}
