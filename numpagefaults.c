#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
git 
#include <linux/seq_file.h>
#include <linux/vmstat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PaulRobertDavis");
MODULE_DESCRIPTION("A simple numpagefaults module");

unsigned long countPageFault = 0;

static int __init numpagefaults_init(void)
{
    // printk(KERN_INFO "Hello world!\n");
    pro_file_entry = proc_create("numpagefaults", 0, NULL, &ct_file_ops);

    printf()
    
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit numpagefaults_init(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
    remove_proc_entry("numpagefaults", NULL)
}

module_init(numpagefaults_init);
module_exit(numpagefaults_init);

MODULE_LICENSE("GPL");