#include "RenderData.h"

void RenderData::AddLine(const RenderableLine& line)
{
    m_Lines.push_back(line);
}

void RenderData::AddText(const RenderableText& text)
{
    m_Texts.push_back(text);
}