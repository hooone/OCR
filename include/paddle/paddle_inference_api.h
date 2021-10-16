#pragma once

#include "paddle_analysis_config.h" // NOLINT
#include "paddle_api.h"             // NOLINT

namespace paddle_infer
{
    using Config = paddle::AnalysisConfig;

    class PD_INFER_DECL Predictor
    {
    public:
        Predictor() = delete;
        ~Predictor() {}

        explicit Predictor(const Config &config);
    };
}