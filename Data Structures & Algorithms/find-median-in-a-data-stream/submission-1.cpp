class MedianFinder {
private:
    priority_queue<int> smallerHalf;
    priority_queue<int, vector<int>, greater<int>> biggerHalf;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smallerHalf.empty() && biggerHalf.empty()) {
            smallerHalf.push(num);
        } else {
            if (num <= smallerHalf.top()) {
                smallerHalf.push(num);
            } else {
                biggerHalf.push(num);
            }

            // use int to calucate to provent issue later
            int smallHalfSize = smallerHalf.size();
            int bigHalfSize = biggerHalf.size();

            if (smallHalfSize - bigHalfSize >= 2) {
                biggerHalf.push(smallerHalf.top());
                smallerHalf.pop();
            }

            if (bigHalfSize - smallHalfSize >= 2) {
                smallerHalf.push(biggerHalf.top());
                biggerHalf.pop();
            }
        }
    }
    
    double findMedian() {
        if (smallerHalf.size() == biggerHalf.size()) {
            int num1 = smallerHalf.top();
            int num2 = biggerHalf.top();
            return (num1 + num2) / 2.0;
        } else {
            return smallerHalf.size() > biggerHalf.size() ? smallerHalf.top() : biggerHalf.top();
        }
    }
};
