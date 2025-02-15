class ProductOfNumbers {
public:
    vector<int> nums;
    int lastzero;
    ProductOfNumbers() {
        lastzero = -1;
        nums.clear();
    }
    
    void add(int num) {
        if(num == 0){
            nums.push_back(0);
            lastzero = nums.size()-1;
            return;
        }
        if(nums.empty() || nums.back()==0)
            nums.push_back(num);
        else
            nums.push_back(nums.back() * num);

    }
    
    int getProduct(int k) {
        int len = nums.size();
        if(lastzero >= len-k)
            return 0;
        if(k == len)
            return nums[len-1];
        else{
            if(nums[len-k-1] == 0)
                return nums[len-1];
            else
                return nums[len-1]/nums[len-k-1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */