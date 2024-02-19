#ifndef SCHEDULE_SHELL
#define SCHEDULE_SHELL

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <stdexcept>
#include <chrono>

#include "./Field.h"
#include "./Ellc.h"
#include "./Ecc.h"

std::vector<std::string> readed(std::istream& in_0);

void shell();

void analysis(std::vector<std::string> readed);

void list();

void list(int i);





void shell()
{

    std::cout << "fino game preshell start up" << std::endl;

/*
    auto now = std::chrono::system_clock::now();
    auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
    std::cout << "当前时间戳为：" << timestamp << " 秒" << std::endl;
*/

    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    std::tm local_time;
    localtime_s(&local_time, &time);

    std::cout << "当前时间是：";
    std::cout << local_time.tm_year + 1900 << "-";     // 年份是从 1900 开始的
    std::cout << local_time.tm_mon + 1 << "-";     // 月份从 0 开始
    std::cout << local_time.tm_mday << " ";        // 日期
    std::cout << local_time.tm_hour << ":";        // 小时
    std::cout << local_time.tm_min << ":";         // 分钟
    std::cout << local_time.tm_sec << std::endl;       // 秒



    while (true)
    {
        std::vector<std::string> rd;

        std::cout << ANSI_COLOR_GREEN;
        std::cout << "preShell<:";
        std::cout << ANSI_COLOR_RESET;

        rd = readed(std::cin);
        //std::cout << rd[0] << "ee" << rd[1];
        analysis(rd);
        std::cout << std::endl;
    
    }



















}


std::vector<std::string> readed(std::istream& in_0)
{


    std::vector<std::string> readed;
    std::string rd_0;

    getline(in_0, rd_0);



    std::string p;

    for (int i = 0; i < rd_0.size(); i++)
    {


        if (rd_0[i] != ' ') { p.push_back(rd_0[i]); }
        else { readed.push_back(p); p = ""; }


    }
    readed.push_back(p); p = "";


    return readed;

}

void analysis(std::vector<std::string> readed)
{
    if (readed[0]=="") { ; }


    else if (readed[0] == "list") {
        if (readed.size()==1) {
            list();
        }
        else if (readed.size() == 2 && readed[1] == "-a") {
            list(1);
        }
        else std::cout << "list 指令参数错误。详细参数请使用 list -a 进一步查阅。";
    }


    else if (readed[0] == "eccseek") {
        if (readed.size() == 3) { int a; int b; bool key=true;
            try {
                int a_pt = stoi(readed[1]);
                a = a_pt;
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "无效的参数错误: " << e.what() << std::endl;
                key = false;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "超出范围错误: " << e.what() << std::endl;
                key = false;
            }
            if (!key) { return; }
            try {
                int b_pt = stoi(readed[2]);
                b = b_pt;
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "无效的参数错误: " << e.what() << std::endl;
                key = false;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "超出范围错误: " << e.what() << std::endl;
                key = false;
            }
            if (!key) { return; }
            pointSeek(a, b);
        }
        else std::cout << "eccseek 指令参数错误。详细参数请使用 list -a 进一步查阅。";
    }


    else if (readed[0] == "eccmult") {
        if (readed.size() == 1) {
            Ellc x; pointMult(x);
        }
        else std::cout << "eccmult 指令参数错误。详细参数请使用 list -a 进一步查阅。";
    }


    else { std::cout << "不存在指令"; }
}

void list()
{

    std::cout << "指令菜单：" << std::endl;
    std::cout << "|- list" << "     显示指令菜单" << std::endl;
    std::cout << "|  list -a" << "      显示指令菜单包括参数" << std::endl;
    std::cout << "|- eccseek" << "      进行ECC计算" << std::endl;
    std::cout << "|- eccmult" << "      进行ECC乘法计算" << std::endl;
    std::cout << "|- exit" << "      退出";



}

void list(int i)
{
    ;

}

#endif
