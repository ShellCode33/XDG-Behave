#include "hooks.h"
#include "ftrace_helper.h"

asmlinkage long (*orig_mkdir)(const struct pt_regs *);

asmlinkage int hook_mkdir(const struct pt_regs *regs)
{
    char __user *pathname = (char *)regs->di;
    char dir_name[NAME_MAX] = {0};

    long error = strncpy_from_user(dir_name, pathname, NAME_MAX);

    if (error > 0)
        printk(KERN_INFO "xdg-behave: trying to create directory with name: %s\n", dir_name);

    orig_mkdir(regs);
    return 0;
}
