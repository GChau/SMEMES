#include "stdafx.h"

namespace processor
{
    enum class transfer_type_e {
        data_transfer,
        control_transfer,   // This is for transfering control between banks (jump absolute long etc.)
        no_transfer
    };

    // Helper function for static assertions
    // If T is a complete enumeration type, provides a member typedef type that names the underlying type of T.
    // https://en.cppreference.com/w/cpp/types/underlying_type
    template<typename E>
    constexpr auto to_integral(E e) -> typename std::underlying_type_t<E> {
        return static_cast<typename std::underlying_type_t<E>>(e);
    }

    enum class address_mode_e {
        immediate,
        absolute_addressing_ct,
        absolute_addressing_dt
    };

    //---------------------------------------------------------------------------------------------

    // See page 92
    template<typename Register, typename Memory, typename DataWidth, typename EnumClass, EnumClass TransferType>
    struct PROCESSORExport absolute_addressing
    {
    public:
        __inline DataWidth operator()(const Register& reg, const Memory& mem, const DataWidth& operand) {
            static_assert(std::is_same_v<EnumClass, transfer_type_e>, "template EnumClass parameter must be of enum class transfer_type_e.");
            static_assert(to_integral(TransferType) != to_integral(transfer_type_e::no_transfer), "transfer_type_e::no_transfer not allowed for absolute addressing - address mode.");

            // Hack for now
            // Does this work for 16 bit mode?
            // Decide to either use the data bank register as the 16-24 bits in the address
            // Or just using the PC counter
            const auto& reg_byte = to_integral(TransferType) == to_integral(transfer_type_e::data_transfer) ? reg->DB_ : reg->PC_;

            // Urgh, can we template this? Another data type?
            const uint32_t full_address = ((reg->DB_ << 16) | operand) & 0x00FFFFFF;
            return (*mem)[full_address];
        }
    };

    //---------------------------------------------------------------------------------------------

    // Example opcode
    // A912     LDA     #$12
    // Load hexidecimal operand $12 into the accumulator
    // # indicates constant operand
    template<typename Register, typename Memory, typename DataWidth>
    struct PROCESSORExport immediate
    {    
    public:
        __inline DataWidth operator()(const Register& reg, const Memory& mem, const DataWidth operand) {
            return operand;
        }
    };
    
    //---------------------------------------------------------------------------------------------

    template<typename Register, typename Memory, typename DataWidth>
    struct PROCESSORExport dp_indexed_indirect_x
    {
    public:
        __inline DataWidth resolve(const Register& reg, const Memory& mem, const DataWidth operand) {
            return (*mem)[reg->DP_ + reg->X_];
        }
    };

}; // processor