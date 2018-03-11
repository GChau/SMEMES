#include "stdafx.h"

namespace processor
{
    template<typename Register, typename DataWidth>
    struct PROCESSORExport address_mode_base
    {
    public:
        address_mode_base(std::shared_ptr<Register> reg, std::shared_ptr<std::vector<DataWidth>> mem)  :
            reg_(std::move(reg)),
            mem_(std::move(mem))
        {
        }
    public:
        virtual DataWidth resolve(const DataWidth value) = 0;
    protected:
        // Data
        std::shared_ptr<Register> reg_;
        std::shared_ptr<std::vector<DataWidth>> mem_;
    };

    template<typename Register, typename DataWidth>
    struct PROCESSORExport dp_indexed_indirect :
        public address_mode_base<Register, DataWidth>
    {
    public:
        using address_mode_base::address_mode_base;
    public:
        virtual __inline DataWidth resolve(const DataWidth ) override {
            return (*mem_)[reg_->DP_];
        }
    };

}; // processor