//
// Created by yalin.han on 2017/8/23.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <io.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fileapi.h>
#include "FileOrDirectory.h"


void FileOrDirectory::test() {
    std::ifstream ifstream;
    ifstream.open("hehe1111.txt", std::ios::in);
    if (!ifstream.is_open()) {
        std::cout << "no" << std::endl;
    }
}

void FileOrDirectory::test2() {
    char name[256], title[256];

    std::cout << "Please, enter your name: ";
    std::cin.getline(name, 256);

    std::cout << "Please, enter your favourite movie: ";
    std::cin.getline(title, 256);

    std::cout << name << "'s favourite movie is " << title;
}

void FileOrDirectory::test3() {
    std::fstream f("d:\\try1111.txt", std::ios::out);
    f << 1234 << ' ' << 3.14 << 'A' << "How are you"; //写入数据
    f.close();
    f.open("d:\\try.txt", std::ios::in);
    int i;
    double d;
    char c;
    char s[20];
    f >> i >> d >> c;//读取数据
    f.getline(s, 3);
    std::cout << i << std::endl;//显示各数据
    std::cout << d << std::endl;
    std::cout << c << std::endl;
    std::cout << s << std::endl;
    f.close();
}

void FileOrDirectory::test4() {
    Info info;
    std::string content = "morgan 2882222 2223333";
    std::istringstream stream(content);
    stream >> info.name >> info.value >> info.value2;
    std::cout << info.name << " " << info.value << " " << info.value2
              << std::endl;
}

void FileOrDirectory::test5() {
    std::ostringstream ostringstream;
    ostringstream << "hehe" << " " << "haha";
    std::cout << ostringstream.str() << std::endl;
}

void FileOrDirectory::test6() {
//    char array[512];
    char *array = new char[512];
    memset(array, 0, 512);
    std::ifstream is("D://try.txt", std::ios::in | std::ios::binary);
    if (is) {
        is.read(array, 20);
    }
    is.close();
    std::cout << array << std::endl;
    delete[] array;
    array = nullptr;
}


/**
 * 判断目录是否存在，不存在不会创建新目录
 * @param dir_name
 * @return
 */
bool is_dir_exist(const std::string &dir_name) {
    if (dir_name.empty()) {
        return false;
    }
    return access(dir_name.c_str(), F_OK) == 0 ? true : false;
}

/**
 * 创建目录
 * @param path_name
 * @return
 */
bool MakeDir(const std::string &path_name) {
    std::string value = (mkdir(path_name.c_str()) == 0) ? "succeed" : "fail";
    printf("result:%s\n", value.c_str());
}

/**
 * 删除目录
 * @param dir_name
 * @return
 */
bool DeleteDir(const std::string &dir_name) {
    if (dir_name.empty()) {
        return false;
    }
    std::string result = (rmdir(dir_name.c_str()) == 0) ? "succeed" : "failed";
    printf("result:%s\n", result.c_str());
}


/**
 * 判断文件是否存在，不存在不会创建新文件
 * @param file_name
 * @return
 */
bool is_file_exist(const std::string &file_name) {
    if (file_name.empty()) {
        return false;
    }
    return access(file_name.c_str(), F_OK) == 0 ? true : false;
}

/**
 * 打开并创建文件(写文件)，如果文件存在直接写入内容，如果文件不存在则创建文件再写入
 * 如果文件路径中的目录不存在，则文件流创建失败
 * @param file_name
 * @return
 */
bool MakeFile(const std::string &file_name) {
    std::ofstream ofstream;
    ofstream.open(file_name.c_str(), std::ios_base::app);
    if (ofstream.is_open()) {
        ofstream << "this a test\n";
        ofstream.close();
        return true;
    } else {
        printf("open file failed\n");
        return false;
    }
}

/**
 * 从文件读取数据时，如果文件存在则读取成功，如果文件不存在则读取失败
 * @param file_name
 * @return
 */
bool ReadFile(const std::string &file_name) {
    char array[100];
    memset(array, 0, sizeof(array));//初始化0就是初始化NULL(空字符)，'\0'
    std::ifstream ifstream;
    ifstream.open(file_name, std::ios_base::in | std::ios_base::binary);
    if (ifstream.is_open()) {
        ifstream.getline(array, 100);
        std::cout << array << std::endl;
        ifstream.close();
    } else {
        printf("can not open");
    }
}

/**
 * 删除文件，成功返回0，失败返回-1，具体错误值存在errno中
 * @param file_name
 * @return
 */
bool delete_file(const std::string &file_name) {
    int ret = remove(file_name.c_str());   //成功返回0，失败返回-1
    return (ret == 0) ? true : false;
}








