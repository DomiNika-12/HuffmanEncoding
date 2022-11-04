//
// Created by Dominika Bobik on 11/4/22.
//

#ifndef HUFFMANENCODING_DECODER_H
#define HUFFMANENCODING_DECODER_H

#include "Node.h"

class Decoder {
private:
    Node* pnRoot;
public:
    Decoder(Node* pnRoot);
    void Decode(Node *npRoot, char* cpEncodedBuffer, int i, int iEncodedBufferSize);
};

#endif //HUFFMANENCODING_DECODER_H
