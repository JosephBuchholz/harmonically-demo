#include "Measure.h"

#include <algorithm>

void Measure::Render(RenderData& renderData, Vec2<float> parentPosition) const
{
    Vec2<float> currentPosition = parentPosition + position;
    currentPosition.x += pickupWidth;

    renderData.AddLine(Line(currentPosition, { currentPosition.x, currentPosition.y + renderData.displayConstants.measureBarlineHeight }, Paint()));
    renderData.AddLine(Line({ currentPosition.x + width, currentPosition.y }, { currentPosition.x + width, currentPosition.y + renderData.displayConstants.measureBarlineHeight }, Paint()));

    for (const auto& chord : m_Chords)
    {
        chord->Render(renderData, currentPosition);
    }

    /*if (isFirstMeasureOfSystem && !m_Lyrics.empty())
    {
        std::shared_ptr<LyricalPhrase> lyricalPhrase = lyrics[0]->parentLyricalPhrase;

        if (lyricalPhrase)
        {
            for (const auto& lyric : lyricalPhrase->lyrics)
            {
                if (lyric->isPickupToNextMeasure)
                {
                    lyric->Render(renderData, settings, currentPosition);
                }
                else
                    break;
            }
        }
    }*/

    /*if (lyricPickup)
    {
        for (const auto& lyric : lyricPickup->lyrics)
        {
            lyric->Render(renderData, settings, currentPosition, true);
        }
    }*/

    for (const auto& lyric : m_Lyrics)
    {
        if (!lyric->isPickupToNextMeasure)
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

/*
    boundingBox = BoundingBox();
    boundingBox.size.x = width;
    boundingBox.size.y = lyricPosY + (settings.displayConstants.lyricFontSize.size / 2.0f); // only an estimation
    */

    std::sort(m_Chords.begin(), m_Chords.end(), [](std::shared_ptr<Chord> a, std::shared_ptr<Chord> b)
        {
            return a->beatPosition < b->beatPosition;
        });

    std::sort(m_Lyrics.begin(), m_Lyrics.end(), [](std::shared_ptr<Lyric> a, std::shared_ptr<Lyric> b)
        {
            return a->beatPosition < b->beatPosition;
        });
    
    std::shared_ptr<Lyric> previousLyric = nullptr;
    bool pickupStarted = false;
    std::shared_ptr<LyricPickup> currentLyricPickup = nullptr;
    for (const auto& lyric : m_Lyrics)
    {
        if (previousLyric != nullptr)
        {
            previousLyric->duration = lyric->beatPosition - previousLyric->beatPosition;
        }

        
        if (lyric->startsPickup || pickupStarted)
        {
            pickupStarted = true;
            lyric->isPickupToNextMeasure = true;

            if (currentLyricPickup == nullptr)
            {
                currentLyricPickup = std::make_shared<LyricPickup>();
            }

            currentLyricPickup->lyrics.push_back(lyric);
            lyric->parentLyricPickup = currentLyricPickup;
        }
        else
        {
            lyric->parentLyricPickup = nullptr;
            lyric->isPickupToNextMeasure = false;
        }
        
        previousLyric = lyric;
    }

    // set this measure's pickup (by using the previous measure)
    /*if (parent)
    {
        if (parent->elementType == BaseElement::ElementType::CSStaff)
        {
            std::shared_ptr<CSStaff> staff = std::dynamic_pointer_cast<CSStaff>(parent);

            int i = 0;
            for (const auto& m : staff->measures)
            {
                if (m.get() == this)
                {
                    break;
                }

                i++;
            }

            if (i > 0)
            {
                if (!staff->measures[i - 1]->m_Lyrics.empty())
                {
                    lyricPickup = staff->measures[i - 1]->m_Lyrics.back()->parentLyricPickup;
                }
            }
        }       
    }*/

    if (lyricPickup)
        pickupWidth = -lyricPickup->lyrics[0]->pickupPosition.x;
    else
        pickupWidth = 0.0f;

    if (previousLyric != nullptr)
        previousLyric->duration = duration - previousLyric->beatPosition;

    float defaultWidth = width;
    Vec2<float> previousPosition = { barlineMargin, chordPosY };
    for (const auto& chord : m_Chords)
    {
        Vec2<float> dimensions = chord->GetBoundingBox().size;
        Vec2<float> position = previousPosition;
        chord->Init(position);

        previousPosition = position;
        previousPosition.x += dimensions.x + chord->duration * beatWidth;
    }


    Vec2<float> prevPos = { 0.0f, lyricPosY };
    for (const auto& lyric : m_Lyrics)
    {
        if (lyric->isPickupToNextMeasure && lyric->parentLyricPickup && !displayReminderPickupLyrics)
        {
            lyric->Init({ 0.0f, 0.0f });
            continue;
        }

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

        lyric->Init(lyricPosition);

        prevPos = { lyricPosition.x + std::max(dimensions.x + lyricSpace, (lyric->duration * beatWidth)), lyricPosY };
    }


    prevPos = { 0.0f, lyricPosY };
    if (!m_Lyrics.empty())
    {
        if (m_Lyrics.back()->parentLyricPickup)
        {
            for (int i = m_Lyrics.back()->parentLyricPickup->lyrics.size() - 1; i >= 0; i--)
            {
                std::shared_ptr<Lyric> lyric = m_Lyrics.back()->parentLyricPickup->lyrics[i];
                Vec2<float> dimensions = lyric->lyricText.GetBoundingBox(Paint()).size;

                lyric->pickupPosition = { prevPos.x - (dimensions.x + lyricSpace), prevPos.y };

                prevPos = lyric->pickupPosition;
            }
        }
    }

    float chordPosX = 0.0f;
    float lyricPosX = 0.0f;

    if (!m_Chords.empty())
        chordPosX = m_Chords.back()->GetBoundingBox().size.x + m_Chords.back()->position.x + m_Chords.back()->duration * 30.0f;

    for (int i = m_Lyrics.size() - 1; i >= 0; i--)
    {
        if (!m_Lyrics[i]->parentLyricPickup)
        {
            lyricPosX = m_Lyrics[i]->lyricText.GetBoundingBox(Paint()).size.x + m_Lyrics[i]->position.x;
            break;
        }
    }
    //if (!lyrics.empty())
    //    lyricPosX = lyrics.back()->lyricText.GetDimensions(Paint()).x + lyrics.back()->position.x;

    width = std::max(std::max(chordPosX, lyricPosX), minMeasureWidth);
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