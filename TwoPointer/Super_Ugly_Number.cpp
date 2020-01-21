class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int length = primes.size();
        if(n == 1) 
            return 1;
        /**
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(int element : primes)
            pq.push(element);
        
        set<long long> contains_element;
        int counter = 1;
        long long answer = 0;
        while(!pq.empty()) {
            long long smallest = pq.top();
            pq.pop();
            counter++;
            if(counter == n) {
                answer = smallest;
                break;
            }
            for(int element: primes) {
                if(contains_element.find(element * smallest) == contains_element.end()) {
                    pq.push(1ll * element * smallest);
                    contains_element.insert(1ll * element * smallest);
                }
            }
        }
        return answer;
        */
        /* set<long long> all_elements;
        vector<long long> answer;
        for(int element : primes)
            all_elements.insert(element);
        for(int counter=1;counter<n;counter++) {
            long long mul = *all_elements.begin();
            for(int element : primes) {
                all_elements.insert(1ll * mul * element);
            }
            answer.push_back(mul);
            all_elements.erase(all_elements.begin());
        }
        return answer.back();
        */
        
        vector<long long> answer;
        answer.push_back(1ll);
        vector<int> array_of_pointers(length, 0);
        while(answer.size() < n) {
            long long min_value = INT_MAX;
            int min_index = -1;
            for(int i=0;i<length;i++) {
                if(answer[array_of_pointers[i]] * 1ll * primes[i] <= min_value) {
                    min_index = i;
                    min_value = answer[array_of_pointers[i]] * 1ll * primes[i];
                }
            }
            if(answer.back() != min_value) 
                answer.push_back(min_value);

            array_of_pointers[min_index]++;
        }
        return answer.back();
    }
};