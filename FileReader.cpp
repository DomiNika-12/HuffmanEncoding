//
// Created by Dominika Bobik on 11/2/22.
//

#include "FileReader.h"



FileReader::FileReader() {

}

int FileReader::ReadFile(char *pcFileName, struct NODE** nppFrequencyArray, int* piCharCount) {
    int iError = 0;
    char c = '0';
    int iCharCounter = 0;
    int iInitialFileSize = 0;
    int iArrayIndex = 0;
    bool bFound = false;

    FILE* ptr = fopen(pcFileName, "r");

    // check stream status
    if (ptr == nullptr)
    {
        cerr << "Can't open input file!";
        iError = errno;
        return iError;
    }

    iInitialFileSize = 10 * sizeof(NODE);
    *nppFrequencyArray = (struct NODE*)malloc(iInitialFileSize);
    memset(*nppFrequencyArray, 0, iInitialFileSize);
    while (true){
        c = fgetc(ptr);
        if (c == EOF)
        {
            break;
        }
        if (iCharCounter >= iInitialFileSize)
        {
            iInitialFileSize = iInitialFileSize * 2;
            *nppFrequencyArray = (struct NODE*) realloc(*nppFrequencyArray, iInitialFileSize);
        }
        while (true)
        {
            if (iArrayIndex >= iCharCounter)
            {
                break;
            }
            if (((*nppFrequencyArray) + iArrayIndex)->c == c)
            {
                ((*nppFrequencyArray) + iArrayIndex)->iFrequency++;
                bFound = true;
                break;
            }
            iArrayIndex++;
        }
        if (!bFound)
        {
            ((*nppFrequencyArray) + iCharCounter)->c = c;
            ((*nppFrequencyArray) + iCharCounter)->iFrequency = 1;
            iCharCounter++;
        }
        iArrayIndex = 0;
        bFound = false;
    }

    *piCharCount = iCharCounter;
    return iError;
}


