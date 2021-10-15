
#pragma once

#include <iostream>

#include "paddle_infer_declare.h" // NOLINT

namespace paddle
{
    struct PD_INFER_DECL AnalysisConfig
    {
        AnalysisConfig() = default;
        explicit AnalysisConfig(const std::string &prog_file,
                                const std::string &params_file);
        void SetModel(const std::string &prog_file_path,
                      const std::string &params_file_path);

    protected:
        // Update the config.
        void Update();
        std::string SerializeInfoCache();
        std::string serialized_info_cache_;

    protected:
        // Model pathes.
        std::string model_dir_;
        mutable std::string prog_file_;
        mutable std::string params_file_;
    };
}