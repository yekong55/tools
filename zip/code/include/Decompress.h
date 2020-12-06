#ifndef __DECOMPRESS__H__
#define __DECOMPRESS__H__

#include <iostream>
#include <sstream>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/filesystem/operations.hpp>


using namespace std;

class IDecompress
{

public:
    IDecompress(){};
    ~IDecompress(){};

    //解压缩接口
    virtual int decompress(string& filename) = 0;

private:
    IDecompress(const IDecompress& other);
    IDecompress& operator=(const IDecompress& other);
};






























#endif















