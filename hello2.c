// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>

MODULE_AUTHOR("Tyshniuk Ivan");
MODULE_DESCRIPTION("Lab 5 - Hello2");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int hello_ammount = 1;
module_param(hello_ammount, uint, 0444);
MODULE_PARM_DESC(hello_ammount, "Ammount of 'Hello, World!' that will be printed");

extern void print_hello(void);

static int __init hello2_init(void)
{
	int i;

	if (hello_ammount == 0 || (hello_ammount >= 5 && hello_ammount <= 10))
		pr_warn("Parameter is either 0 or in range 5-10\n");

	if (hello_ammount > 10) {
		pr_err("Parameter can't be larger than 10\n");
		return -EINVAL;
	}

	for (i = 0; i < hello_ammount; i++) {
		print_hello();
	}

	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Module hello2 unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

