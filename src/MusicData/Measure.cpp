#include "Measure.h"

#include <algorithm>
#include <iostream>

void Measure::Render(RenderData& renderData, Vec2<float> parentPosition) const
{
    Vec2<float> currentPosition = parentPosition + position;

    // Add left barline
    renderData.AddLine(Line(currentPosition, { currentPosition.x, currentPosition.y + renderData.displayConstants.measureBarlineHeight }, Paint()));

    // Add right barline
    renderData.AddLine(Line({ currentPosition.x + width, currentPosition.y }, { currentPosition.x + width, currentPosition.y + renderData.displayConstants.measureBarlineHeight }, Paint()));

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
            return a->beatPosition < b->beatPosition;
        });

    std::sort(m_Lyrics.begin(), m_Lyrics.end(), [](std::shared_ptr<Lyric> a, std::shared_ptr<Lyric> b)
        {
            return a->beatPosition < b->beatPosition;
        });

    // Calculate the position of child chords
    Vec2<float> position = { barlineMargin, chordPosY };
    for (const auto& chord : m_Chords)
    {
        Vec2<float> dimensions = chord->GetBoundingBox().size;
        chord->SetPosition(position);

        position.x += dimensions.x + (chord->duration * beatWidth);
    }

    // Calculate the position of child lyrics (moving the position of chords when nessesary)
    Vec2<float> prevPos = { 0.0f, lyricPosY };
    for (const auto& lyric : m_Lyrics)
    {
        Vec2<float> dimensions = lyric->lyricText.GetBoundingBox(Paint()).size;

        float chordPositionX = GetPositionXFromBeatPositionOfChords(lyric->beatPosition);

        Vec2<float> lyricPosition = prevPos;

        if (lyricPosition.x > chordPositionX)
        {
            // change chord position x
            std::shared_ptr<Chord> chord = GetChordFromBeatPosition(lyric->beatPosition);

            if (chord != nullptr)
                chord->position.x = lyricPosition.x;
        }
        else if (lyricPosition.x < chordPositionX)
        {
            lyricPosition.x = chordPositionX;
        }

        lyric->position = lyricPosition;

        std::cout << "x: " << lyric->position.x << "y: " << lyric->position.y << std::endl;

        prevPos = { lyricPosition.x + std::max(dimensions.x + lyricSpace, (lyric->duration * beatWidth)), lyricPosY };
    }

    // Set the width of this measure to the last lyrics or chord's position + its size
    // So that the measure is big enough to contain all the child lyrics and chords.
    float lastChordPositionX = 0.0f;
    float lastLyricPositionX = 0.0f;

    if (!m_Chords.empty())
    {
        std::shared_ptr<Chord> lastChord = m_Chords.back();
        lastChordPositionX = lastChord->GetBoundingBox().size.x + lastChord->position.x + lastChord->duration * beatWidth;
    }

    if (!m_Lyrics.empty())
    {
        std::shared_ptr<Lyric> lastLyric = m_Lyrics.back();
        lastLyricPositionX = lastLyric->lyricText.GetBoundingBox(Paint()).size.x + lastLyric->position.x;
    }

    width = std::max(std::max(lastChordPositionX, lastLyricPositionX), minMeasureWidth);
}

float Measure::GetPositionXFromBeatPositionOfChords(float beatPosition) const
{
    for (const auto& chord : m_Chords)
    {
        if (beatPosition == chord->beatPosition) // found
        {
            return chord->position.x;
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
        /*if (beatPosition >= previousChordBeatPosition && beatPosition <= chord->beatPosition) // found
        {
            return chord;
        }

        previousChordBeatPosition = chord->beatPosition;*/

        if (beatPosition == chord->beatPosition)
        {
            return chord;
        }

        // else beatPos < chord.beatPos: continue
    }

    return nullptr;
}