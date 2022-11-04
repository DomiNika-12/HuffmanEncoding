//
// Created by Dominika Bobik on 11/3/22.
//

#ifndef HUFFMANENCODING_ENCODER_H
#define HUFFMANENCODING_ENCODER_H


#include <vector>
#include <iostream>
#include <queue>
#include "Types.h"
#include "Node.h"
using namespace std;

class Encoder {
private:
    int iCharCount;
    vector<CharEncoding> Encodings{};
public:
    Encoder(int iCharCount);
    void Sort(vector<Node>* pVector);
    static bool cmp(const Node a, const Node b);
    void GeneratePQ(vector<Node>* pVector, std::priority_queue<Node, std::vector<Node>, CompareNodes>* pPQ);
    void GenerateTree(priority_queue<Node, std::vector<Node>, CompareNodes>* pPQ, Node* pNode);
    void GenerateEncoding(Node* pRoot, int array[], int top);
    vector<CharEncoding> GetEncodings();
};

#endif //HUFFMANENCODING_ENCODER_H
