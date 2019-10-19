//
// Created by Paulius on 2019-10-18.
//

#include "Block.h"

Block::Block(std::string &pPrevBlockHash) {
    prPrevBlockHash = pPrevBlockHash;
    prVersion = Context::GetVersion();
}

void Block::Mine() {

}
