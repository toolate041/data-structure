#include <iostream>
using namespace std;

int main()
{
    int n, k, t;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;
    int indexMax[100]; // 每个块的最大值
    for (int i = 0; i < k; i++)
    {
        cin >> indexMax[i];
    }

    int blockSize = n / k; // 每块大小
    int indexStart[100];   // 每块起始位置
    for (int i = 0; i < k; i++)
    {
        indexStart[i] = i * blockSize;
    }

    cin >> t;
    while (t--)
    {
        int target;
        cin >> target;

        int blockIdx = -1;
        int cnt = 0;

        // 索引表顺序查找
        for (int i = 0; i < k; i++)
        {
            cnt++;
            if (target <= indexMax[i])
            {
                blockIdx = i;
                break;
            }
        }

        if (blockIdx == -1)
        {
            cout << "error" << endl;
            continue;
        }

        // 块内顺序查找
        int found = 0;
        int start = indexStart[blockIdx];
        int end = start + blockSize;
        for (int i = start; i < end; i++)
        {
            cnt++;
            if (arr[i] == target)
            {
                cout << i + 1 << "-" << cnt << endl;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            cout << "error" << endl;
        }
    }

    return 0;
}