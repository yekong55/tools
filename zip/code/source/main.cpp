#include <iostream>
#include <sstream>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include "../include/Decompress.h"
#include "../include/ZipDecommpress.h"




int main()
{
    string filename("/home/yekong/tmp/test.zip");
    IDecompress* decompress = new ZipDecommpress();
    decompress->decompress(filename);
    return 0;
}























