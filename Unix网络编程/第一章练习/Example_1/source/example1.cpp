#include <iostream>
#include <cstring>
#include <dirent.h>
#include "example1.h"

using namespace std;

//列出目录项
void testDir(char* dir)
{
    DIR* dp;
    struct dirent * dirp;

    //打开目录
    dp = opendir(dir);
    if(dp == NULL)
    {
        cout << "can not open " << dir << endl;
        exit(2);
    }

    //读取目录中的每一项内容
    dirp = readdir(dp);
    while (dirp != NULL)
    {
        cout << dirp->d_name << endl;
        dirp = readdir(dp);
    }

    closedir(dp);

}

//测试IO输入输出
void testIO()
{
    int n = 0;
    char buf[MAXBUFFERSIZE] = {'\0'};
    n = read(STDIN_FILENO, buf, MAXBUFFERSIZE);
    while (n > 0)
    {
        if(write(STDOUT_FILENO, buf, n) != n)
        {
            cout << "write error1\n";
            exit(1);
        }
        n = read(STDIN_FILENO, buf, MAXBUFFERSIZE);

    }

    if(n < 0)
    {
        cout << "read error!\n";
        exit(2);
    }
    

}

//测试信号signal
void sigInt(int)
{
    cout << "sigInt()!!!\n";
}

void testSignal()
{
    pid_t pid;
    int status;
    char buf[MAXBUFFERSIZE] = {'\0'};

    if(signal(SIGINT, sigInt) == SIG_ERR)
    {
        cout << "signale error!\n";
    }

    //从标准输入中获取执行执行命令
    while (fgets(buf, MAXBUFFERSIZE, stdin) != NULL)
    {
        if(buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = '\0';
        }
    }

    //生成子进程，并执行
    if((pid = fork()) < 0)    
    {
        cout << "fork error1\n";
    }
    else if(pid == 0)
    {
        //execlp()是exec()的函数变体，功能：从PATH 环境变量所指的目录中查找符合参数file的文件名，
        //找到后便执行该文件，然后将第二个以后的参数当做该文件的argv[0]、argv[1]……，最后一个参数必须用空指针(NULL)作结束
        //通常用0代表一个NULL指针;函数执行成功，函数后面的程序就不会执行了。
        execlp(buf, buf, (char*)0);
        cout << "couldn't execute: " << buf << endl;
        exit(127);
    }

    if((pid = waitpid(pid, &status, 0)) < 0)
    {
        cout << "waitpid error!\n";
    }
    cout << "%%%%\n"; 
}



int main(int argc, char* argv[])
{
    //判断入参个数是否为2
    // if(argc != 2)
    // {
    //     cout << "The number of argc is not equal to 2! \n";
    //     exit(1);
    // }
    //列出目录项
    // testDir(argv[1]);

    //测试IO输入输出
    // testIO();

    //测试信号signal
    testSignal();
    
    exit(0);

}