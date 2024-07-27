class Solution {
public:
    int numWaterBottles(int numB, int numE) {
        
        //its easy --

        //initially all the bottles are full 

        int ans = numB;
        int empty= numB;

        while(empty>=numE)
        {
            ans+=empty/numE;
            empty=empty/numE+empty%numE;
        }

        return ans;
    }
};