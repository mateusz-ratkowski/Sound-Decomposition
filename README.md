# Sound Decomposition

This is a project that processes audio data, collects it using a sound input device, and performs a frequency decomposition of the captured sound. The frequency range selected is based on standard guitar tuning frequencies.

## Project Structure

- **`record.h`**: Contains functions to record audio data from a sound input device.
- **`main.cpp`**: Main program that records audio, performs frequency decomposition using Discrete Fourier Transform (DFT), and visualizes the results.
- **`C++-Imaginary-numbers-library`**: A library that provides a class `Imaginary` for representing and performing operations on complex numbers (with real and imaginary parts). It is used in the project for DFT operations.

## Frequency Range

The selected frequency range (70 Hz - 340 Hz) corresponds to the frequencies of the strings on a standard guitar.

## Dependencies

- **Windows MM API**: Used for audio input. Specifically, it uses `waveIn` for recording sound data.
- **C++-Imaginary-numbers-library**: This library provides a class `Imaginary` for representing and performing operations on complex numbers (with real and imaginary parts). 

  You can download the library here: [C++-Imaginary-numbers-library](https://github.com/mateusz-ratkowski/cpp-Imaginary-numbers-library.git).

## C++-Imaginary-numbers-library

This C++ library provides a class `Imaginary` for representing and performing operations on complex numbers (with real and imaginary parts). The library includes basic arithmetic operations, comparisons, and additional functionalities like modulus, conjugate, and norm.

## Compilation

To compile the project, use the following command:

```bash
g++ -o sound_decomposition main.cpp ./libs/Imaginary/Imaginary.cpp -lwinmm
```

## Usage

1. **`Run the program`**: Execute the compiled sound_decomposition executable.
2. **`Recording`**: The program will start recording audio from the input device (your microphone or sound input).
3. **`Frequency Decomposition`**: It will then perform a frequency decomposition of the captured sound using the Discrete Fourier Transform (DFT) on the frequency range of 70 Hz - 340 Hz (based on standard guitar tuning).
4. **`Visualization`**: A simple text-based graph will be displayed in the terminal, showing the strength of the detected frequencies. The graph's X-axis represents the strength of the frequency components, and the Y-axis corresponds to the frequency values.
5. **`Closing`**: Close program by Ctrl^C.

## Future development

This project is a work in progress and will be further developed to enhance its capabilities and features.

## License

This project is released under the MIT License. Feel free to use, modify, and distribute it as needed.
