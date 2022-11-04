//
// Created by Dominika Bobik on 11/3/22.
//

#include "Encoder.h"

Encoder::Encoder(int iCharCount) {
    this->iCharCount = iCharCount;
}

bool Encoder::cmp(const Node a, const Node b)
{
    return a.iFrequency < b.iFrequency;
}

void Encoder::Sort(vector<Node> *pVector)
{
    sort((*pVector).begin(), (*pVector).end(), &(Encoder::cmp));
}

void Encoder::GeneratePQ(vector<Node>* pVector, std::priority_queue<Node, std::vector<Node>, CompareNodes>* pPQ) {
    for (int i = 0; i < iCharCount; i++)
    {
        (*pPQ).push( (*pVector).at(i));
    }
}

void Encoder::GenerateTree(priority_queue<Node, std::vector<Node>, CompareNodes>* pPQ, Node* pNode) {
    while ((*pPQ).size() != 1)
    {
        auto* n1 = new Node();
        auto* n2 = new Node();
        auto* node = new Node();
        *n1 = (*pPQ).top();
        (*pPQ).pop();
        *n2 = (*pPQ).top();
        (*pPQ).pop();
        node->iFrequency = n1->iFrequency + n2->iFrequency;
        node->leftNode = n1;
        node->rightNode = n2;
        (*pPQ).push(*node);
    }
    *pNode = (*pPQ).top();
}

void Encoder::GenerateEncoding (Node* npRoot, int arr[], int top) {
    if (npRoot->leftNode) {
        arr[top] = 0;
        GenerateEncoding(npRoot->leftNode, arr, top + 1);
    }

    if (npRoot->rightNode) {
        arr[top] = 1;
        GenerateEncoding(npRoot->rightNode, arr, top + 1);
    }

    if (!npRoot->leftNode && !npRoot->rightNode) {
        auto* e = (CharEncoding*) malloc(sizeof(CharEncoding));
        e->iArraySize = 0;
        e->c = npRoot->c;
        for (int i = 0; i < top; i++) {
            e->array[i] = arr[i];
            e->iArraySize++;
        }
        Encodings.push_back(*e);
    }
}

vector<CharEncoding> Encoder::GetEncodings() {
    return Encodings;
}

