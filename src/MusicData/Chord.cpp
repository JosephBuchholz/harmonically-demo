#include "Chord.h"

Chord::Chord()
    : chordSymbol("Gm")
{
}

void Chord::Render(RenderData& renderData, Vec2<float> measurePosition) const
{
    chordSymbol.Render(renderData, measurePosition + position);
}

void Chord::Init(Vec2<float> pos)
{
    position = pos;

    /*chordSymbol.justify = Justify::Left;

    noteHead->sizeFactor = 0.8f;

    if (noteStem)
    {
        noteStem->stemStartY = 0.0f;
        noteStem->stemEndY = -15.0f;
        noteStem->stemPositionX = noteHead->GetNoteHeadWidth(settings.displayConstants) - (1.25f / 2.0f);
    }

    if (noteHead->noteDuration == NoteValue::Eighth || noteHead->noteDuration == NoteValue::Sixteenth)
    {
        noteFlag = std::make_unique<NoteFlag>();
        
        noteFlag->noteDuration = noteHead->noteDuration;
        noteFlag->type = NoteFlag::Type::Up;
        noteFlag->size = 0.6f;
    }

    if (augDot)
    {
        float x = noteHead->GetNoteHeadWidth(settings.displayConstants);

        if (noteFlag)
            x += 6.0f;

        augDot->CalculatePositionAsPaged(settings.displayConstants, false, false, x);
    }*/
}

BoundingBox Chord::GetBoundingBox() const
{
    //BoundingBox bb = chordSymbol.GetBoundingBoxRelativeToParent();
    BoundingBox bb;
    bb.position += position;
    return bb;
}