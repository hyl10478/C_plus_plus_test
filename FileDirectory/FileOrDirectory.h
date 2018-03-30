//
// Created by yalin.han on 2017/8/23.
//

#ifndef PRO1_FILEORDIRECTORY_H
#define PRO1_FILEORDIRECTORY_H

struct Info {
    std::string name;
    int value;
    int value2;
};

class FileOrDirectory {
public:
    void test();

    void test2();

    void test3();

    void test4();

    void test5();

    void test6();

    void test7();

};

extern bool is_file_exist(const std::string &file_name);

extern bool is_dir_exist(const std::string &dir_name);

extern bool is_file_exist2(const std::string &file_name);

extern bool MakeDir(const std::string &path_name);

extern bool MakeFile(const std::string &file_name);

extern bool DeleteDir(const std::string &dir_name);

extern bool ReadFile(const std::string &file_name);

extern bool delete_file(const std::string &file_name);
#endif //PRO1_FILEORDIRECTORY_H
