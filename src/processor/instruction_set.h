#include "stdafx.h"

#include "proc_65c816.h"

namespace processor {
    namespace imp
    {
        // Page 327
        // algorithm.cpp algorithmADC16
        template<typename AddressMode, typename Processor>
        __inline void add_with_carry(Processor* proc, const uint16_t operand) {
            AddressMode am{};
            int32_t result;
            int32_t CF = proc->get_reg()->P_.C ? 1 : 0;
            
            if (!proc->get_reg()->P_.D) {
                result = am(proc->get_reg(), proc->get_mem(), operand) + CF;
            } else {
                result = (proc->get_reg()->A_ & 0x000F) + (operand & 0x000F) + (CF << 0);
                if (result > 0x0009) { result += 0x0006; }
                CF = result > 0x000F;
                result = (proc->get_reg()->A_ & 0x00F0) + (operand & 0x00F0) + (CF << 4) + (result & 0x000F);
                if (result > 0x009F) { result += 0x0060; }
                CF = result > 0x00FF;
                result = (proc->get_reg()->A_ & 0x0F00) + (operand & 0x0F00) + (CF << 8) + (result & 0x00FF);
                if (result > 0x09FF) { result += 0x0600; }
                CF = result > 0x0FFF;
                result = (proc->get_reg()->A_ & 0xF000) + (operand & 0xF000) + (CF << 12) + (result & 0x0FFF);
            } 

            // Set flags
            proc->get_reg()->P_.N = result & 0x8000;
            proc->get_reg()->P_.V = ~(proc->get_reg()->A_ ^ operand) & (proc->get_reg()->A_ ^ result) & 0x8000;
            proc->get_reg()->P_.Z = (uint16_t)result == 0;
            proc->get_reg()->P_.C = result > 0xFFFF;

            proc->get_reg()->A_ = result;
        }
    }
}