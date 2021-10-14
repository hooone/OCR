#include <iostream>
#include <gflags/gflags.h>

using namespace std;

DEFINE_string(image_dir, "", "Dir of input image.");
int main(int argc, char **argv)
{
    std::cout << "hello world!" << endl;

    // 解析输入的参数
    google::ParseCommandLineFlags(&argc, &argv, true);
    std::cout << "image_dir:"
              << FLAGS_image_dir << endl;
}