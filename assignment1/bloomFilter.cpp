
#include <iostream>
#include <string>
#include <fstream>
#include "bloom.h"

int main(int argc, char **argv)
{
    std::string dictionary = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile3 = argv[3];
    std::string outputFile5 = argv[4];

    std::ifstream myfile(dictionary);
    std::ifstream input(inputFile);
    std::ofstream output3(outputFile3);
    std::ofstream output5(outputFile5);


    std::string line = "yolo";
    Bloom bloomFilter(5000000);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            bloomFilter.add(line);
            bloomFilter.add2(line);
        }
    }

    else
        std::cout << "Unable to open file";
    
    if (input.is_open())
    {
        while (getline(input, line))
        {
            if(bloomFilter.check(line, false)) {
                std::cout << line << ": " << "Maybe!" << std::endl;
                output5 << "maybe\n";
            }
            else {
                std::cout << line << ": " << "No!" << std::endl;
                output5 << "no\n";
            }
            if(bloomFilter.check2(line, false)) {
                std::cout << line << ": " << "Maybe!" << std::endl;
                output3 << "maybe\n";
            }
            else {
                std::cout << line << ": " << "No!" << std::endl;
                output3 << "no\n";
            }
        }
    }

    else
        std::cout << "Unable to open file";

    myfile.close();

    return 0;
}