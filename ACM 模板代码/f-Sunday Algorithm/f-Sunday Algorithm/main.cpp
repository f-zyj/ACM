//
//  main.cpp
//  f-Sunday Algorithm
//
//  Created by ZYJ on 16/7/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  BM算法改进的算法：Sunday Algorithm

/*
 *  BM算法优于KMP
 *  SUNDAY 
    算法描述:字符串查找算法中,最著名的两个是KMP算法(Knuth-Morris-Pratt)和BM算法(Boyer-Moore)。两个算法在最坏情 况下均具有线性的查找时间。但是在实用上,KMP算法并不比最简单的c库函数strstr()快多少,而BM算法则往往比KMP算法快上3-5倍。但是BM算法还不是最快的算法,这里介绍一种比BM算法更快一些的查找算法。例如我们要在"substring searching algorithm"查找"search",刚开始时,把子串与文本左边对齐:
    substring searching algorithm search
 *  结果在第二个字符处发现不匹配,于是要把子串往后移动。但是该移动多少呢? 这就是各种算法各显神通的地方了,最简单的做法是移动一个字符位置;KMP是利用已经匹配部分的信息来移动;BM算法是做反向比较,并根据已经匹配的部分来确定移动量。这里要介绍的方法是看紧跟在当前子串之后的那个字符(第一个字符串中的'i')。显然,不管移动多少,这个字符是肯定要参加下一步的比较的,也就是说,如果下一步匹配到了,这个字符必须在子串内。所以,可以移动子串,使子串中的最右边的这个字符与它对齐。现在子串'search'中并不存在'i',则说明可以直接跳过一大片,从'i'之后的那个字符开始作下一步的比较,如下:
    substring searching algorithm search
 *  比较的结果,第一个字符就不匹配,再看子串后面的那个字符,是'r',它在子串中出现在倒数第三位,于是把子串向后移动三位,使两个'r'对齐,如下:
    substring searching algorithm search
 *  这次匹配成功了!回顾整个过程,我们只移动了两次子串就找到了匹配位置, 是不是很神啊?!可以证明,用这个算法,每一步的移动量都比BM算法要大,所以肯定比BM算法更快。
 */

void SUNDAY(char *text, char *patt)
{
    size_t temp[256];
    size_t *shift = temp;
    size_t i, patt_size = strlen(patt), text_size = strlen(text);
    cout << "size : " << patt_size << endl;
    for(i = 0; i < 256; i++)
    {
        *(shift+i) = patt_size + 1;
    }
    for(i = 0; i < patt_size; i++)
    {
        *(shift + (unsigned char)(*(patt+i))) = patt_size-i;    //  shift['s']=6步,shitf['e']=5以此类推
    }
    size_t limit = text_size - patt_size + 1;
    for(i = 0; i < limit; i += shift[text[i + patt_size]])
    {
        if(text[i] == *patt)
        {
            char *match_text = text + i + 1;
            size_t match_size = 1;
            do  //  输出所有匹配的位置
            {
                if(match_size == patt_size)
                {
                    cout << "the NO. is " << i << endl;
                }
            }
            while((*match_text++) == patt[match_size++]);
        }
    }
    cout << endl;
}

int main(void)
{
    char text[100] = "substring searching algorithm search";
    char patt[10] = "search";
    SUNDAY(text, patt);
    return 0;
}