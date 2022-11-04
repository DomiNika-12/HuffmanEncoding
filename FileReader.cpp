//
// Created by Dominika Bobik on 11/2/22.
//

#include "FileReader.h"

FileReader::FileReader(char* pcInputFileName, char* pcOutputFileName) {
    iFileContentsBufferSize = 10;
    pcFileContentsBuffer = (char*)malloc(iFileContentsBufferSize*sizeof(char));
    iCharCount = 0;
    this->pcInputFileName = pcInputFileName;
    this->pcOutputFileName = pcOutputFileName;
}

int FileReader::ReadFile(int* piDistinctCharCount, vector<Node>* pVector) {
    int iError = 0;
    char c = '0';
    int iDistinctCharCounter = 0;
    int iArrayIndex = 0;
    bool bFound = false;

    FILE* ptr = fopen(pcInputFileName, "r");
    if (ptr == nullptr)
    {
        cerr << "Can't open input file!";
        iError = errno;
        return iError;
    }

    while (true){
        c = (char)fgetc(ptr);
        if (c == EOF)
        {
            break;
        }
        if (iCharCount >= iFileContentsBufferSize)
        {
            iFileContentsBufferSize = iFileContentsBufferSize * 2;
            pcFileContentsBuffer = (char*)realloc(pcFileContentsBuffer, iFileContentsBufferSize);
        }
        pcFileContentsBuffer[iCharCount] = c;
        iCharCount++;
        while (true)
        {
            if (iArrayIndex >= iDistinctCharCounter)
            {
                break;
            }
            if((*pVector).at(iArrayIndex).c == c)
            {
                (*pVector).at(iArrayIndex).iFrequency++;
                bFound = true;
                break;
            }
            iArrayIndex++;
        }
        if (!bFound)
        {
            auto* node = new Node();
            node->iFrequency = 1;
            node->c = c;
            (*pVector).push_back(*node);
            iDistinctCharCounter++;
        }
        iArrayIndex = 0;
        bFound = false;
    }

    *piDistinctCharCount = iDistinctCharCounter;
    fclose(ptr);
    return iError;
}

int FileReader::WriteFile(vector<CharEncoding> *pEncodings) {
    int iError = 0;
    FILE* ptr = nullptr;
    char c = '\0';

    ptr = fopen(pcOutputFileName, "w");
    if (ptr == nullptr)
    {
        cerr << "Can't create file!";
        iError = errno;
        return iError;
    }

    for (int i = 0; i < iCharCount; i++)
    {
        c = pcFileContentsBuffer[i];
        int j = 0;
        while(1)
        {
            if (c == '\0')
            {
                fprintf(ptr, "%c", c);
                break;
            }
            if (pEncodings->at(j).c == c)
            {
                for (int k = 0; k < pEncodings->at(j).iArraySize; k++)
                {
                    fprintf(ptr, "%d", pEncodings->at(j).array[k]);
                }
                break;
            }
            j++;
        }
    }

    return iError;
}


