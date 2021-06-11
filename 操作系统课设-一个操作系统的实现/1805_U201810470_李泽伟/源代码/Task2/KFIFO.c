#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include<linux/kfifo.h>
#include<linux/wait.h>
#include<linux/sched.h>
#include<linux/slab.h>
#include<linux/uaccess.h>

#define    HELLO_MAJOR     236
#define    DEVICE_NAME     "MyTestTorKfifo"
#define BUFFER_SIZE 32

DEFINE_KFIFO(FIFO_BUFFER,char,BUFFER_SIZE);
/*
 * DEFINE_KFIFO - 定义并且初始化一个 fifo 结构
 * @fifo: name of the declared fifo datatype
 * @type: type of the fifo elements
 * @size: the number of elements in the fifo, 在初化时，将它向上扩展成2的幂
*/
unsigned int actual_read;
unsigned int actual_write;

wait_queue_head_t read_queue;
wait_queue_head_t write_queue;

static int mytest_open(struct inode *inodep, struct file *filep){
    printk(KERN_EMERG "hello open.\n");
    return 0;
}

static ssize_t mytest_read(struct file *filep, char __user * buf, size_t count, loff_t *ppos)
{
    if(kfifo_is_empty(&FIFO_BUFFER))
    {
        if(filep->f_flags&O_NONBLOCK)//f_flags:表示打开文件的权限
        return -EAGAIN;
        wait_event_interruptible(read_queue,!kfifo_is_empty(&FIFO_BUFFER));
    }
    kfifo_to_user(&FIFO_BUFFER,buf,count,&actual_read);
    //read from FIFO_BUFFER
    if(!kfifo_is_full(&FIFO_BUFFER))//condition = 0 休眠 condition = 1 唤醒
    {
        wake_up_interruptible(&write_queue);
    }

    return actual_read;
}

static ssize_t mytest_write(struct file *filep,const char __user * buf, size_t count, loff_t *ppos)
{
    if(kfifo_is_full(&FIFO_BUFFER))
    {
        if(filep->f_flags&O_NONBLOCK)
            return -EAGAIN;
        wait_event_interruptible(write_queue,!kfifo_is_full(&FIFO_BUFFER));
    }//
    kfifo_from_user(&FIFO_BUFFER,buf,count,&actual_write);
    if(!kfifo_is_empty(&FIFO_BUFFER))
        wake_up_interruptible(&read_queue);
   
    return actual_write;
}


static struct file_operations mytest_flops = {
    .owner  =   THIS_MODULE,
    .open   =   mytest_open,     
    .write  =   mytest_write,
    .read   =   mytest_read,
};

static int __init mytest_init(void){
    int ret;
    
    ret = register_chrdev(HELLO_MAJOR,DEVICE_NAME, &mytest_flops);
    if (ret < 0) {
      printk(KERN_EMERG DEVICE_NAME " can't register major number.\n");
      return ret;
    }
    printk(KERN_EMERG DEVICE_NAME " initialized.\n");
    init_waitqueue_head(&read_queue);
    init_waitqueue_head(&write_queue);
    return 0;
}

static void __exit mytest_exit(void){
    unregister_chrdev(HELLO_MAJOR, DEVICE_NAME);
    printk(KERN_EMERG DEVICE_NAME " removed.\n");
}

module_init(mytest_init);
module_exit(mytest_exit);
MODULE_LICENSE("GPL");

