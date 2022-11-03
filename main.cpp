#include <iostream>
#include <queue>
#include "FileReader.h"
#include "Encoder.h"

int main() {
    FileReader* Reader = nullptr;
    Node* npFrequencyArray = nullptr;
    Node* pRoot = nullptr;
    Encoder* pEncoder = nullptr;
    std::vector<Node> vector{};
    std::priority_queue<Node> queue{};
    int iCharCount = 0;
    int i = 0;

    Reader = new FileReader("test.txt", "out.txt");
    //Eerie eyes seen near lake.
    Reader->ReadFile(&iCharCount, &vector);

    while (i != iCharCount)
    {
        printf("Char: %c Frequency: %d\n", vector.at(i).c, vector.at(i).iFrequency);
        i++;
    }

    i = 0;
    while (i != iCharCount)
    {
        printf("Char: %c Frequency: %d\n", vector.at(i).c, vector.at(i).iFrequency);
        i++;
    }

    pEncoder = new Encoder(iCharCount);
    pRoot = new Node();

    pEncoder->Sort(&vector);
    pEncoder->GeneratePQ(&vector, &queue);
    pEncoder->GenerateTree(&queue, pRoot);

    int array[200];
    int top = 0;
    pEncoder->GenerateEncoding(pRoot, array, top);

    return 0;
}
