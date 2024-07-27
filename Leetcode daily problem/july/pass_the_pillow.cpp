class Solution {
public:
    int passThePillow(int n, int time) {
        
        //its quite wasy 

        int turn = time/(n-1);  //if even see from start else end

        int rem = time%(n-1);

        if(turn&1)
        {
            return n-rem;
        }else return rem+1;


    }
};