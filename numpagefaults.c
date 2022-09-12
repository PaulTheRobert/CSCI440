#include <linux/module.h>	// included for all kernel modules
#include <linux/kernel.h>	// included for KERN_INFO
#include <linux/init.h>	        // included for __init and __exit macros

#include <linux/fs.h>		// fs
#include <linux/proc_fs.h>	// needed for proc_create
#include <linux/seq_file.h>	// sequence files
#include <linux/jiffies.h>	// jiffies - following example from web
#include <linux/mm.h>		// for all_vm_events
				//

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PaulRobertDavis");
MODULE_DESCRIPTION("A simple numpagefaults module");


static struct proc_dir_entry* numpagefaults_file;

//static void *sequence_start(struct seq_file *s, loff_t *pos){
//	loff_t *spos = kmalloc(sizeof(loff_t), GFP_KERNEL);
//	if(! spos)
//		return NULL;
//	*spos = *pos;
//	return spos;
//}


static int print_numpagefaults(struct seq_file *m, void *v){
//	unsigned long events*[NR_VM_EVENT_ITEMS];

	unsigned long  numpagefault = 999999;
//	struct memory_data *mem_data;
	
//	mem_data = data;
//	mem_data->sync_count1++;

//	all_vm_events(events);
	 
//	mem_data->pgfault = events[PGFAULT];

//	seq_printf(m, "%llu", events[PGFAULT]);
//	seq_printf(m, "%llu", events, "PGFAULT");
	seq_printf(m, "%lun", numpagefault);
	return 0;
}

static int open_numpagefaults(struct inode *inode, struct file *file){
	return single_open(file, print_numpagefaults, NULL);
//	return seq_open(file, &ct_seq_ops);
	return 0;
}

static struct proc_ops numpagefaults_fops = {
	.proc_open = open_numpagefaults,
	.proc_read = seq_read,
};

static int __init numpagefaults_init(void){
	
	numpagefaults_file = proc_create("numpagefaults", 0, NULL, &numpagefaults_fops);
	
	if (!numpagefaults_file){
		return -ENOMEM;
	}

	return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit numpagefaults_cleanup(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
	remove_proc_entry("numpagefaults", NULL);
	
}

module_init(numpagefaults_init);
module_exit(numpagefaults_cleanup);

MODULE_LICENSE("GPL");
