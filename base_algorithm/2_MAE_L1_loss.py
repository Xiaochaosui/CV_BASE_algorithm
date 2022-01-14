# -*- coding: utf-8 -*- 
# @Time    : 2022/1/7 17:31
# @Author  : xiaochaosui
# @File    : 2_MAE_L1_loss.py
# @Software: PyCharm
# @Email   : chaosuixiao@gmail.com
'''

平均绝对误差
'''

from  matplotlib import pyplot as plt

def loss_MAE_L1(pred,label):
    n = len(pred)
    sum = 0
    res_sum = []
    for i in range(n):
        diff  = abs(label[i]-pred[i])
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
    loss_mae = loss_MAE_L1(pred, label)
    print(loss_mae)