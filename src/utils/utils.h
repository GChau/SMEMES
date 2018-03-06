#pragma once
#include <stdint.h>

struct uint8
{
    uint8_t dat_;

    uint8_t bit(uint8_t pos)
    {
        return (dat_ >> pos) & 0x1;
    }

    template<int pos>
    uint8_t bit()
    {
        return (dat_ >> pos) & 0x1;
    }

    auto& operator=(const uint8_t data)
    {
        dat_ = data;
        return *this;
    }

    auto operator==(const uint8 &other) const
    {
        return (dat_ == other.dat_);
    }

    auto operator==(const uint8_t &other) const
    {
        return (dat_ == other);
    }
};

struct uint16
{
    uint16_t dat_;

    uint16_t bit(uint16_t pos)
    {
        return (dat_ >> pos) & 0x1;
    }

    template<int pos>
    uint16_t bit()
    {
        return (dat_ >> pos) & 0x1;
    }

    auto& operator=(const uint16_t data)
    {
        dat_ = data;
        return *this;
    }

    auto operator==(const uint16 &other) const
    {
        return (dat_ == other.dat_);
    }

    auto operator==(const uint16_t &other) const
    {
        return (dat_ == other);
    }
};