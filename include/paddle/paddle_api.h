
#pragma once

#include <iostream>

#include "paddle_infer_declare.h" // NOLINT

namespace paddle
{
    class PD_INFER_DECL PaddlePredictor
    {
    public:
        struct Config;
        PaddlePredictor() = default;
        PaddlePredictor(const PaddlePredictor &) = delete;
        PaddlePredictor &operator=(const PaddlePredictor &) = delete;

        /// Base class for NativeConfig and AnalysisConfig.
        struct Config
        {
            std::string model_dir; /*!< path to the model directory. */
        };
    };
}