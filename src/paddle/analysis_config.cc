#include <iostream>
#include <sstream>

#include <include/paddle/paddle_analysis_config.h>
#include <include/ocr_rec.h>

namespace paddle
{
    AnalysisConfig::AnalysisConfig(const std::string &prog_file,
                                   const std::string &params_file)
    {
        prog_file_ = prog_file;
        params_file_ = params_file;

        Update();
    }
    void AnalysisConfig::SetModel(const std::string &prog_file_path,
                                  const std::string &params_file_path)
    {
        prog_file_ = prog_file_path;
        params_file_ = params_file_path;

        Update();
    }

    std::string AnalysisConfig::SerializeInfoCache()
    {
        std::stringstream ss;
        ss << model_dir_;
        ss << prog_file_;
        ss << params_file_;

        return ss.str();
    }
    // TODO(Superjomn) refactor this, buggy.
    void AnalysisConfig::Update()
    {
        auto info = SerializeInfoCache();
        if (info == serialized_info_cache_)
            return;

        // pass_builder_.reset(new CpuPassStrategy(
        //     *static_cast<CpuPassStrategy *>(pass_builder_.get())));
    }
}