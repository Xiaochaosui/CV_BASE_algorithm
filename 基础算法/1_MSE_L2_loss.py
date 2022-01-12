# -*- coding: utf-8 -*- 
# @Time    : 2022/1/7 16:46
# @Author  : xiaochaosui
# @File    : 1_MSE_L2_loss.py
# @Software: PyCharm
# @Email   : chaosuixiao@gmail.com

'''
均分误差
'''

from  matplotlib import pyplot as plt

def loss_MSE(pred,label):
    n = len(pred)
    sum = 0
    res_sum = []
    for i in range(n):
        diff = (label[i]-pred[i]) ** 2
        sum += diff
        res_sum.append(diff)
    loss = sum / n
    x = pred
    y = res_sum
    plt.plot(x,y)
    plt.show()
    return loss



if __name__ == '__main__':
    pred = [i for i in range(-10000,10001)]
    label = [100 for i in range(-10000,10001)]
    loss_mse = loss_MSE(pred, label)
    print(loss_mse)


