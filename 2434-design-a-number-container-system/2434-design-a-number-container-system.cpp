class NumberContainers {
public:
    unordered_map<int,int>indexsenumber;
    unordered_map<int,set<int>>numberseindex;

    NumberContainers() {
        //constructure
    }
    
    void change(int index, int number) {
        if (indexsenumber.find(index)!=indexsenumber.end()){
            int prev=indexsenumber[index];
            numberseindex[prev].erase(index);
            if(numberseindex[prev].size()==0)numberseindex.erase(prev);
        }
        indexsenumber[index]=number;
        numberseindex[number].insert(index);
    }
    
    int find(int number) {
        if (numberseindex.find(number)!=numberseindex.end()){
            return *(numberseindex[number].begin());
        }
        return -1;
    }

};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */