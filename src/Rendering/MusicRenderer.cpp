#include "MusicRenderer.h"

#include "Renderer.h"

MusicRenderer::MusicRenderer()
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

void MusicRenderer::Render()
{
    Renderer& renderer = Renderer::GetInstance();

    renderer.DrawText("Hello World", { 50.0f, 50.0f });
    renderer.DrawLine({ 0.0f, 0.0f }, { 200.0f, 100.0f });
}