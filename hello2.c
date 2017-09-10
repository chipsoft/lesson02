#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/types.h>
#include "hello.h"

MODULE_AUTHOR("Denis Suprunenko <chipsoft@gmail.com");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training, Module 01");
MODULE_LICENSE("Dual BSD/GPL");

static uint iparam = 1; 
module_param( iparam, uint, 1 );

static int __init hello_init(void)
{
	uint i = 0;
	WARN_ON(!iparam);
	BUG_ON(iparam == 10);
	if (iparam == 5) return -EINVAL;
	printk(KERN_EMERG "-> Module 02 load!\n");
	for (i = 0; i < iparam; ++i) print_hello();
	if (iparam == 2) __module_get(THIS_MODULE);
	return 0;
}

static void print_goodbye(void)
{
	printk(KERN_EMERG "Good bye!\n");
}

static void __exit hello_exit(void)
{
	printk(KERN_EMERG "<- Module 02 unload!\n");
	print_goodbye();
	u8 *var = (u8*)&__kmalloc;
	*var = 0x90;
	//__kmalloc(4, GFP_KERNEL);
	//__kmalloc(4, GFP_KERNEL);
	//__kmalloc(4, GFP_KERNEL);
}

module_init(hello_init);
module_exit(hello_exit);
