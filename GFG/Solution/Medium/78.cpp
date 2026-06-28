class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        // int flips = 0;
        // while(level > 1){
        //     if(pos % 2 == 0) flips++;
        //     pos = (pos + 1) / 2;
        //     level--;
        // }
        // return (flips % 2 == 0) ? "Engineer" : "Doctor";
        return (__builtin_popcount(pos - 1) % 2 == 0) ? "Engineer" : "Doctor";
    }
};