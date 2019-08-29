vector<int> arr,minimum;
MinStack::MinStack() {
    arr.clear();
    minimum.clear();
    
}

void MinStack::push(int x) {
    arr.push_back(x);
    if(minimum.empty())
        minimum.push_back(x);
    else if(x < minimum.back())
        minimum.push_back(x);
}

void MinStack::pop() {
    if(arr.empty())
        return;
    int x=  arr.back();
    arr.pop_back();
    if(x == minimum.back())
        minimum.pop_back();
}

int MinStack::top() {
    if(arr.empty())
        return -1;
    int x = arr.back();
    return x;
}

int MinStack::getMin() {
    if(minimum.empty())
        return -1;
    int x = minimum.back();
    return x;
}

