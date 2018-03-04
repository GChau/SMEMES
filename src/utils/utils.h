#pragma once
#include <stdint.h>

struct uint8
{
    uint8_t dat;

    uint8_t bit(uint8_t pos)
    {
        return (dat >> pos) & 0x1;
    }

    auto& operator=(const uint8_t data)
    {
        dat = data;
        return *this;
    }

    auto& operator=(const uint8 data)
    {
        dat = data.dat;
        return *this;
    }

    auto operator==(const uint8 &other) const
    {
        return (dat == other.dat);
    }

    auto operator==(const uint8_t &other) const
    {
        return (dat == other);
    }
};

struct uint16
{
    uint16_t dat;

    uint16_t bit(uint16_t pos)
    {
        return (dat >> pos) & 0x1;
    }

    auto& operator=(const uint16_t data)
    {
        dat = data;
        return *this;
    }

    auto operator==(const uint16 &other) const
    {
        return (dat == other.dat);
    }

    auto operator==(const uint16_t &other) const
    {
        return (dat == other);
    }
};