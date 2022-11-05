#include <iostream>
#include <queue>
#include "FileReader.h"
#include "Encoder.h"
#include "Node.h"
#include "Decoder.h"

void PrintFrequencies(std::vector<Node> vector, int iCharCount)
{
    int i = 0;
    printf("+------+-------------+\n");
    printf("| Char |   Frequency |\n");
    printf("+------+-------------+\n");
    while (i != iCharCount)
    {
        printf("|   %c  |      %d      |\n", vector.at(i).c, vector.at(i).iFrequency);
        i++;
    }
    printf("+------+-------------+\n");
}

void PrintEncoding(std::vector<CharEncoding> e, int iCharCount)
{
    printf("HUFFMAN ENCODING\n");
    printf("+------+-------------+\n");
    printf("| Char |   Encoding  |\n");
    printf("+------+-------------+\n");

    for (int j = 0;j <iCharCount; j++ )
    {
        printf("|   %c  | ", e.at(j).c);
        for (int k = 0; k < e.at(j).iArraySize; k++) {
            cout << e.at(j).array[k];
        }
        cout << endl;
    }

    printf("+------+-------------+\n");
}
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
    std::vector<CharEncoding> e;

    Reader = new FileReader("test.txt", "out.txt");
    //Eerie eyes seen near lake.
    Reader->ReadFile(&iCharCount, &vector);

    pEncoder = new Encoder(iCharCount);
    pRoot = new Node();

    pEncoder->Sort(&vector);
    PrintFrequencies(vector, iCharCount);

    pEncoder->GeneratePQ(&vector, &queue);
    pEncoder->GenerateTree(&queue, pRoot);

    int array[200];
    int top = 0;
    pEncoder->GenerateEncoding(pRoot, array, top);

    e = pEncoder->GetEncodings();
    PrintEncoding(e, iCharCount);

    Reader->WriteFile(&e);
    char* pcEncodedBuffer = Reader->GetEncodedBuffer();
    int iEncodedBufferSize = Reader->GetEncodedBufferSize();
    int x = 0;
    pDecoder = new Decoder(pRoot);
    pDecoder->Decode(pRoot, pcEncodedBuffer, x, iEncodedBufferSize);

    printf("\nInput file size  : %d bits\n", Reader->GetInputFileSize());
    printf("Output file size : %d bits\n", Reader->GetOutputFileSize());
    return 0;
}
