//
// Created by Dominika Bobik on 11/3/22.
//

#ifndef HUFFMANENCODING_ENCODER_H
#define HUFFMANENCODING_ENCODER_H


#include <vector>
#include "Node.h"
using namespace std;

class Encoder {
public:
    void Sort(vector<Node>* pVector);
    bool cmp(const Node a, const Node b);

};


#endif //HUFFMANENCODING_ENCODER_H
