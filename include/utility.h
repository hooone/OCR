
#include <iostream>
#include <vector>

namespace PaddleOCR
{
    class Utility
    {
    public:
        // File.ReadLines
        // 读取文件，按行返回读取结果
        static std::vector<std::string> ReadDict(const std::string &path);
    };
} // namespace PaddleOCR