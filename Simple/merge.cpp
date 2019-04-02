//88. 合并两个有序数组
//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//说明:
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

//方法一：直接排序法
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=0; i<n; i++)
        {
            nums1[m+i] = nums2[i];  //直接把nums2加到nums1的末尾。
        }
        sort(nums1.begin(),nums1.end());    //对nums1进行排序。
    }
};


//方法二：后插排序法
/*因为nums1后面是没有数的，可以用后插法。当原来nums1的数没有插入结束，分别从两个数组最后取出来数作比较，如果大的就把他放到nums1的最后。
放置之后，nums1的指针往前移，取出来放的数组指针也往前移。一直到nums2的数都插入到nums1，相当于n<0。
在这个过程中，如果原来nums1的数被插入完了，相当于nums1剩下的没有被赋值的前面几位都是nums2剩下的数。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m-- + n-- - 1;    //定义nums1在m+n-1处的指针
        while (n >= 0)  //当nums2的数没有被插入结束时执行
        {//nums1从后往前赋值，这里可以展开写。
            nums1[len--] = (m >= 0 && nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
        }
    }
};

