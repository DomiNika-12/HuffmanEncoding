//
// Created by Dominika Bobik on 11/3/22.
//

#ifndef HUFFMANENCODING_NODE_H
#define HUFFMANENCODING_NODE_H


class Node {
public:
    char c;
    int iFrequency;
    Node* leftNode;
    Node* rightNode;
    bool operator<(const Node& b) const
    {
        return iFrequency > b.iFrequency;
    }
    Node();
};


#endif //HUFFMANENCODING_NODE_H
