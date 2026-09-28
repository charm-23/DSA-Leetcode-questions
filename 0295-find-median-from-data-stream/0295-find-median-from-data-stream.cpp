class MedianFinder {
public:
    priority_queue<int>maxh; 
    priority_queue<int, vector<int>, greater<int>>minh; 

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxh.empty() || num<=maxh.top()) maxh.push(num); 
        else{
            minh.push(num); 
        }

        if(minh.size()>maxh.size()){
            maxh.push(minh.top()); 
            minh.pop(); 
        }

        else if(maxh.size()-minh.size()>1){
            minh.push(maxh.top()); 
            maxh.pop(); 
        }
    }
    
    double findMedian() {
        if(maxh.size()==minh.size()) return double(maxh.top()+ minh.top())/2; 
        else{
            return (double)maxh.top(); 
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */