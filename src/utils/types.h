#include<inttypes.h>

template<class type>
struct uint
{
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

    auto& operator=(const type data)
    {
        dat_ = data;
        return *this;
    }

    auto& operator=(const uint data)
    {
        dat_ = data.dat_;
        return *this;
    }

    auto operator==(const uint &other) const
    {
        return (dat_ == other.dat_);
    }

    auto operator==(const type &other) const
    {
        return (dat_ == other);
    }

    auto operator+(const type &other) const
    {
        this.dat_ += other;
        return this.dat_;
    }
};

typedef uint<uint8_t> uint8;
typedef uint<uint16_t> uint16;
typedef uint<uint32_t> uint32;
