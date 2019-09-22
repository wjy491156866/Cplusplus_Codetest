//0交换排序
//长度为n的数组乱序存放着0至n-1. 现在只能进行0与其他数的交换，完成以下函数

/**
 * 交换数组里n和0的位置
 * array: 存储[0-n)的数组
 * len: 数组长度
 * n: 数组里要和0交换的数
 */
extern void swap_with_zero(int* array, int len, int n);

class Solution {
public:
    /**
     * 调用方法swap_with_zero来对array进行排序
     */
    void sort(int* array, int len) {
        if (len <= 1)    return;
        for (int i=len-1; i>0; --i)
        {
            swap_with_zero(array, len, array[i]);    //先把最后的数和0换了
            int max = array[i];
            for (int j=i; j>=0; --j)    //找最大的数
            {
                if (array[j] > max)
                {
                    max = array[j];
                }
            }
            swap_with_zero(array, len, max);        //把最大数和0交换，最大数保持在最后
        }
    }
};
