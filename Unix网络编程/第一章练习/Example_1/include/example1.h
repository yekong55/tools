#ifndef __TESTDIR_H__
#define __TESTDIR_H__
#include <sys/wait.h>
#include "common.h"

//列出一个目录下的所有目录项，包括文件，目录
void testDir(char* dir);

//测试IO输入输出
void testIO();

//测试信号signal
void testSignal();

#endif 