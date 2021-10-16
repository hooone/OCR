
#include <memory>

#include <include/paddle/paddle_inference_api.h>

namespace paddle_infer
{
    Predictor::Predictor(const Config &config)
    {
        // TODO:
        // The second parameter indicates that the discard log is not printed
        // predictor_ = paddle::CreatePaddlePredictor<
        //     Config>(config);
    }

    std::shared_ptr<Predictor> CreatePredictor(const Config &config)
    { // NOLINT
        std::shared_ptr<Predictor> predictor(new Predictor(config));
        return predictor;
    }
}