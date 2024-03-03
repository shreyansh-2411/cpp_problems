#include <iostream>
#include <stack>
using namespace std;

void prevGreater(vector<int> height, vector<int> &prevGreatest)
{
    stack<int> s;
    s.push(0);
    prevGreatest[0] = -1;
    for (int i = 1; i < height.size(); i++)
    {
        while (!s.empty() && height[i] >= height[s.top()])
        {
            s.pop();
        }
        if (s.empty())
            prevGreatest[i] = -1;
        else
            prevGreatest[i] = s.top();
        s.push(i);
    }
}

void nextGreatest(vector<int> height, vector<int> &nextGreater)
{
    stack<int> s;
    int n = nextGreater.size();
    s.push(n - 1);
    nextGreater[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && height[i] >= height[s.top()])
        {
            s.pop();
        }
        if (s.empty())
            nextGreater[i] = -1;
        else
            nextGreater[i] = s.top();
        s.push(i);
    }
}

int trap(vector<int> &height)
{
    vector<int> prevGreatest(height.size());
    vector<int> nextGreater(height.size());
    prevGreater(height, prevGreatest);
    nextGreatest(height, nextGreater);
    int water = 0;
    for (int i = 0; i < height.size(); i++)
    {
        if (prevGreatest[i] == -1 || nextGreater[i] == -1)
            continue;
        int waterHeight = min(height[nextGreater[i]], height[prevGreatest[i]]);
        water += (nextGreater[i] - prevGreatest[i] - 1) * waterHeight;
        int temp = nextGreater[i];
        int k = prevGreatest[i] + 1;
        while (k < temp)
        {
            water = water - height[k];
            height[k] = waterHeight;
            k++;
        }
        i = nextGreater[i] - 1;
    }
    return water;
}

int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    cout << trap(arr);
}