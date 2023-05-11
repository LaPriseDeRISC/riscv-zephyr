//
// Created by noic on 04/05/23.
//

#ifndef CVA6_SOFTCORE_CONTEST_LPDR_SOC_CONTEXT_H
#define CVA6_SOFTCORE_CONTEST_LPDR_SOC_CONTEXT_H

#define RAS_CTRL_GEN_NEW_TOSP   0b10
#define RAS_CTRL_ENABLE_SECURE  0b01

#if defined(CONFIG_RISCV_CUSTOM_CONTEXT_SAVE)
    #define CUSTOM_CONTEXT_MEMBERS	\
        uint32_t tosp;	        \
        uint32_t ctrl;          \
        uint32_t init

    #define CUSTOM_CONTEXT_INIT	\
        0,	                    \
        RAS_CTRL_ENABLE_SECURE, \
        1

#endif

#endif //CVA6_SOFTCORE_CONTEST_LPDR_SOC_CONTEXT_H
