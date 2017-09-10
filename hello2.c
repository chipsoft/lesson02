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
module_param( iparam, uint, S_IRUGO ); // Имя и тип входного параметра модуля
MODULE_PARM_DESC(iparam, "Number of messages to print");

static int __init hello_init(void)
{
	uint i = 0;
	WARN_ON(!iparam); // Предупреждение при значении параметра равном 0 (посмотреть можно через dmesg)
	BUG_ON(iparam == 10);
	if (iparam == 5) return -EINVAL; // Возвращаем ошибку при значении параметра 5
	printk(KERN_EMERG "-> Module 02 load!\n");
	for (i = 0; i < iparam; ++i) print_hello(); // Выводим количество сообщений, заданных в параметре
	if (iparam == 2) __module_get(THIS_MODULE); // При значении параметра равном 2 увеличиваем число ссылок на модуль
	return 0;
}

static void print_goodbye(void)
{
	printk(KERN_EMERG "Good bye!\n");
}

static void __exit hello_exit(void)
{
	printk(KERN_EMERG "<- Module 02 unload!\n");
	print_goodbye(); // Вызываем функцию из другого модуля
	//u8 *var = (u8*)&__kmalloc;
	//*var = 0x90;
	//__kmalloc(4, GFP_KERNEL);
	//__kmalloc(4, GFP_KERNEL);
	//__kmalloc(4, GFP_KERNEL);
}

module_init(hello_init);
module_exit(hello_exit);
