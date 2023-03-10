#ifndef HOOKS_H
#define HOOKS_H

#include <linux/ftrace.h>

extern asmlinkage long (*orig_mkdir)(const struct pt_regs *);
asmlinkage int hook_mkdir(const struct pt_regs *regs);

#endif // HOOKS_H
