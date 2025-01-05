#include <iostream>
#include "./libs/record/record.h"
#include "./libs/Imaginary/Imaginary.h"
#include <signal.h>
#include <iomanip>
#include <cstdlib>

#define PRECISION 10

using namespace std;


const int bufferSize = 44100;  // 1 second of audio (44100 samples)
double * buffer;

void handler(int c) {
    stopAndCloseWaveIn();
    delete[] buffer;
    exit(0);
}

void drawGraph(double data[], int size) {
    system("cls");

    const int max_height = 50;

    // Variable to hold the maximum average value
    double max_value = 0.0;

    // Array to store the average values
    int num_averages = size / PRECISION;
    double averages[num_averages];

    // Calculate the average of 10 consecutive elements
    for (int i = 0; i < num_averages; ++i) {
        double sum = 0.0;
        for (int j = 0; j < PRECISION; ++j) {
            sum += data[i * PRECISION + j];  // Collect the next 10 elements
        }
        averages[i] = sum / (double)PRECISION;

        // Check if this average is greater than the current maximum value
        if (averages[i] > max_value) {
            max_value = averages[i];
        }
    }

    // Draw the graph based on the average values
    for (int i = 0; i < num_averages; ++i) {
        int height = static_cast<int>((averages[i] / max_value) * max_height);

        cout << setw(3) << (i + 7) * PRECISION << "Hz: ";
        for (int j = 0; j < height; ++j) {
            cout << "#";
        }
        cout << endl;
    }
}


int main() {
    buffer = new double[bufferSize];
    signal(SIGINT, handler);

    double DFT_resoult[270];

    // Start recording and collect data
    while (1) {
        collectAudioData(buffer, bufferSize);
        for (int i = 70; i < 340; i++) {
            Imaginary z = discreteFourierTransform((double)i, buffer, 44100);
            DFT_resoult[i-70] = z.module();
        }
        drawGraph(DFT_resoult, 270);
    }

    handler(5);
    //collectAudioData(buffer, bufferSize);

    // Processing the data in the buffer (e.g., analysis)
    for (int i = 0; i < 44100; i++) {
        cout << buffer[i] << " ";
    }

    return 0;
}

// Compilation command:
// g++ -o sound_decomposition main.cpp ./libs/Imaginary.cpp -lwinmm
