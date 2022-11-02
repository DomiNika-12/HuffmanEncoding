//
// Created by Dominika Bobik on 11/2/22.
//
#include <iostream>
#include <fstream>

using namespace std;

#ifndef HUFFMANENCODING_FILEREADER_H
#define HUFFMANENCODING_FILEREADER_H

class FileReader {
public:
    struct NODE {
            char c;
            int iFrequency;
    };
    FileReader();
    void WriteFile(char* pcFileName);
    int ReadFile(char *pcFileName, struct NODE **nppFrequencyArray, int* piCharCount);
};


#endif //HUFFMANENCODING_FILEREADER_H
