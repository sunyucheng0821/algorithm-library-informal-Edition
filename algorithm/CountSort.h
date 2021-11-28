class CountSortclass
{
public:
    int* countSort(int* data, int length)
    {
        if (data == nullptr || length <= 0)
            return nullptr;

        //确定数列最大值
        int max = data[0];
        int min = data[0];
        for (int i = 1; i < length; ++i)
        {
            if (data[i] > max)
                max = data[i];
            if (data[i] < min)
                min = data[i];
        }
        int d = max - min;
        // 确定统计数组长度并进行初始化
        int* coutData = new int[d + 1];
        for (int i = 0; i <= d; ++i)
            coutData[i] = 0;
        // 遍历数组，统计每个数出现的次数
        for (int i = 0; i < length; ++i)
                ++coutData[data[i] - min];
        // 统计数组做变形，后面的元素等于前面的元素之和
        for (int i = 1; i <= d; ++i)
            coutData[i] += coutData[i - 1];
    // 倒序遍历原始数列，从统计数组找到正确的位置，输出到结果数组
        int* sortedArray = new int[length];
        for (int i = length - 1; i >= 0; i--)
        {
            sortedArray[coutData[data[i] - min] - 1] = data[i];        // 找到data[i]对应的coutData的值，值为多少，表示原来排序多少，（因为从1开始，所以再减1）
            coutData[data[i] - min]--;        // 然后将相应的coutData的值减1，表示下次再遇到此值时，原来的排序是多少。
        }
        return sortedArray;
    }
};