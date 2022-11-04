//
// Created by Dominika Bobik on 11/4/22.
//

#ifndef HUFFMANENCODING_TYPES_H
#define HUFFMANENCODING_TYPES_H

#include "Node.h"

struct CharEncoding {
    char c;
    int array[200];
    int iArraySize;
};

struct CompareNodes {
    bool operator()(Node const& n1, Node const& n2)
    {
        return n1.iFrequency >= n2.iFrequency;
    }
};

#endif //HUFFMANENCODING_TYPES_H
