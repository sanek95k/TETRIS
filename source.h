#ifndef SOURCE_H
#define SOURCE_H

#include "block.h"
#include <iostream>
#include <string.h>

const short L=20, M=14;
const std::string blockIcon="\356\202\252", borderIcon="\342\226\222";

void construct(char ***&);
void clear(char ***&, Block *);
void draw(char ***&);
void destruct(char ***&);
bool game(char ***&);
void line(char ***&);



#endif
