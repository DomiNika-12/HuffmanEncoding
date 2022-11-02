#include <iostream>
#include "FileReader.h"

int main() {
    auto* Reader = new FileReader();
    int iCharCount = 0;
    struct FileReader::NODE* npFrequencyArray = nullptr;
    int i = 0;
    //Eerie eyes seen near lake.
    char* pcFileName = (char*) "test.txt";

    Reader->ReadFile(pcFileName, &npFrequencyArray, &iCharCount);

    while (i != iCharCount)
    {
        printf("Char: %c Frequency: %d\n", npFrequencyArray[i].c, npFrequencyArray[i].iFrequency);
        i++;
    }
    return 0;
}
