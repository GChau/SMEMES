#include "stdafx.h"

namespace processor
{
    template<typename Register, typename DataWidthInput, typename DataWidthOutput>
    struct PROCESSORExport address_mode_base
    {
    public:
        address_mode_base(std::shared_ptr<Register> reg, std::shared_ptr<std::vector<DataWidthInput>> mem)  :
            reg_(std::move(reg)),
            mem_(std::move(mem))
        {
        }
    public:
        virtual DataWidthOutput resolve(const DataWidthInput value) = 0;
    protected:
        // Data
        std::shared_ptr<Register> reg_;
        std::shared_ptr<std::vector<DataWidthInput>> mem_;
    };

    template<typename Register, typename DataWidthInput, typename DataWidthOutput>
    struct PROCESSORExport immediate : public address_mode_base<Register, DataWidthInput, DataWidthOutput>
    {
    public:
        using address_mode_base::address_mode_base;
    public:
        virtual __inline DataWidthOutput resolve(const DataWidthInput value) override {
            return (DataWidthOutput)value;
        }
    };

    template<typename Register, typename DataWidthInput, typename DataWidthOutput>
    struct PROCESSORExport immediate : public address_mode_base<Register, DataWidthInput, DataWidthOutput>
    {
    public:
        using address_mode_base::address_mode_base;
    public:
        virtual __inline DataWidthOutput resolve(const DataWidthInput value) override {
            return (DataWidthOutput)(*mem_)[value];
        }
    };

    template<typename Register, typename DataWidthInput, typename DataWidthOutput>
    struct PROCESSORExport dp_indexed_indirect_x :  public address_mode_base<Register, DataWidthInput, DataWidthOutput>
    {
    public:
        using address_mode_base::address_mode_base;
    public:
        virtual __inline DataWidthOutput resolve(const DataWidthInput value) override {
            return (*mem_)[reg_->DP_ + reg_->X_];
        }
    };


}; // processor