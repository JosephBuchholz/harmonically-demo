#include "BoundingBox.h"

#include "../Debugging/Debug.h"

BoundingBox::BoundingBox()
{

}

bool BoundingBox::DoesOverlapWith(const BoundingBox& boundingBox) const
{
    return (this->position.x < boundingBox.position.x + boundingBox.size.x &&
            this->position.x + this->size.x > boundingBox.position.x &&
            this->position.y < boundingBox.position.y + boundingBox.size.y &&
            this->position.y + this->size.y > boundingBox.position.y);
}

bool BoundingBox::DoesOverlapWithPoint(Vec2<float> point) const
{
    return (point.x > this->position.x &&
            point.x < this->position.x + this->size.x &&
            point.y > this->position.y &&
            point.y < this->position.y + this->size.y);
}

bool BoundingBox::DoBoundingBoxesOverlap(const BoundingBox& boundingBox1, const BoundingBox& boundingBox2)
{
    return boundingBox1.DoesOverlapWith(boundingBox2);
}

BoundingBox BoundingBox::CombineBoundingBoxes(const BoundingBox& boundingBox1, const BoundingBox& boundingBox2)
{
    BoundingBox newBoundingBox;

    float left = std::min(boundingBox1.position.x, boundingBox2.position.x);
    float top = std::min(boundingBox1.position.y, boundingBox2.position.y);

    float right = std::max(boundingBox1.position.x + boundingBox1.size.x, boundingBox2.position.x + boundingBox2.size.x);
    float bottom = std::max(boundingBox1.position.y + boundingBox1.size.y, boundingBox2.position.y + boundingBox2.size.y);

    newBoundingBox.position.x = left;
    newBoundingBox.position.y = top;

    newBoundingBox.size.x = right - left;
    newBoundingBox.size.y = bottom - top;

    return newBoundingBox;
}

BoundingBox BoundingBox::AddPadding(float padding)
{
    position.x -= padding;
    position.y -= padding;
    size.x += padding * 2.0f;
    size.y += padding * 2.0f;

    return *this;
}

void BoundingBox::MakeDimensionsPositive()
{
    if (size.x < 0.0f)
    {
        size.x = -size.x; // make positive
        position.x -= size.x; // adjust position
    }

    // same as x
    if (size.y < 0.0f)
    {
        size.y = -size.y;
        position.y -= size.y;
    }
}