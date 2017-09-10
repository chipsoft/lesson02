#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello.h"

MODULE_AUTHOR("Denis Suprunenko <chipsoft@gmail.com");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training, Module 01");
MODULE_LICENSE("Dual BSD/GPL");

extern void print_hello(void)
{
	printk(KERN_EMERG "Hello, world from Module 01!\n");	
}
EXPORT_SYMBOL(print_hello);

static int __init hello_init(void)
{
	printk(KERN_EMERG "-> Module 01 load!\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_EMERG "<- Module 01 unload!\n");
}

module_init(hello_init);
module_exit(hello_exit);
