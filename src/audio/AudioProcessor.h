#pragma once
#include <string>
#include <vector>

class AudioProcessor {
public:
    struct AudioSettings {
        double pitchShift;
        double formantShift;
        double reverbLevel;
        double noiseReduction;
        std::string preset;
    };
    
    AudioProcessor();
    void setSettings(const AudioSettings& settings);
    void processBuffer(float* input, float* output, int bufferSize);
    void loadPreset(const std::string& presetName);
    std::vector<std::string> getAvailablePresets();
};
