/*
# -*- coding: utf-8 -*- 
# @Time    : 2022/1/12 10:07
# @Author  : xiaochaosui
# @File    : 3_LBP.py
# @Software: PyCharm
# @Email   : chaosuixiao@gmail.com
'''
*/
/*
特征提取算法
LBP（Local Binary Patterns，局部二值模式）是提取局部特征作为判别依据的。LBP方法显著的优点是对光照不敏感，但是依然没有解决姿态和表情的问题。不过相比于特征脸方法，LBP的识别率已经有了很大的提升。在[1]的文章里，有些人脸库的识别率已经达到了98%+。
https://blog.csdn.net/peng_peng123/article/details/51755119 学习来源
基本思想是：用中心像素的灰度值作为阈值，与它的邻域相比较得到的二进制码来表述局部纹理特征。
'''
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   system("chcp 65001");
   cout<<"aa"<<endl;
   system("pause");
   return 0;
}
