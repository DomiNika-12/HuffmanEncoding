//
// Created by Dominika Bobik on 11/2/22.
//
#include <iostream>
#include <vector>
#include <fstream>
#include "Node.h"
#include "Types.h"

using namespace std;

#ifndef HUFFMANENCODING_FILEREADER_H
#define HUFFMANENCODING_FILEREADER_H

class FileReader {
public:
    char* pcFileContentsBuffer;
    int iFileContentsBufferSize;
    int iCharCount;
    char* pcInputFileName;
    char* pcOutputFileName;
    FileReader(char* pcInputFileName, char* pcOutputFileName);
    int ReadFile(int* piDistinctCharCount, vector<Node>* pVector);
    int WriteFile(vector<CharEncoding>* pEncodings);

};


#endif //HUFFMANENCODING_FILEREADER_H
