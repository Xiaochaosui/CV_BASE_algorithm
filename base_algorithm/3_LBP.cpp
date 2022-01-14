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

#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
#include <fstream>
using namespace std;


//原始LBP特征计算
template <typename _tp>
void getOriginLBPFeature(cv::Mat _src,cv::Mat dst)
{
    cv::Mat src = _src;
    
    for(int i=1;i<src.rows-1;i++)
    {
        for(int j=1;j<src.cols-1;j++)
        {
            _tp center = src.at<_tp>(i,j);
            unsigned char lbpCode = 0;
            lbpCode |= (src.at<_tp>(i-1,j-1) > center) << 7;
            lbpCode |= (src.at<_tp>(i-1,j  ) > center) << 6;
            lbpCode |= (src.at<_tp>(i-1,j+1) > center) << 5;
            lbpCode |= (src.at<_tp>(i  ,j+1) > center) << 4;
            lbpCode |= (src.at<_tp>(i+1,j+1) > center) << 3;
            lbpCode |= (src.at<_tp>(i+1,j  ) > center) << 2;
            lbpCode |= (src.at<_tp>(i+1,j-1) > center) << 1;
            lbpCode |= (src.at<_tp>(i  ,j-1) > center) << 0;
            dst.at<uchar>(i-1,j-1) = lbpCode;
        }
    }
}

void test1()
{
   string img_file ;
   img_file = "D:\\xcsy\\dataset\\coco128\\images\\train2017\\000000000436.jpg";
   cv::Mat img = cv::imread(img_file);
   // cout<<img<<endl;
   cv::Mat gray_img,res;
   cv::cvtColor(img,gray_img,cv::COLOR_BGR2GRAY);
   res.create(gray_img.rows-2,gray_img.cols-2,CV_8UC1);
   //  cv::Mat dst = _dst;
   res.setTo(0);
   
   // cout<<img.rows<<","<<img.cols<<endl;
   getOriginLBPFeature<uchar>(gray_img,res);
   cv::imshow("x",img);
   cv::imshow("a",res);
   cv::waitKey();
   // cout<<gray_img.at<uchar>(0,0)<<endl;
}


int main()
{
   system("chcp 65001");
   test1();
   // unsigned char a;
   
   // a = true << 1;
   // cout<<a<<endl;
   system("pause");
   return 0;
}
