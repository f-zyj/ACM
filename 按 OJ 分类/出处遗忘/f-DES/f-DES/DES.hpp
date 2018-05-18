//
//  DES.hpp
//  f-DES
//
//  Created by ZYJ on 2017/12/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#ifndef DES_hpp
#define DES_hpp

#include <stdio.h>
#include <string>

#define BITS_PER_CHAR   8
#define KEY_SZIE        8
#define SUBKEY_NUM      16
#define SUBKEY_LENGHT   48
#define EXPAND_SIZE     48
#define PC_2_SIZE       48
#define PC_1_SIZE       56
#define BIT_STR_SIZE    64

class DES
{
public:
    DES();
    ~DES();
    
    //  加密函数
    std::string Encrypt(const std::string &plain, const std::string &key);
    //  解密函数
    std::string Decrypt(const std::string &cipher, const std::string &key);
    
private:
    //  生成16个子秘钥
    bool CreateSubKey(const std::string &key, char subKey[SUBKEY_NUM][SUBKEY_LENGHT]);
    
    //  加密8字节数据块
    bool EncryptBlock(std::string &block, char subKey[SUBKEY_NUM][SUBKEY_LENGHT]);
    
    //  解密8字节数据块
    bool DecryptBlock(std::string &block, char subKey[SUBKEY_NUM][SUBKEY_LENGHT]);
    
    /* ************************** 转换工具 ************************** */
    //  PC1转换
    bool PC1_Transform(const std::string &bitStr, std::string &PC1BitStr);
    //  PC2转换
    bool PC2_Transform(const std::string &PC1BitStr, char subKey[SUBKEY_LENGHT]);
    //  IP转换
    bool IP_Transform(std::string &bitStr);
    //  E扩展转换
    bool Expand_Transform(const std::string &halfBitStr, std::string &eBitStr);
    //  S盒转换
    bool SBox_Transform(const std::string &eBitStr, std::string &halfBitStr);
    //  单纯转换
    bool Permute_Transform(std::string &halfBitStr);
    //  IP逆转
    bool IP_1_Transform(std::string &bitStr);
    
    /* ************************** 基础工具 ************************** */
    //  8位char转64Bit
    bool Char8ToBit64(const std::string &str, std::string &bitStr);
    //  64Bit转8位char
    bool Bit64ToChar8(const std::string &bitStr, std::string &str);
    //  异或函数
    bool XOR(std::string &strFirst, const std::string &strSecond, size_t num);
    //  循环左移函数
    bool LeftCycle(std::string &str, size_t beginSection, size_t endSection, size_t step);
    
    /* ************************** 生成秘钥需要的表 ************************** */
    //  压缩换位去掉每个字节的第8位，用作奇偶校检，基本上第8位可忽略
    static char PC1_Table[PC_1_SIZE];
    //  左循环距离表
    static char Move_Table[SUBKEY_NUM];
    //  选择其中的某些位将其减少到48位
    static char PC2_Table[PC_2_SIZE];
    
    /* ************************** 加密或解密需要的表 ************************** */
    //  表中的数值表示输入为被置换后的新位置
    static char IP_Table[BIT_STR_SIZE];
    //  通过重复某些位将32位的右半部分按照表扩展成48位
    static char Expand_Table[EXPAND_SIZE];
    //  单纯置换表
    static char Permute_Table[BIT_STR_SIZE / 2];
    //  逆置换表
    static char IP_1_Table[BIT_STR_SIZE];
    //  S置换盒
    static char SBox_Table[KEY_SZIE][4][16];
};

#endif /* DES_hpp */
