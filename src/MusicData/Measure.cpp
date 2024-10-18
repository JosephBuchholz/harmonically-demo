#include "Measure.h"

#include <algorithm>

void Measure::Render(RenderData& renderData, Vec2<float> parentPosition) const
{
    Vec2<float> currentPosition = parentPosition + m_Position;

    // Add left barline
    renderData.AddLine(RenderableLine(currentPosition, { currentPosition.x, currentPosition.y + renderData.displayConstants.measureBarlineHeight }, Paint()));

    // Add right barline
    renderData.AddLine(RenderableLine({ currentPosition.x + m_Width, currentPosition.y }, { currentPosition.x + m_Width, currentPosition.y + renderData.displayConstants.measureBarlineHeight }, Paint()));

    // Render chords
    for (const auto& chord : m_Chords)
    {
        chord->Render(renderData, currentPosition);
    }

    // Render lyrics
    for (const auto& lyric : m_Lyrics)
    {
        lyric->Render(renderData, currentPosition);
    }
}

BoundingBox Measure::GetBoundingBox() const
{
    return BoundingBox(m_Position, { m_Width, 50.0f });
}

void Measure::Init(const MusicDisplayConstants& displayConstants)
{
    float barlineMargin = displayConstants.chordMarginFromBarline;
    float beatWidth = displayConstants.beatWidth;
    float chordPosY = displayConstants.chordPositionY;
    float lyricPosY = displayConstants.lyricPositionY;
    float lyricSpace = displayConstants.lyricSpaceWidth;
    float minMeasureWidth = displayConstants.minimumMeasureWidth;
    bool displayReminderPickupLyrics = displayConstants.displayReminderPickupLyrics;

    // Sort chords and lyrics by their beat position
    std::sort(m_Chords.begin(), m_Chords.end(), [](std::shared_ptr<Chord> a, std::shared_ptr<Chord> b)
        {
            return a->GetBeatPosition() < b->GetBeatPosition();
        });

    std::sort(m_Lyrics.begin(), m_Lyrics.end(), [](std::shared_ptr<Lyric> a, std::shared_ptr<Lyric> b)
        {
            return a->GetBeatPosition() < b->GetBeatPosition();
        });

    // Calculate the position of child chords
    Vec2<float> position = { barlineMargin, chordPosY };
    for (const auto& chord : m_Chords)
    {
        Vec2<float> dimensions = chord->GetBoundingBox().size;
        chord->SetPosition(position);

        position.x += dimensions.x + (chord->GetDuration() * beatWidth);
    }

    // Calculate the position of child lyrics (moving the position of chords when nessesary)
    Vec2<float> prevPos = { 0.0f, lyricPosY };
    for (const auto& lyric : m_Lyrics)
    {
        Vec2<float> dimensions = lyric->GetBoundingBox().size;

        float chordPositionX = GetPositionXFromBeatPositionOfChords(lyric->GetBeatPosition());

        Vec2<float> lyricPosition = prevPos;

        if (lyricPosition.x > chordPositionX)
        {
            // change chord position x
            std::shared_ptr<Chord> chord = GetChordFromBeatPosition(lyric->GetBeatPosition());

            if (chord != nullptr)
                chord->SetPosition({ lyricPosition.x, chord->GetPosition().y });
        }
        else if (lyricPosition.x < chordPositionX)
        {
            lyricPosition.x = chordPositionX;
        }

        lyric->SetPosition(lyricPosition);

        prevPos = { lyricPosition.x + std::max(dimensions.x + lyricSpace, (lyric->GetDuration() * beatWidth)), lyricPosY };
    }

    // Set the width of this measure to the maximum of the last lyric's or chord's position + its size
    // So that the measure is big enough to contain all the child lyrics and chords.
    float lastChordPositionX = 0.0f;
    float lastLyricPositionX = 0.0f;

    if (!m_Chords.empty())
    {
        std::shared_ptr<Chord> lastChord = m_Chords.back();
        lastChordPositionX = lastChord->GetBoundingBox().size.x + lastChord->GetPosition().x + lastChord->GetDuration() * beatWidth;
    }

    if (!m_Lyrics.empty())
    {
        std::shared_ptr<Lyric> lastLyric = m_Lyrics.back();
        lastLyricPositionX = lastLyric->GetBoundingBox().size.x + lastLyric->GetPosition().x;
    }

    m_Width = std::max(std::max(lastChordPositionX, lastLyricPositionX), minMeasureWidth);
}

float Measure::GetPositionXFromBeatPositionOfChords(float beatPosition) const
{
    for (const auto& chord : m_Chords)
    {
        if (beatPosition == chord->GetBeatPosition()) // found
        {
            return chord->GetPosition().x;
        }

        // else beatPos < chord.beatPos: continue
    }

    return 0.0f;
}

std::shared_ptr<Chord> Measure::GetChordFromBeatPosition(float beatPosition)
{
    float previousChordBeatPosition = 0.0f;
    for (const auto& chord : m_Chords)
    {
        if (beatPosition == chord->GetBeatPosition())
        {
            return chord;
        }

        // else beatPos < chord.beatPos: continue
    }

    return nullptr;
}