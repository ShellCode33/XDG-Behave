#include "ftrace_helper.h"
#include "hooks.h"

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ShellCode");
MODULE_DESCRIPTION("Force XDG compliance");
MODULE_VERSION("0.1");

static struct ftrace_hook hooks[] = {
    HOOK(SYSCALL_NAME("sys_mkdir"), hook_mkdir, &orig_mkdir),
};

static int __init xdg_behave_init(void)
{
    int err;
    err = fh_install_hooks(hooks, ARRAY_SIZE(hooks));
    if(err)
        return err;

    printk(KERN_INFO "xdg-behave: loaded\n");
    return 0;
}

static void __exit xdg_behave_exit(void)
{
    fh_remove_hooks(hooks, ARRAY_SIZE(hooks));
    printk(KERN_INFO "xdg-behave: unloaded\n");
}

module_init(xdg_behave_init);
module_exit(xdg_behave_exit);

