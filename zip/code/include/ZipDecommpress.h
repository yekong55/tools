#ifndef __ZIPDECOMPRESS__H__
#define __ZIPDECOMPRESS__H__

#include<iostream>
#include "Decompress.h"


class ZipDecommpress : public IDecompress
{

public:
    ZipDecommpress();
    ~ZipDecommpress();

    virtual int decompress(string& filename);

private:

};








































#endif