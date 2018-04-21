#include "stdafx.h"

namespace processor
{
    enum class transfer_type_e {
        data_transfer,
        control_transfer,
        no_transfer
    };

    // Helper function for static assertions
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

    template<typename Register, typename DataWidth, typename EnumClass, EnumClass TransferType>
    struct PROCESSORExport address_mode_base
    {
    public:
        address_mode_base(std::shared_ptr<Register> reg, std::shared_ptr<std::vector<DataWidth>> mem) :
            reg_(std::move(reg)),
            mem_(std::move(mem))
        {
        }

        virtual ~address_mode_base()
        {
        }

    public:
        virtual DataWidth resolve(const DataWidth value) = 0;
    protected:
        // Data
        std::shared_ptr<Register> reg_;
        std::shared_ptr<std::vector<DataWidth>> mem_;
    };

    //---------------------------------------------------------------------------------------------

    template<typename Register, typename DataWidth, typename EnumClass, EnumClass TransferType>
    struct PROCESSORExport absolute_addressing : public address_mode_base<Register, DataWidth, EnumClass, TransferType>
    {
    public:
        using address_mode_base::address_mode_base;

    public:
        virtual __inline DataWidth resolve(const DataWidth value) override {
            static_assert(std::is_same_v<EnumClass, transfer_type_e>, "tempalte EnumClass parameter must be of enum class transfer_type_e.");
            static_assert(to_integral(TransferType) != to_integral(transfer_type_e::no_transfer), "transfer_type_e::no_transfer not allowed for absolute addressing - address mode.");

            // Hack for now
            // Does this work for 16 bit mode?

            const auto& reg_byte = to_integral(TransferType) == to_integral(transfer_type_e::data_transfer) ? reg_->DB_ : reg_->PC_;


            const uint32_t full_address = (value | (reg_->DB_ << (sizeof(DataWidth) * 8))) & 0x00FFFFFF;
            return (*mem_)[full_address];

            return 0;
        }
    };

    //---------------------------------------------------------------------------------------------

    // Example opcode
    // A912     LDA     #$12
    // Load hexidecimal value $12 into the accumulator
    // # indicates constant value
    template<typename Register, typename DataWidth>
    struct PROCESSORExport immediate : public address_mode_base<Register, DataWidth, transfer_type_e, transfer_type_e::no_transfer>
    {
    public:
        using address_mode_base::address_mode_base;

    public:
        virtual __inline DataWidth resolve(const DataWidth value) override {
            return (DataWidth)value;
        }
    };

    //---------------------------------------------------------------------------------------------

    template<typename Register, typename DataWidth>
    struct PROCESSORExport dp_indexed_indirect_x : public address_mode_base<Register, DataWidth, transfer_type_e, transfer_type_e::no_transfer>
    {
    public:
        using address_mode_base::address_mode_base;
    public:
        virtual __inline DataWidth resolve(const DataWidth value) override {
            return (*mem_)[reg_->DP_ + reg_->X_];
        }
    };

}; // processor