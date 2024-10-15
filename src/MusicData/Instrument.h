#pragma once

#include <string>
#include <vector>

#include "Staff.h"

class Instrument
{
public:
    Instrument(const std::string& name)
        : m_Name(name) {}

    void Render(RenderData& renderData) const;

    void AddStaff(std::shared_ptr<Staff> staff);

private:
    std::string m_Name;

    std::vector<std::shared_ptr<Staff>> m_Staves;
};