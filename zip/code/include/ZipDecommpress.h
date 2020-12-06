#ifndef __ZIPDECOMPRESS__H__
#define __ZIPDECOMPRESS__H__

#include<iostream>
#include <stdlib.h>
#include<boost/iostreams/device/file.hpp>
#include <arpa/inet.h>
#include "Decompress.h"

class ZipDecommpress : public IDecompress
{

public:
    ZipDecommpress();
    ~ZipDecommpress();

    virtual int decompress(string& filename);

private:
    char m_ZipHeader[5];    //用于存储zip头

};








































#endif