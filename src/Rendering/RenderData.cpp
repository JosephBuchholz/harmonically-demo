#include "RenderData.h"

void RenderData::AddLine(const Line& line)
{
    m_lines.push_back(line);
}

void RenderData::AddText(const Text& text)
{
    m_texts.push_back(text);
}