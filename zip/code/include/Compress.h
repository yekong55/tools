#ifndef __DECOMPRESS__H__
#define __DECOMPRESS__H__
#include <iostream>
#include <cstring>

using namespace std;


class ICompress
{
public:
    ICompress() {}
    ~ICompress(){}

    //压缩接口
    virtual int compress(string& srcFilename, string& dstFilename) = 0;

private:
    ICompress(const ICompress& other);
    ICompress& operator=(const ICompress& other);

};























#endif




















