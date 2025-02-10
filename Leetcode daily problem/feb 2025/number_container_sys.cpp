class NumberContainers {
public:

//it can be easily done by 2 map --- one to keep the track of index 
//and corresponding number and other is for the number whicih is the 
//rescent index --- 
//some sort of set also need to be kept is latest --- 

unordered_map<int,int> ind;
unordered_map<int,set<int>> latest;

    NumberContainers() {       
    }
    
    void change(int index, int number) {
       
       //lets erase the index from the set for the given number -- 
       latest[ind[index]].erase(index);
       latest[number].insert(index);
       ind[index] = number;
    }
    
    int find(int number) {
        
        if(latest[number].empty()) return -1;
        auto it = latest[number].begin();
        return *it;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */