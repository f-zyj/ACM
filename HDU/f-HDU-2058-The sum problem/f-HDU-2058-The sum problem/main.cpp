//
//  main.cpp
//  f-HDU-2058-The sum problem
//
//  Created by ZYJ on 16/6/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    long long N, M;
    while (std::cin >> N >> M && N != 0 && M != 0)
    {
        long long i, k, sum = 0;
        for (i = 1; i <= N; i++)
        {
            sum = i;
            for (k = i + 1; k <= N && sum < M; k++)
            {
                sum += k;
            }
            if (sum == M)
            {
                std::cout << '[' << i << ',' << k - 1 << ']' << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


//    long long n,m,i,k;
//    while(scanf("%I64d%I64d",&n,&m)!=EOF&&n!=0&&m!=0)
//    {
//        int sum=0;
//        for(i=1;i<=n;i++)
//        {
//            k=i;
//            for(i=k;i<=n;i++)
//            {
//                sum+=i;
//                if(sum==m)
//                {
//                    printf("[%I64d,%I64d]\n",k,i);
//                    break;
//                }
//            }
//        }
//        printf("[%I64d,%I64d]\n",m,m);
