#include "collision.h"
bool Collision::CollideAABB(SDL_Rect pRectA, SDL_Rect pRectB)
{
    if (pRectA.x < pRectB.x + pRectB.w && pRectA.x + pRectA.w > pRectB.x && pRectA.y < pRectB.y + pRectB.h && pRectA.y + pRectA.h > pRectB.y)
    {
        return true;
    }

    return false;
}