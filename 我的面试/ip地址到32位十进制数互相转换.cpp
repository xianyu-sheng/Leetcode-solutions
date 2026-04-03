#include <iostream>
#include <string>
using namespace std;

// 1. 字符串转十进制 (你的原代码，很完美)
unsigned int io_to_dec(const string& str) {
    unsigned int res = 0;
    unsigned int cur_num = 0;
    for (char c : str) {
        if (c == '.') {
            res = (res << 8) | cur_num;
            cur_num = 0;
        } else {
            cur_num = cur_num * 10 + (c - '0');
        }
    }
    res = (res << 8) | cur_num;
    return res;
}

// 2. 十进制转为 IP 地址 (修复了 Bug)
string dec_to_ip(unsigned int num) {
    string ip = "";
    for (int i = 3; i >= 0; i--) {
        // 截断获取当前 8 位
        unsigned int temp = (num >> (i * 8)) & 0xFF;

        // 【修改点 1】: 将 = 改为 ==
        if (temp == 0) {
            ip += "0";
        } else {
            string str = "";
            while (temp) {
                // 【修改点 2】: 去掉 +=，直接用 = 进行前插拼接
                str = (char)('0' + temp % 10) + str;
                temp /= 10;
            }
            ip += str;
        }
        
        // 加上分隔符
        if (i > 0) {
            ip += ".";
        }
    }
    return ip;
}

int main() {
    unsigned int num = 3232235777;
    string ip = "192.168.1.1";
    
    // 应该输出 3232235777
    cout << io_to_dec(ip) << endl; 
    
    // 应该输出 192.168.1.1
    cout << dec_to_ip(num) << endl; 
    
    return 0;
}
