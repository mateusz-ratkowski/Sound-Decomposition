# Sound Decomposition

This is a private project that processes audio data, collects it using a sound input device, and performs a frequency decomposition of the captured sound. The frequency range selected is based on standard guitar tuning frequencies.

## Project Structure

- **`record.h`**: Contains functions to record audio data from a sound input device.
- **`main.cpp`**: Main program that records audio, performs frequency decomposition using Discrete Fourier Transform (DFT), and visualizes the results.
- **`Imaginary.h` & `Imaginary.cpp`**: Defines the `Imaginary` class for complex number operations used in the DFT.

## Frequency Range

The selected frequency range (70 Hz - 340 Hz) corresponds to the frequencies of the strings on a standard guitar.

## Dependencies

- **Windows MM API**: Used for audio input. Specifically, it uses `waveIn` for recording sound data.

No external libraries are required for this project aside from the Windows MM API, which comes pre-installed on Windows systems.

## Compilation

To compile the project, use the following command:

```bash
g++ -o sound_decomposition main.cpp ./libs/Imaginary.cpp -lwinmm
