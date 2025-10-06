#pragma once
#include<raylib.h>

class Block {
    public:
      Block(Vector2 postition);
      void Draw();
    private:
      Vector2 position;
};