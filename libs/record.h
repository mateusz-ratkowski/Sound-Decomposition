#ifndef _RECORD_H_
#define _RECORD_H_

#include <windows.h>
#include <iostream>
#include <mmsystem.h>
#include <cstring>  // For memcpy

using namespace std;

// Global variables
HWAVEIN hWaveIn;            // Handle to the recording device
WAVEHDR waveHeader;         // Structure to store the WAVE header
short* rawData = nullptr;   // Buffer for audio data (raw data in short format)
bool isRecording = false;   // Recording flag

// Function to start and stop recording
void collectAudioData(double* buffer, int bufferSize)
{
    if (isRecording) {
        cerr << "Recording started" << endl;
        return;
    }

    // Set the recording format
    WAVEFORMATEX wfx;
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nChannels = 1;            // Mono
    wfx.nSamplesPerSec = 44100;   // 44.1 kHz
    wfx.nAvgBytesPerSec = 44100 * 2; // 16-bit mono
    wfx.nBlockAlign = 2;
    wfx.wBitsPerSample = 16;
    wfx.cbSize = 0;

    // Open the recording device
    if (waveInOpen(&hWaveIn, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_FUNCTION) != MMSYSERR_NOERROR) {
        cerr << "Failed to open wave input device!" << endl;
        return;
    }

    // Allocate a buffer for storing data
    rawData = new short[bufferSize];  // Buffer for data

    // Prepare the WAVE header
    waveHeader.lpData = (LPSTR)rawData;
    waveHeader.dwBufferLength = bufferSize * 2;  // 16-bit mono
    waveHeader.dwBytesRecorded = 0;
    waveHeader.dwUser = 0;
    waveHeader.dwFlags = 0;
    waveHeader.dwLoops = 1;

    // Prepare the WAVE header
    if (waveInPrepareHeader(hWaveIn, &waveHeader, sizeof(WAVEHDR)) != MMSYSERR_NOERROR) {
        cerr << "Failed to prepare header!" << endl;
        return;
    }

    // Add the buffer for recording
    if (waveInAddBuffer(hWaveIn, &waveHeader, sizeof(WAVEHDR)) != MMSYSERR_NOERROR) {
        cerr << "Failed to add buffer!" << endl;
        return;
    }

    // Start recording
    if (waveInStart(hWaveIn) != MMSYSERR_NOERROR) {
        cerr << "Failed to start recording!" << endl;
        return;
    }

    // Set the recording flag
    isRecording = true;
    cout << "Recording started..." << endl;
    Sleep(500);
    // Later, data will be saved to the buffer

    // Stop recording
    if (waveInStop(hWaveIn) != MMSYSERR_NOERROR) {
        cerr << "Failed to stop recording!" << endl;
    } else {
        isRecording = false;
        cout << "Recording stopped" << endl;
    }

    // Convert data to double format (divide by 100000)
    for (int i = 0; i < bufferSize; ++i) {
        buffer[i] = static_cast<double>(rawData[i]) / 100000.0;
    }

    // Free resources
    delete[] rawData;
}

// Function to check and stop recording, then close the wave input
void stopAndCloseWaveIn()
{
    if (isRecording) {
        if (waveInStop(hWaveIn) != MMSYSERR_NOERROR) {
            cerr << "Failed to stop recording!" << endl;
        } else {
            isRecording = false;
            cout << "Recording stopped" << endl;
        }
    }

    // Close the recording device
    waveInClose(hWaveIn);
}

#endif
