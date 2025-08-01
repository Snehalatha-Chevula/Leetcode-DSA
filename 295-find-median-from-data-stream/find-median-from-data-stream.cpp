class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    MedianFinder() {
        while(!maxi.empty())
            maxi.pop();
        while(!mini.empty())
            mini.pop();
    }
    
    void addNum(int num) {
        if(maxi.empty()){
            maxi.push(num);
            return;
        }
        if(maxi.size() == mini.size()){
            if(num > mini.top()){
                maxi.push(mini.top());
                mini.pop();
                mini.push(num);
            }
            else
                maxi.push(num);
        }
        else{
            if(num > maxi.top())
                mini.push(num);
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxi.size() == mini.size())
            return (maxi.top()+mini.top())/2.0;
        return maxi.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */