
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <cstdio>
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "test.pb.h"
 
using namespace std;
int main(int argc, char** argv)
{
    if (argc <2){
        printf("programe savefile\n");
        exit(1);
    }
 
    person c;
    
    //添加学生
    student* t = c.add_member();
    t->set_name("Toy");
    t->set_age(21);
    t->set_sex("boy");
    
    t = c.add_member();
    t->set_name("jack");
    t->set_age(25);
    t->set_sex("boy");
 
    t = c.add_member();
    t->set_name("lili");
    t->set_age(20);
    t->set_sex("girl");
 
 
    //首先将protobuf输出到一个string中
    std::string p;
    google::protobuf::TextFormat::PrintToString(c,&p);
    
    //输出到文件中
    ofstream fout;
    fout.open(argv[1], ios::out| ios_base::ate);
    if (!fout.is_open()){
        fprintf(stderr, "open %s fail\n", argv[1]);
        return -1;
    }
    fout <<p<<endl;
    fout.flush();
    fout.close();
 
    return 0;

}
