//
//  main.cpp
//  f-DES(C)
//
//  Created by HHH on 2017/12/6.
//  Copyright © 2017年 HHH. All rights reserved.
//

#include <cstdio>
#include <cstring>

//  IP 初始置换表
const int IP_Init_Table[64] =
{
    58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17,  9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
};

//  E 扩展表
const int E_Table[48] =
{
    32,  1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,
     8,  9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32,  1
};

//  P 盒
const int P_Table[32] =
{
    16, 7, 20, 21, 29, 12, 28, 17,  1, 15, 23, 26,  5, 18, 31, 10,
     2, 8, 24, 14, 32, 27,  3,  9, 19, 13, 30,  6, 22, 11,  4, 25
};

//  IP 逆置换表
const int IPR_Table[64] =
{
    40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41,  9, 49, 17, 57, 25
};

//  密钥第一次置换表
const int PC1_Table[56] =
{
    57, 49, 41, 33, 25, 17,  9,  1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27, 19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,  7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29, 21, 13,  5, 28, 20, 12,  4
};

//  密钥第二次置换表
const int PC2_Table[48] =
{
    14, 17, 11, 24,  1,  5,  3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8, 16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
};

//  S 盒
const int S_Box[8][4][16] =
{
    //  s1
    14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
    0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
    4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
    15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13,
    //  s2
    15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
    3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
    0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
    13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9,
    //  s3
    10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
    13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
    13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
    1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,
    //  s4
    7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
    13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
    10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
    3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,
    //  s5
    2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
    14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
    4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
    11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3,
    //  s6
    12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
    10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
    9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
    4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13,
    //  s7
    4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
    13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
    1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
    6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,
    //  s8
    13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,  
    1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
    7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
    2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
};

/*
 *  类型转换函数 I
 *  将 char 型转化为二进制形式
 *  8 * sizeof(char) = 8(位) 8 个字符 64 位
 */
void CharToBit(const char input[], int output[], int bits)
{
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            output[7 * (j + 1) - i + j] = (input[j] >> i) & 1;
        }
    }
}

/*
 *  类型转换函数 II
 *  将二进制形式转化为 char 型
 */
void BitToChar(const int intput[], char output[], int bits)
{
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            output[j] = output[j] * 2 + intput[i + 8 * j];
        }
    }
}

/*
 *  异或函数
 *  将数组 INA 和 INB 进行异或操作，并且保存在 INA 中
 */
void Xor(int *INA, int *INB, int len)
{
    for (int i = 0; i<len; i++)
    {
        *(INA + i) = *(INA + i) ^ *(INB + i);
    }
}

/*
 *  IP 初始置换函数
 *  IP 根据 IP 初始置换表进行初始置换
 */
void IP_Init_Rep(const int input[64], int output[64], const int table[64])
{
    for (int i = 0; i < 64; i++)
    {
        output[i] = input[table[i] - 1];
    }
}

/*
 *  E 扩展置换函数
 *  根据 E 扩展表进行扩展
 */
void E_Extend(const int input[32], int output[48], const int table[48])
{
    for (int i = 0; i < 48; i++)
    {
        output[i] = input[table[i] - 1];
    }
}

/*
 *  P 置换函数
 *  根据 P 盒进行置换
 */
void P_Rep(const int input[32], int output[32], const int table[32])
{
    for (int i = 0; i < 32; i++)
    {
        output[i] = input[table[i] - 1];
    }
}

/*
 *  IP 逆置换函数
 *  IP 根据 IP 逆置换表进行置换
 */
void IP_Inv_Rep(const int input[64], int output[64], const int table[64])
{
    for (int i = 0; i < 64; i++)
    {
        output[i] = input[table[i] - 1];
    }
}

/*
 *  密匙第一次置换函数
 *  根据密匙第一次置换表进行置换
 */
void PC_1(const int input[64], int output[56], const int table[56])
{
    for (int i = 0; i < 56; i++)
    {
        output[i] = input[table[i] - 1];
    }
}

/*
 *  密匙第二次置换函数
 *  根据密匙第二次置换表进行置换
 */
void PC_2(const int input[56], int output[48], const int table[48])
{
    for (int i = 0; i < 48; i++)
    {
        output[i] = input[table[i] - 1];
    }
}

/*
 *  S 盒压缩函数
 *  根据 8 个 S 盒进行压缩
 */
void S_Comp(const int input[48], int output[32], const int table[8][4][16])
{
    int INT[8];
    for (int i = 0, j = 0; i < 48; i = i + 6)
    {
        INT[j] = table[j][(input[i] << 1)
               + (input[i + 5])][(input[i + 1] << 3)
               + (input[i + 2] << 2)
               + (input[i + 3] << 1)
               + (input[i + 4])];
        j++;
    }
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            output[3 * (j + 1) - i + j] = (INT[j] >> i) & 1;
        }
    }
}

/*
 *  轮迭代函数
 *  DES 核心迭代部分
 */
void F_func(const int input[32], int output[32], int subKey[48])
{
    int len = 48;
    int temp0[48] = {0};
    int temp1[32] = {0};
    E_Extend(input, temp0, E_Table);
    Xor(temp0, subKey, len);
    S_Comp(temp0, temp1, S_Box);
    P_Rep(temp1, output, P_Table);
}

/*
 *  密匙循环左移函数
 *  密匙在不同轮数都要进行不同的左移操作
 */
void RotateL(const int input[28], int output[28], int leftCount)
{
    int len = 28;
    for (int i = 0; i < len; i++)
    {
        output[i] = input[(i + leftCount) % len];
    }
}

/*
 *  子密匙生成函数
 *  生成 subKey，在第 1、2、9、16 轮循环左移 1 位，其他轮循环左移 2 位
 */
void subKey_fun(const int input[64], int subKey[16][48])
{
    int loop0 = 1, loop1 = 2;
    int c[28], d[28];
    int pc_1[56] = {0};
    int pc_2[16][56] = {0};
    int rotatel_c[16][28] = {0};
    int rotatel_d[16][28] = {0};
    
    PC_1(input, pc_1, PC1_Table);
    for (int i = 0; i < 28; i++)
    {
        c[i] = pc_1[i];
        d[i] = pc_1[i + 28];
    }
    
    int leftCount = 0;
    for (int i = 1; i < 17; i++)
    {
        if (i == 1 || i == 2 || i == 9 || i == 16)
        {
            leftCount += loop0;
            RotateL(c, rotatel_c[i - 1], leftCount);
            RotateL(d, rotatel_d[i - 1], leftCount);
        }
        else
        {
            leftCount += loop1;
            RotateL(c, rotatel_c[i - 1], leftCount);
            RotateL(d, rotatel_d[i - 1], leftCount);
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            pc_2[i][j] = rotatel_c[i][j];
            pc_2[i][j + 28] = rotatel_d[i][j];
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        PC_2(pc_2[i], subKey[i], PC2_Table);
    }
}

/*
 *  DES 加密函数
 *  传入明文 input 和密匙 inKey，获取 64 位二进制密文 output
 */
void DES_Efun(const char input[8], char inKey[8], int output[64])
{
    int ip[64] = {0};
    int output_1[64] = {0};
    int subKeys[16][48];
    int chartobit[64] = {0};
    int key[64];
    int l[17][32], r[17][32];
    
    CharToBit(input, chartobit, 8);
    IP_Init_Rep(chartobit, ip, IP_Init_Table);
    CharToBit(inKey, key, 8);
    subKey_fun(key, subKeys);
    
    for (int i = 0; i < 32; i++)
    {
        l[0][i] = ip[i];
        r[0][i] = ip[32 + i];
    }
    for (int j = 1; j < 16; j++)    //  15 轮迭代
    {
        for (int k = 0; k < 32; k++)
        {
            l[j][k] = r[j - 1][k];
        }
        F_func(r[j - 1], r[j], subKeys[j - 1]);
        Xor(r[j], l[j - 1], 32);
    }
    
    int t = 0;
    for (t = 0; t < 32; t++)        //  第 16 轮迭代
    {
        r[16][t] = r[15][t];
    }
    F_func(r[15], l[16], subKeys[15]);
    Xor(l[16], l[15], 32);
    
    for (t = 0; t < 32; t++)
    {
        output_1[t] = l[16][t];
        output_1[32 + t] = r[16][t];
    }
    IP_Inv_Rep(output_1, output, IPR_Table);
}

/*
 *  DES 解密函数
 *  传入 64 位二进制密文 input 和密匙 inKey 获取明文 output
 */
void DES_Dfun(const int input[64], char inKey[8], char output[8])
{
    int ip[64] = {0};
    int output_1[64] = {0};
    int output_2[64] = {0};
    int subKeys[16][48];
    int key[64];
    int l[17][32], r[17][32];
    
    IP_Init_Rep(input, ip, IP_Init_Table);
    CharToBit(inKey, key, 8);
    subKey_fun(key, subKeys);
    for (int i = 0; i < 32; i++)
    {
        l[0][i] = ip[i];
        r[0][i] = ip[32 + i];
    }
    for (int j = 1; j < 16; j++)    //  15 轮迭代
    {
        for (int k = 0; k < 32; k++)
        {
            l[j][k] = r[j - 1][k];
        }
        F_func(r[j - 1], r[j], subKeys[16 - j]);
        Xor(r[j], l[j - 1], 32);
    }
    
    int t = 0;
    for (t = 0; t < 32; t++)        //  第 16 轮迭代
    {
        r[16][t] = r[15][t];
    }
    F_func(r[15], l[16], subKeys[0]);
    Xor(l[16], l[15], 32);
    
    for (t = 0; t < 32; t++)
    {
        output_1[t] = l[16][t];
        output_1[32 + t] = r[16][t];
    }
    IP_Inv_Rep(output_1, output_2, IPR_Table);
    BitToChar(output_2, output, 8);
}

int output[64] = {0};
char A[9] = {0};
char B[9] = {0};

int main()
{
    printf("Please enter the plaintext(8 bytes):\n");
    scanf("%s", A);
    printf("Please enter the key(8 bytes):\n");
    scanf("%s", B);
    
    DES_Efun(A, B, output);
    
    putchar(10);
    printf("Encryption\n");
    for (int i = 0; i < 64; i++)
    {
        printf("%d", output[i]);
        if ((i + 1) % 8 == 0)
        {
            putchar(10);
        }
        else if ((i + 1) % 4 == 0)
        {
            putchar(' ');
        }
    }
    
    putchar(10);
    printf("Decryption\n");
    
    DES_Dfun(output, B, A);
    
    for (int i = 0; i < 8; i++)
    {
        printf("%c", A[i]);
    }
    putchar(10);
    
    return 0;
}
