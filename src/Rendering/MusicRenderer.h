/**
 * This files contains the definition for the 'MusicRenderer' class.
 */

#pragma once

#include <memory>

#include "RenderData.h"

/**
 * This class handles all the rendering calculations.
 */
class MusicRenderer
{
public:
    MusicRenderer();

    void Render();

public:

    Paint LinePaint;
    Paint NoteStemPaint;
    Paint NoteBeamPaint;
    Paint BarLinePaint;
    Paint HeavyBarLinePaint;

    Paint TabSlurPaint;
    Paint TiePaint;

    Paint TextPaint;
    Paint TabTextPaint;
    Paint InstNameTextPaint;

    int normalColor = 0xff000000;
    int highlightedColor = 0xff1188ee;
    int playedColor = 0xff1188ee;

    bool layoutCalculated = false;

    RenderData m_RenderData = RenderData();

    std::vector<Vec2<float>> pagePositions;
    std::vector<Vec2<float>> systemPositions;

    float pageGap = 80.0f;

    bool updateRenderData = true; // weather the sheet music needs to be updated(rendered) again

    float zoom = 1.0f;
    Vec2<float> offset = { 0.0f, 0.0f };
};
