#pragma once

#include <vector>
#include <memory>

#include "Lyric.h"

class Lyric;

class LyricPickup
{
public:
    std::vector<std::shared_ptr<Lyric>> lyrics;
};

