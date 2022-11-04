#include <iostream>
#include <queue>
#include "FileReader.h"
#include "Encoder.h"
#include "Node.h"
#include "Decoder.h"

int main() {
    FileReader* Reader = nullptr;
    Node* npFrequencyArray = nullptr;
    Node* pRoot = nullptr;
    Encoder* pEncoder = nullptr;
    Decoder* pDecoder = nullptr;
    std::vector<Node> vector{};
    std::priority_queue<Node, std::vector<Node>, CompareNodes> queue;
    int iCharCount = 0;
    int i = 0;

    Reader = new FileReader("test.txt", "out.txt");
    //Eerie eyes seen near lake.
    Reader->ReadFile(&iCharCount, &vector);

    pEncoder = new Encoder(iCharCount);
    pRoot = new Node();

    pEncoder->Sort(&vector);
    i = 0;
    while (i != iCharCount)
    {
        printf("Char: %c Frequency: %d\n", vector.at(i).c, vector.at(i).iFrequency);
        i++;
    }

    pEncoder->GeneratePQ(&vector, &queue);
    pEncoder->GenerateTree(&queue, pRoot);

    int array[200];
    int top = 0;
    pEncoder->GenerateEncoding(pRoot, array, top);

    std::vector<CharEncoding> e = pEncoder->GetEncodings();
    printf("Printing from main:\n");
    for (int j = 0;j <iCharCount; j++ )
    {
        cout << e.at(j).c << " ";
        for (int k = 0; k < e.at(j).iArraySize; k++) {
            cout << e.at(j).array[k];
        }
        cout << endl;
    }

    char* b = "110001001010101011010011101110111101001011000111001100011010100111001101110000001011011011000010011110100111110111111000010111011011100111010110011010111011001000111100";
    int o = 0;
    Reader->WriteFile(&e);
    pDecoder = new Decoder(pRoot);
    pDecoder->Decode(pRoot, b, o, strlen(b));


    return 0;
}
