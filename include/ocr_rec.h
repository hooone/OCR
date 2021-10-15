
#include <iostream>
#include <vector>

#include <include/utility.h>

namespace PaddleOCR
{

    class CRNNRecognizer
    {
    public:
        explicit CRNNRecognizer(const std::string &model_dir, const std::string &label_path)
        {
            this->label_list_ = Utility::ReadDict(label_path);
            this->label_list_.insert(this->label_list_.begin(),
                                     "#"); // blank char for ctc
            this->label_list_.push_back(" ");
            for (std::vector<std::string>::const_iterator iter = label_list_.cbegin(); iter != label_list_.cend(); iter++)
            {
                std::cout << (*iter) << std::endl;
            }
        };

    private:
        int cpu_math_library_num_threads_ = 4;
        std::string precision_ = "fp32";
        std::vector<std::string> label_list_;
    };
}