#pragma once

#include "Paint.h"
#include "../Utils/Vec2.h"

/**
 * An object that holds data needed to render a line.
 */
struct Line
{
    Line() {}
    Line(Vec2<float> start, Vec2<float> end, Paint paint = Paint())
        : start(start), end(end), paint(paint) {}

    Vec2<float> start = { 0.0f, 0.0f };
    Vec2<float> end = { 0.0f, 0.0f };
    Paint paint = Paint();
};