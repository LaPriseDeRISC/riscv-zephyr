//
// Created by noic on 04/05/23.
//

#ifndef CVA6_SOFTCORE_CONTEST_LPDR_SOC_OFFSETS_H
#define CVA6_SOFTCORE_CONTEST_LPDR_SOC_OFFSETS_H

#if defined(CONFIG_RISCV_CUSTOM_OFFSETS)

#define GEN_CUSTOM_OFFSETS_SYMS()   \
	GEN_OFFSET_SYM(custom_context_t, tosp);\
	GEN_OFFSET_SYM(custom_context_t, ctrl);\
    GEN_OFFSET_SYM(custom_context_t, init)

#endif  /* CONFIG_RISCV_CUSTOM_OFFSETS */

#endif //CVA6_SOFTCORE_CONTEST_LPDR_SOC_OFFSETS_H
