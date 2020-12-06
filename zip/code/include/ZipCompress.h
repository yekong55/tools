#ifndef __ZIPCOMPRESS__H__
#define __ZIPCOMPRESS__H__

#include <iostream>
#include "Compress.h"

using namespace std;

class ZipCompress : ICompress
{

public:
    ZipCompress();
    ~ZipCompress();

    //压缩接口
    virtual int compress(string& srcFilename, string& dstFilename);
    const int HEADERSIZE = 4;

private:

};



































#endif