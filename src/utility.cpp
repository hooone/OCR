
#include <include/utility.h>
#include <ostream>
#include <iostream>
#include <fstream>

namespace PaddleOCR
{
    // File.ReadLines
    // 读取文件，按行返回读取结果
    std::vector<std::string> Utility::ReadDict(const std::string &path)
    {
        std::ifstream in(path);
        std::string line;
        std::vector<std::string> m_vec;
        if (in)
        {
            while (getline(in, line))
            {
                m_vec.push_back(line);
            }
        }
        else
        {
            std::cout << "no such label file: " << path << ", exit the program..."
                      << std::endl;
            exit(1);
        }
        return m_vec;
    }
}