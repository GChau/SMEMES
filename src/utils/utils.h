#pragma once
#include <stdint.h>

struct uint8
{
public:
    uint8() : dat_(0)
    {
    }

    uint8(const uint8& other) : dat_(other.dat_)
    {
    }

    uint8(const uint8_t& val) : dat_(val)
    {
    }

public:
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
public:
    // Data
    uint8_t dat_;
};

struct uint16
{
public:
    uint16() : dat_(0)
    {
    }

    uint16(const uint16& other) : dat_(other.dat_)
    {
    }

    uint16(const uint16_t& val) : dat_(val)
    {
    }

public:
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

public:
    // Data
    uint16_t dat_;
};