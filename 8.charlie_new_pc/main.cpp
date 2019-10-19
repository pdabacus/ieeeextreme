#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

int max_sum(std::vector< std::vector<int> > nums, int total) {
    return total;
}

int main(int argc, char* argv[]) {

    std::vector< std::vector<int> > nums;
    int total = 60;
    std::vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(100);
    nums.push_back(a);

    std::vector<int> b;
    b.push_back(0);
    b.push_back(10);
    b.push_back(50);
    nums.push_back(b);

    std::vector<int> c;
    c.push_back(0);
    c.push_back(10);
    c.push_back(50);
    nums.push_back(c);

    printf("%d\n", max_sum(nums, total));
    return 0;
}
