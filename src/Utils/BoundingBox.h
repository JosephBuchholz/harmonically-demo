#pragma once

#include "Vec2.h"
#include "../Rendering/RenderData.h"
#include "../Utils/Converters.h"

/**
* A structure that stores bounds in the form of rectangle/box.
*/
class BoundingBox
{
public:
    BoundingBox() {}
    BoundingBox(Vec2<float> position, Vec2<float> size)
        : position(position), size(size) {}

    float GetLeft() const { return position.x; }
    float GetRight() const { return position.x + size.x; }

    float GetTop() const { return position.y; }
    float GetBottom() const { return position.y + size.y; }

    /**
     * Calculates whether the given bounding box overlaps with this one.
     *
     * @param boundingBox The bounding box to check against.
     * @return Whether they overlap.
     */
    bool DoesOverlapWith(const BoundingBox& boundingBox) const;

    /**
     * Finds whether the given point overlaps with this bounding box.
     *
     * @param point The point to test against.
     * @return Whether the point overlaps.
     */
    bool DoesOverlapWithPoint(Vec2<float> point) const;

    /**
     * Adds the given amount of padding to the outside edges.
     *
     * @param padding The amount of padding.
     */
    BoundingBox AddPadding(float padding = 1.0f);

    /**
     * Makes the dimensions of this bounding box positive while adjusting
     * the position so that the bounding box is in the same spot.
     */
    void MakeDimensionsPositive();

    /**
     * Tests whether the two given bounding boxes overlap.
     * 
     * @param boundingBox1 The first bounding box.
     * @param boundingBox2 The second bounding box.
     * @return Whether they overlap.
     */
    static bool DoBoundingBoxesOverlap(const BoundingBox& boundingBox1, const BoundingBox& boundingBox2);

    /**
     * Combines the two given bounding boxes into one.
     * 
     * @param boundingBox1 The first bounding box.
     * @param boundingBox2 The second bounding box.
     * @return The new combined bounding box.
     */
    static BoundingBox CombineBoundingBoxes(const BoundingBox& boundingBox1, const BoundingBox& boundingBox2);

public:
    bool operator==(const BoundingBox& rhs) const
    {
        return (this->position == rhs.position) && (this->size == rhs.size);
    }

public:

    // Relative to the top left hand corner.
    Vec2<float> position = { 0.0f, 0.0f };
    Vec2<float> size = { 0.0f, 0.0f };
};