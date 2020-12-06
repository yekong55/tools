#include "ZipDecommpress.h"
#include <sstream>

using namespace std;

ZipDecommpress::ZipDecommpress()
{
    memset(m_ZipHeader, 0, sizeof(m_ZipHeader));
}

ZipDecommpress::~ZipDecommpress()
{

}


int ZipDecommpress::decompress(string& filename)
{
    if(!boost::filesystem::exists(filename))
    {
        cout << filename << " doesn't  exist!\n";
        return 1;
    }

    // ifstream input(filename);
    // input.read(m_ZipHeader, 4);
    // printf("m_ZipHeader: %x\n", ntohl(*reinterpret_cast<int*>(m_ZipHeader)));

    // input.seekg(38);
    // input.read(m_ZipHeader, 4);
    // printf("m_ZipHeader: %x\n", ntohl(*reinterpret_cast<int*>(m_ZipHeader)));


    //这种解压方式是解压boost压缩的数据，不是常用的zip压缩数据
    // std::stringstream ss_decomp;  
    // boost::iostreams::filtering_istream in;  
    // in.push(boost::iostreams::zlib_decompressor());  
    // //in.push(ss_comp);     //从字符流中解压  
    // in.push(boost::iostreams::file_source(filename));     //从文件中解压  
    // boost::iostreams::copy(in, ss_decomp);  

    std::cout << "decompressor data:" << ss_decomp.str() << std::endl;  


    return 0;
}





































