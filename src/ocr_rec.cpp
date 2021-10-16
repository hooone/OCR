
#include <include/ocr_rec.h>
#include <include/paddle/paddle_inference_api.h>

namespace PaddleOCR
{
    void CRNNRecognizer::LoadModel(const std::string &model_dir)
    {
        //   AnalysisConfig config;
        paddle_infer::Config config;
        config.SetModel(model_dir + "/inference.pdmodel",
                        model_dir + "/inference.pdiparams");

        this->predictor_ = CreatePredictor(config);
    }
    PD_INFER_DECL std::shared_ptr<paddle_infer::Predictor> CreatePredictor(
        const paddle_infer::Config &config); // NOLINT
}