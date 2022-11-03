#include <iostream>
#include <queue>
#include "FileReader.h"

bool cmp(const Node a, const Node b)
{
    return a.iFrequency < b.iFrequency;
}

void getEncoding (Node* npRoot, int arr[], int top) {
    if (npRoot->leftNode) {
        printf("Left node\n");
        arr[top] = 0;
        getEncoding(npRoot->leftNode, arr, top + 1);
    }

    if (npRoot->rightNode) {
        printf("Right node\n");
        arr[top] = 1;
        getEncoding(npRoot->rightNode, arr, top + 1);
    }

    if (!npRoot->leftNode && !npRoot->rightNode) {
        cout << npRoot->c << " ";
        for (int i = 0; i < top; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
}

int main() {
    FileReader* Reader = nullptr;
    int iCharCount = 0;
    Node* npFrequencyArray = nullptr;
    std::vector<Node> vector;
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
    sort(vector.begin(), vector.end(), &cmp);
    while (i != iCharCount)
    {
        printf("Char: %c Frequency: %d\n", vector.at(i).c, vector.at(i).iFrequency);
        i++;
    }

    std::priority_queue<Node> queue{};

    i = 0;
    while (i != iCharCount)
    {
        queue.push( vector.at(i));
        i++;
    }
    while (queue.size() != 1)
    {
        auto* n1 = new Node();
        auto* n2 = new Node();
        auto* node = new Node();
        *n1 = queue.top();
        queue.pop();
        *n2 = queue.top();
        queue.pop();
        node->iFrequency = n1->iFrequency + n2->iFrequency;
        node->leftNode = n1;
        node->rightNode = n2;
        printf("New node: %d\n", node->iFrequency);
        queue.push(*node);
    }

    Node pcRoot = queue.top();
    int array[200];
    int top = 0;
    getEncoding(&pcRoot, array, top);

//    i = 0;
//    while (i != iCharCount)
//    {
//        printf("c: %c encoding: ", pEncodingArray[i].c);
//
//        for (int k = 0; k < pEncodingArray->n; k++)
//        {
//            printf("%d", pEncodingArray->encoding[k]);
//        }
//        printf("\n");
//        i++;
//    }

    return 0;
}
