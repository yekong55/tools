#include <iostream>
#include <cstring>
#include <dirent.h>
#include "example3.h"

using namespace std;

//信号处理函数
void sigInt(int)
{
    cout << "sigInt()!!!\n";
}

//测试lseek函数功能:会产生空洞文件
void testLseekHoleFile()
{
    char buf1[] = "abcdefghig";
    char buf2[] = "ABCDEFGHIG";

    int fd = creat("testLseekHole.txt", FILE_MODE);
    if(fd < 0)
    {
        cout << "create file failed!\n";
        exit(1);
    }

    size_t len = write(fd, buf1, sizeof(buf1)) ;
    if(len != 11)
    {
        cout << "file: " << __FILE__ << "line: " << __LINE__ << "  function: " << __FUNCTION__<< "  len: " << len << "  write to file failed!\n";
        exit(2);
    }

    if(lseek(fd, 1000, SEEK_SET) == -1)
    {
        cout << "file: " << __FILE__ << "line: " << __LINE__ << "  function: " << __FUNCTION__<< "   lseek failed! \n";
        exit(3);
    }

    if(write(fd, buf2, sizeof(buf2)) != 11)
    {
        cout << "file: " << __FILE__ << "line: " << __LINE__ << "  function: " << __FUNCTION__ << "  len: " << len << "  write to file failed!\n";
        exit(4);
    }

    close(fd);
}

//测试lseek函数功能:不产生空洞文件
void testLseekNoHoleFile()
{
    char buf1[] = "abcdefghig";
    char buf2[] = "ABCDEFGHIG";

    int fd = creat("testLseekNoHole.txt", FILE_MODE);
    if(fd < 0)
    {
        cout << "create file failed!\n";
        exit(1);
    }

    size_t len = write(fd, buf1, sizeof(buf1)) ;
    if(len != 11)
    {
        cout << "file: " << __FILE__ << "line: " << __LINE__ << "  function: " << __FUNCTION__<< "  len: " << len << "  write to file failed!\n";
        exit(2);
    }

    if(lseek(fd, 10, SEEK_SET) == -1)
    {
        cout << "file: " << __FILE__ << "line: " << __LINE__ << "  function: " << __FUNCTION__<< "   lseek failed! \n";
        exit(3);
    }

    if(write(fd, buf2, 1001) <= 0)
    {
        cout << "file: " << __FILE__ << "line: " << __LINE__ << "  function: " << __FUNCTION__ << "  len: " << len << "  write to file failed!\n";
        exit(4);
    }

    close(fd);
}

int main(int argc, char* argv[])
{
    //测试lseek函数功能:产生空洞文件
    testLseekHoleFile();

    //测试lseek函数功能：不产生空洞文件
    testLseekNoHoleFile();

    exit(0);

}