#include <iostream>
#include <fstream>
using namespace std;
 
int fstream_test(const char* filename, std::string& file_content) 
{
    fstream out(filename);
    if (out.is_open()) 
   {
        cout << "the file " << filename << " is created" << endl;
        getline(out,file_content);
        out.close();
		return 0;
    }
	return 1;
}

