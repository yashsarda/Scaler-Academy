// Reference:- http://bhrigu.me/blog/2017/01/22/lru-cache-c-plus-plus-implementation/#targetText=LRU%20Cache%20%2D%20C%2B%2B%20Implementation,when%20the%20memory%20is%20full.
// Node class is used for defining a particular node of DLL
class Node
{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    
    Node(int k,int v): key(k), value(v), next(nullptr), prev(nullptr) {}
};
// DLL class defines the complete doubly linked list 
class DLL 
{
    Node* front;
    Node* rear;
    
    bool isEmpty() {
        return rear == nullptr;
    }
    
    public:
    DLL(): front(nullptr), rear(nullptr) {}
    
    // This function adds a new page to the head of the LL
    Node* add_to_head(int key, int value)
    {
        Node* page = new Node(key, value);
        if(!front && !rear) {
            front = rear = page;
        }
        else {
            page -> next = front;
            front -> prev = page;
            front = page;
            page -> prev = nullptr;
        }
        return page;
    }
    
    // This function moves any page in the cache to the head of the LL
    void move_to_head(Node* page)
    {
        if(page == front)
            return;
        
        if(page == rear) {
            rear = rear -> prev;
            rear -> next = nullptr;
        }
        else {
            page -> prev -> next = page -> next;
            page -> next -> prev = page -> prev;
        }
        
        page -> next = front;
        page -> prev = nullptr;
        front -> prev = page;
        front = page;
    }
    
    // This function removes the rear node from the LL
    void remove_from_rear()
    {
        if(isEmpty())
            return;
        
        if(front == rear) {
            delete rear;
            front = rear = nullptr;
        }
        else {
            Node* temp = rear;
            rear = rear -> prev;
            rear -> next = nullptr;
            delete temp;
        }
    }
    
    // This gives a reference to the rear node
    Node* get_rear() {
        return rear;
    }
};
class LRU
{
    int capacity;
    int size;
    
    DLL* list;
    unordered_map<int, Node*> pageMap;
    
    public: 
    LRU() 
    {
        
    }
    LRU(int cap)
    {
        capacity = cap;
        size = 0;
        list = new DLL();
    }
    
    int get_item(int key)
    {
        // If the item is not found in the map, return -1;
        if(pageMap.find(key) == pageMap.end())
            return -1;
        
        // Return the value of the item and move the item to the head of the LL
        int value = pageMap[key] -> value;
        list -> move_to_head(pageMap[key]);
        return value;
    }
    
    void put_item(int key, int value)
    {
        // If it find the page in the LL, just update its value
        // And move to the head of the LL
        if(pageMap.find(key) != pageMap.end()) {
            pageMap[key] -> value = value;
            list -> move_to_head(pageMap[key]);
            return;
        }
        
        // If it's no in the LL, just check if the cache is full
        // if it is remove from the LL 
        if(size == capacity) {
            int k = list -> get_rear() -> key;
            pageMap.erase(k);
            list -> remove_from_rear();
            size--;
        }
        // Add a new page to the head of the LL
        Node* page = list -> add_to_head(key, value);
        size++;
        pageMap[key] = page;
    }
};
LRU* cache;
LRUCache::LRUCache(int capacity) {
    cache = new LRU(capacity);
}

int LRUCache::get(int key) {
    int value = cache -> get_item(key);
    return value;
}

void LRUCache::set(int key, int value) {
    cache -> put_item(key, value);
}
