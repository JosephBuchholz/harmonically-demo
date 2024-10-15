#include "MusicManager.h"

#include "Renderer.h"

#include <iostream>

MusicManager::MusicManager()
{
    LinePaint = Paint();
    LinePaint.strokeWidth = 1.4f;

    NoteStemPaint = Paint();
    NoteStemPaint.strokeWidth = 0.8333f;
    NoteStemPaint.strokeCap = Paint::Cap::Round;

    NoteBeamPaint = Paint();
    NoteBeamPaint.strokeWidth = 5.0f;
    NoteBeamPaint.strokeCap = Paint::Cap::Butt;
    NoteBeamPaint.verticalEnds = true;

    BarLinePaint = Paint();
    BarLinePaint.strokeWidth = 1.25f;
    BarLinePaint.strokeCap = Paint::Cap::Butt;

    HeavyBarLinePaint = Paint();
    HeavyBarLinePaint.strokeWidth = 5.0f;
    HeavyBarLinePaint.strokeCap = Paint::Cap::Butt;

    TabSlurPaint = Paint();
    TabSlurPaint.strokeWidth = 1.25f;

    TiePaint = Paint();
    TiePaint.strokeWidth = 1.25f;

    TextPaint = Paint();
    TextPaint.textSize = 30.0f;

    TabTextPaint = Paint();
    TabTextPaint.textSize = 16.0f;
    TabTextPaint.isTablature = true;

    InstNameTextPaint = Paint();
    InstNameTextPaint.textSize = 9.0f;
    InstNameTextPaint.align = Paint::Align::Right;
}

void MusicManager::Render()
{
    Renderer& renderer = Renderer::GetInstance();
    RenderData renderData = RenderData();

    m_Song->Render(renderData);

    // render
    renderer.SetScale(1.0f);
    renderer.SetOffset(renderData.offset);

    for (const Line& line : renderData.m_lines)
    {
        renderer.DrawLine(line.start, line.end, line.paint);
    }

    for (const Text& text : renderData.m_texts)
    {
        renderer.DrawText(text.text, text.position, text.paint);
    }
}