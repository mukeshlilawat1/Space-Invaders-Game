#pragma once
#include <raylib.h>

class Alien {
    public:
          Alien(int type, Vector2 position);
          void update();
          void Draw();
          int GetType();
          static void UnloadImage();
          static Texture2D alienImage[3];
          int type;
          Vector2 position;
          
    private:
};