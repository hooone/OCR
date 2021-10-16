
#include <iostream>
#include <vector>
#include <memory>

#include <include/utility.h>
#include <include/paddle/paddle_inference_api.h>

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

            LoadModel(model_dir);
        };

        // Load Paddle inference model
        void LoadModel(const std::string &model_dir);

    private:
        int cpu_math_library_num_threads_ = 4;
        std::string precision_ = "fp32";
        std::vector<std::string> label_list_;

    private:
        std::shared_ptr<paddle_infer::Predictor> predictor_;
    };
}