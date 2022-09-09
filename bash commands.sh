# Compile Hello World kernel module
~$ wget https://www.bryancdixon.com/static/helloworld.tar 
~$ tar xvf helloworld.tar x helloworld/ x helloworld/hello.c x helloworld/Makefile

$ cd helloworld $ make

~/helloworld$ ls hello.c hello.ko hello.mod.c hello.mod.o hello.o Makefile modules.order Module.symvers



# bash 
# inserted the Hello World kernel module with the insmod command 
~/helloworld$ sudo insmod hello.ko 
# , immediately removed it with the rmmod command, 
~/helloworld$ sudo rmmod hello 
# and finally inspected the dmesg output to find the printk statements that printed ”Hello World!” 
# when the module was installed and the cleanup message when the module was removed. In the above output, this process completed successfully.
~/helloworld$ sudo dmesg | tail 

[ 6814.354580] Hello world! [ 6819.571911] Cleaning up module.