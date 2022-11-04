//
// Created by Dominika Bobik on 11/4/22.
//

#include <cstdio>
#include "Decoder.h"


Decoder::Decoder(Node* pnRoot) {
    this->pnRoot = pnRoot;
}

void Decoder::Decode(Node *npRoot, char* cpEncodedBuffer, int i, int iEncodedBufferSize)
{
    if (i >= iEncodedBufferSize) return;
    int val = cpEncodedBuffer[i];
    if ((val - 48) == 1 && npRoot->rightNode)
    {
        Decode(npRoot->rightNode, cpEncodedBuffer, i + 1, iEncodedBufferSize);
    }

    if ((val - 48) == 0 && npRoot->leftNode)
    {
        Decode(npRoot->leftNode, cpEncodedBuffer, i + 1, iEncodedBufferSize);
    }

    if (!npRoot->leftNode && !npRoot->rightNode)
    {
        printf("%c", npRoot->c);
        Decode(pnRoot, cpEncodedBuffer, i, iEncodedBufferSize);
    }
}

