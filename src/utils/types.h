#pragma once
#include<inttypes.h>

template<class type>
struct uint
{
public:
    uint() : dat_(0)
    {
    }

    uint(const uint& other) : dat_(other.dat_)
    {
    }

    uint(const type& val) : dat_(val)
    {
    }

public:
    type dat_;

    type bit(int pos)
    {
        return (dat_ >> pos) & 0x1;
    }

    template<int pos>
    type bit()
    {
        return (dat_ >> pos) & 0x1;
    }

    type byte(int pos)
    {
        int actualPosition = pos * 4;
        type shiftedDat = dat_ >> actualPosition;
        return (shiftedDat & 0xFFFF);
    }

    inline  auto& operator=(const type &data)
    {
        dat_ = data;
        return *this;
    }

    inline auto& operator=(const uint &data)
    {
        dat_ = data.dat_;
        return *this;
    }

    /***********************************
    /           COMPARISONS
    ***********************************/

    inline friend bool operator==(const uint &rhs, const uint &lhs)
    {
        return (rhs.dat_ == lhs.dat_);
    }

    inline friend bool operator<(const uint &rhs, const uint &lhs)
    {
        return (rhs.dat_ < lhs.dat_);
    }

    inline friend bool operator<=(const uint &rhs, const uint &lhs)
    {
        return (rhs.dat_ <= lhs.dat_);
    }

    inline friend bool operator>(const uint &rhs, const uint &lhs)
    {
        return (rhs.dat_ > lhs.dat_);
    }

    inline friend bool operator>=(const uint &rhs, const uint &lhs)
    {
        return (rhs.dat_ >= lhs.dat_);
    }

    /***********************************
    /               MATHS
    ***********************************/
    inline friend auto & operator+=(uint &rhs, const uint &lhs)
    {
        rhs.dat_ = rhs.dat_ + lhs.dat_;
        return rhs;
    }

    inline friend auto & operator-=(uint &rhs, const uint &lhs)
    {
        rhs.dat_ = rhs.dat_ - lhs.dat_;
        return rhs;
    }



    inline auto & operator +=(const type &lhs)
    {
        dat_ = dat_ + lhs;
        return *this;
    }

    inline auto operator <<(const uint &lhs)
    {
        return (this.dat_ << lhs.dat_);
    }
    
    inline auto operator >>(const uint &lhs)
    {
        return (this.dat_ >> lhs.dat_);
    }

    inline friend auto operator+(const uint &rhs, const uint &lhs)
    {
        return rhs.dat_ + lhs.dat_;
    }

    inline friend auto operator-(const uint &rhs; const uint &lhs)
    {
        return rhs.dat_ - lhs.dat_;
    }
};

typedef uint<uint8_t> uint8;
typedef uint<uint16_t> uint16;
typedef uint<uint32_t> uint32;
