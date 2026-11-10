/* To run the file:
 * 1.) g++ CSci114_P1.cpp
 * 2.) ./a.out
 * 3.) mv data.out out.pdf or any pdf file name.
 * 4.) open pdf file in pdf viewer of choice.
 * No AI was used in the making of this program.
 * I used some of the sample code that was given along with the documentation.
 * */
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
  ifstream inputFile; // uses data.in file to read the input data.
  char buffer[4096];
  ofstream outputFile; // uses data.out file to write the output in.
  inputFile.open("data.in", ios::in | ios::binary);
  outputFile.open("data.out", ios::out | ios::binary);
  if (inputFile.is_open()) { // Opens and reads the file.
    cout << "Input file was opened successfully\n";
  } else { // Fail state if file is not found.
    throw runtime_error("File not able to be read\n");
  }
  if (outputFile.is_open()) { // Shows that the file was able to be opened.
    cout << "Output file was opened successfully.\n";
  } else if (!outputFile.is_open()) { // Fail state for when the file is not
                                      // accessible.
    throw runtime_error(
        "Output file failed to access change directory or create file.\n");
  }
  while (inputFile.read(buffer,
                        sizeof(buffer))) { // Reads the input until end of file.
    outputFile.write(buffer,
                     inputFile.gcount()); // Writes until loop terminates.
  }
  outputFile.write(buffer, inputFile.gcount()); // Catches any bits left.
  inputFile.close();
  outputFile.close();
  cout << "Program has been completed\n";
  return 0;
}
