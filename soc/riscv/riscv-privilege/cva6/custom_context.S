

#include <offsets_short_arch.h>
#include <zephyr/linker/sections.h>
#include "custom_context.h"
#include <soc.h>

/* Exports */
#ifdef CONFIG_RISCV_CUSTOM_CONTEXT_SAVE
GTEXT(__custom_switch_context)

// a1 is old thread
// a0 is new one
SECTION_FUNC(TEXT, __custom_switch_context)
    lw t0, CUSTOM_SAVE_OFFSET(init)(a0)
    lw t1, CUSTOM_SAVE_OFFSET(ctrl)(a0)
	bnez t0, init_tosp
    lw t0, CUSTOM_SAVE_OFFSET(tosp)(a0)
    csrrw t2, CSR_RAS_TOSP, t0
    sw t2, CUSTOM_SAVE_OFFSET(tosp)(a1)
done_init:
    csrw CSR_RAS_CTRL, t1
    ret
init_tosp:
    sw zero, CUSTOM_SAVE_OFFSET(init)(a0)
    ori t1, t1, RAS_CTRL_GEN_NEW_TOSP
    j done_init

#endif /* CONFIG_RISCV_CUSTOM_CONTEXT_SAVE */
