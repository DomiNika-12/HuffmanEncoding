#include <iostream>
#include <queue>
#include "FileReader.h"
#include "Encoder.h"
#include "Node.h"

int main() {
    FileReader* Reader = nullptr;
    Node* npFrequencyArray = nullptr;
    Node* pRoot = nullptr;
    Encoder* pEncoder = nullptr;
    std::vector<Node> vector{};
    std::priority_queue<Node, std::vector<Node>, CompareNodes> queue;
    int iCharCount = 0;
    int i = 0;

    Reader = new FileReader("test.txt", "out.txt");
    //Eerie eyes seen near lake.
    Reader->ReadFile(&iCharCount, &vector);

//    while (i != iCharCount)
//    {
//        printf("Char: %c Frequency: %d\n", vector.at(i).c, vector.at(i).iFrequency);
//        i++;
//    }



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

    Reader->WriteFile(&e);

    return 0;
}
