#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <gflags/gflags.h>

#include <include/ocr_rec.h>

using namespace std;
using namespace cv;

DEFINE_string(image_path, "C:/Users/hooone/Pictures/mhd/vsop.jpg", "Path of input image.");
DEFINE_string(rec_model_dir, "./model/", "Path of char model.");
DEFINE_string(char_list_file, "./model/en_dict.txt", "Path of char dict.");

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
    PaddleOCR::CRNNRecognizer rec(FLAGS_rec_model_dir, FLAGS_char_list_file);
    return 0;
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