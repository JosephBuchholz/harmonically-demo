#pragma once

#include "BaseElement.h"
#include "Types.h"
#include "../Utils/Vec2.h"
#include "../Debugging/Debug.h"
#include "../Rendering/RenderData.h"

/**
 * This class represents a element that is visible.
 */
class VisibleElement : public BaseElement
{
public:
    /**
     * Constructs a VisibleElement object.
     */
    VisibleElement() {}

    /**
     * Constructs a VisibleElement object.
     * 
     * @param position The position of this object.
     */
    VisibleElement(Vec2<float> position)
        : m_Position(position) {}
    
    /**
     * Getters and Setters for m_Position.
     */
    Vec2<float> GetPosition() const { return m_Position; }
    void SetPosition(Vec2<float> position) { this->m_Position = position; }

protected:
    // Relative to the parent element
    Vec2<float> m_Position = { 0.0f, 0.0f };
};