#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// 判断文件是否存在
bool file_exist(const char* file_name)
{

    fstream fin(file_name, ios::in);
    bool exist = false;
    if (fin)
    {

        exist = true;
        fin.close();
    }
    return exist;
}

int main(int argc, char* argv[])
{
    const string space = " ";
    string file_path = argv[0];
    string file_dir = file_path.substr(0, file_path.find_last_of("\\") + 1); // 当前exe文件所在目录
    stringstream command;
    command << file_dir << "clang-format.exe";

    // 如果项目目录存在.clang-format或_clang-format
    // VS的调用路径在项目目录, 所以使用相对路径
    if (file_exist(".clang-format") || file_exist("_clang-format"))
    {

        for (int i = 1; i < argc; i++)
        {

            string arg = argv[i];
            command << space << arg;
        }
    }
    else
    {
        string format_file(file_dir + "clang-format.txt");
        command << space << "-style=file:" << format_file;
        for (int i = 1; i < argc; i++)
        {
            string arg = argv[i];
            if (arg.find("-style=") == string::npos)
            {
                // 去掉VS传的-style和-fallback-style参数
                command << space << arg;
            }
        }
    }

    return system(command.str().data()); // 将clang-format的结束状态返回, 提供给VS结果信息
}
