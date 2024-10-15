#include "MusicManager.h"

#include "Renderer.h"

void MusicManager::Render()
{
    Renderer& renderer = Renderer::GetInstance();
    RenderData renderData = RenderData();

    m_Song->Render(renderData);

    // render
    renderer.SetScale(1.0f);
    renderer.SetOffset(renderData.offset);

    for (const RenderableLine& line : renderData.m_Lines)
    {
        renderer.DrawLine(line.start, line.end, line.paint);
    }

    for (const RenderableText& text : renderData.m_Texts)
    {
        renderer.DrawText(text.text, text.position, text.paint);
    }
}