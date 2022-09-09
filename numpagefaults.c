#include <linux/module.h>	// included for all kernel modules
#include <linux/kernel.h>	// included for KERN_INFO
#include <linux/init.h>	  // included for __init and __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PaulRobertDavis");
MODULE_DESCRIPTION("A simple numpagefaults module");

static int __init numpagefaults_init(void)
{
    printk(KERN_INFO "Hello world!\n");
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit numpagefaults_cleanup(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
	
}

module_init(numpagefaults_init);
module_exit(numpagefaults_cleanup);

MODULE_LICENSE("GPL");
