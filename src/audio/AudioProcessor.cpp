#include "AudioProcessor.h"
#include <iostream>
#include <random>

AudioProcessor::AudioProcessor() {
    std::cout << "[AudioProcessor] Initialized with 48kHz sample rate" << std::endl;
}

void AudioProcessor::setSettings(const AudioSettings& settings) {
    std::cout << "[AudioProcessor] Applied settings:" << std::endl;
    std::cout << "  Pitch Shift: " << settings.pitchShift << " semitones" << std::endl;
    std::cout << "  Formant Shift: " << settings.formantShift << std::endl;
    std::cout << "  Reverb Level: " << settings.reverbLevel << std::endl;
    std::cout << "  Noise Reduction: " << settings.noiseReduction << std::endl;
    std::cout << "  Preset: " << settings.preset << std::endl;
}

void AudioProcessor::processBuffer(float* input, float* output, int bufferSize) {
    // In real version: apply actual audio processing
    // Here: just copy input to output with slight modification
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-0.01, 0.01);
    
    for (int i = 0; i < bufferSize; ++i) {
        output[i] = input[i] + static_cast<float>(dis(gen));
    }
}

void AudioProcessor::loadPreset(const std::string& presetName) {
    AudioSettings settings;
    settings.preset = presetName;
    
    if (presetName == "Male to Female") {
        settings.pitchShift = 5.0;
        settings.formantShift = 0.3;
        settings.reverbLevel = 0.2;
        settings.noiseReduction = 0.5;
    } else if (presetName == "Female to Male") {
        settings.pitchShift = -4.0;
        settings.formantShift = -0.2;
        settings.reverbLevel = 0.1;
        settings.noiseReduction = 0.4;
    } else if (presetName == "Robot") {
        settings.pitchShift = 0.0;
        settings.formantShift = 0.8;
        settings.reverbLevel = 0.3;
        settings.noiseReduction = 0.2;
    } else if (presetName == "Radio Host") {
        settings.pitchShift = 2.0;
        settings.formantShift = 0.1;
        settings.reverbLevel = 0.15;
        settings.noiseReduction = 0.6;
    } else if (presetName == "Whisper") {
        settings.pitchShift = -2.0;
        settings.formantShift = -0.1;
        settings.reverbLevel = 0.4;
        settings.noiseReduction = 0.8;
    }
    
    setSettings(settings);
}

std::vector<std::string> AudioProcessor::getAvailablePresets() {
    return {
        "Male to Female",
        "Female to Male", 
        "Robot",
        "Radio Host",
        "Whisper"
    };
}
