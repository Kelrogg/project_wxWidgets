#ifndef COMMAND_DOCUMENT_ELEMENTS_FRAME_HPP
#define COMMAND_DOCUMENT_ELEMENTS_FRAME_HPP

#include "Point.hpp"

template <typename T>
struct Frame
{
    explicit constexpr Frame() = default;
    explicit constexpr Frame(const Point<T> &leftTop, const Size<T> &size)
        : pLeftTop(leftTop), size(size)
    {
    }

    explicit constexpr Frame(T xLeftTop, T yLeftTop, T width, T height)
        : pLeftTop(xLeftTop, yLeftTop), size(width, height)
    {
    }

    bool operator==(const Frame<T> &other) const noexcept
    {
        return pLeftTop = other.pLeftTop && size == other.size;
    }

    bool operator!=(const Frame<T> &other) const noexcept
    {
        return !(*this == other);
    }

    Point<T> m_topLeft;
    Point<T> m_bottomRight;
};

template <typename T, typename Container>
static inline Frame<T> GetFrame(Container const &framesContainer)
{
    T minX{}, minY{}, maxX{}, maxY{};

    for (const auto &rect : framesContainer)
    {
        minX = std::min(minX, rect.pLeftTop.x);
        minY = std::min(minY, rect.pLeftTop.y);

        maxX = std::max(maxX, rect.pLeftTop.x + rect.size.width);
        maxY = std::max(maxY, rect.pLeftTop.y + rect.size.height);
    }

    return Frame<T>(minX, minY, std::abs(minX + maxX), std::abs(minY + maxY));
}

#endif