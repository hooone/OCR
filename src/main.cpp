#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <gflags/gflags.h>

using namespace std;
using namespace cv;

DEFINE_string(image_path, "C:/Users/hooone/Pictures/mhd/vsop.jpg", "Path of input image.");

/// 检查是否指定了图片
void check_params()
{
    if (FLAGS_image_path.empty())
    {
        std::cout << "请指定图片路径 --image_path=" << std::endl;
        exit(1);
    }
}

int main_rec(cv::String cv_all_img_name)
{
    Mat image = imread(cv_all_img_name);
    namedWindow("img");
    imshow("img", image);
    waitKey(0);
}

int main(int argc, char **argv)
{
    system("chcp 65001");
    std::cout << "hello world!" << endl;

    // 解析输入的参数
    google::ParseCommandLineFlags(&argc, &argv, true);
    check_params();
    std::cout << "image_path:"
              << FLAGS_image_path << endl;

    // 识别图片
    cv::String cv_all_img_name(FLAGS_image_path);
    return main_rec(cv_all_img_name);
}