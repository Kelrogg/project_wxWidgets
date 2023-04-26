#pragma once

#include <wx/wx.h>

struct GraphicObject
{
    wxRect2DDouble rect;
    wxColor color;
    wxAffineMatrix2D transform;
    // wxRect2DDouble selectedFrame;

    // void selectFrame()
    //{
    //     T minX{}, minY{}, maxX{}, maxY{};
    //
    //    for (const auto &rect : container)
    //    {
    //        minX = std::min(minX, rect.leftTop.x);
    //        minY = std::min(minY, rect.leftTop.y);
    //
    //        maxX = std::max(maxX, rect.leftTop.x + rect.width);
    //        maxY = std::max(maxY, rect.leftTop.y + rect.height);
    //    }
    //}
};