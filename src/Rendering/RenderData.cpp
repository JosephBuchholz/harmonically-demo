#include "RenderData.h"

void RenderData::AddLine(const Line& line)
{
    m_lines.push_back(line);
}

void RenderData::AddText(const Text& text)
{
    m_texts.push_back(text);
}

void RenderData::AddDebugDot(Vec2<float> position)
{
    Line line = Line();

    line.start = position;
    line.end = position + Vec2<float>{ 10.f, 10.0f };

    line.paint = Paint(0xFFFF00FF);
    line.paint.strokeWidth = 10.0f;

    m_lines.push_back(line);
}