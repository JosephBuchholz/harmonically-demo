/**
 * Defaults/settings for how the music should be displayed. (Not all of them are used for this demo project).
 */

#pragma once

#include "../MusicData/Types.h"

#define DEFAULT_STAFF_LINE_WIDTH 0.8333f

#define DEFAULT_PAGE_WIDTH 1233.87f
#define DEFAULT_PAGE_HEIGHT 1596.77f

#define DEFAULT_LEFT_MARGIN 110.0f
#define DEFAULT_RIGHT_MARGIN 80.0f
#define DEFAULT_TOP_MARGIN 80.0f
#define DEFAULT_BOTTOM_MARGIN 80.0f

struct Scaling
{
    float millimeters;
    float tenths;
};

struct MusicDisplayConstants
{
    // all in tenths

    float lineSpacing = 10.0f;
    float tabLineSpacing = 13.33f;

    float pageWidth = DEFAULT_PAGE_WIDTH;
    float pageHeight = DEFAULT_PAGE_HEIGHT;

    float leftMargin = DEFAULT_LEFT_MARGIN;
    float rightMargin = DEFAULT_RIGHT_MARGIN;
    float topMargin = DEFAULT_TOP_MARGIN;
    float bottomMargin = DEFAULT_BOTTOM_MARGIN;

    float staffDistance = 80.0f;

    float stemLineWidth = 1.25f;
    float beamLineWidth = 5.0f;
    float staffLineWidth = DEFAULT_STAFF_LINE_WIDTH;
    float lightBarLineWidth = 2.0833f;
    float heavyBarLineWidth = 6.6667f;
    float legerLineWidth = 1.25f;
    float endingLineWidth = 0.7682f;
    float wedgeLineWidth = 0.957f;
    float enclosureLineWidth = 1.6667f;

    // percentage of the regular size
    float graceNoteSize = 0.66f;
    float cueNoteSize = 0.66f;

    float hyphenDistance = 60.0f;
    float beamDistance = 7.5f;

    float clefChangeScale = 0.75f; // clef changes are commonly drawn 2/3rds the size of normal clefs (according to SMuFL)

    Scaling scaling;

    float ledgerLineMargin = 3.5f;

    // notes stems
    float minNoteStemHeight = 15.0f; // the minimum height for a note stem (not including the beam height)

    // beams
    float maxBeamSlope = 0.333f; // the maximum (abs value) slope that a beam can have

    // chord sheet
    FontSize lyricFontSize = FontSize(12.0f);

    float chordMarginFromBarline = 8.0f;
    float beatWidth = 30.0f;
    float chordPositionY = 5.0f;
    float lyricPositionY = 28.0f;
    float lyricSpaceWidth = 8.0f;
    float minimumMeasureWidth = 30.0f;
    bool displayReminderPickupLyrics = false;

    float measureBarlineHeight = 22.0f;
    FontSize chordFontSize = FontSize(12.0f);
};