class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int A1 = 0 , A2 = 0 , CA=0;
        A1 = (ax2-ax1)*(ay2-ay1);
        A2 = (bx2-bx1)*(by2-by1);
        if(ax2<bx1 || bx2<ax1 || by2<ay1 || ay2<by1){
            return A1+A2;
        }
        else {
            int cl = min(bx2 , ax2) - max(bx1,ax1);
            int cb = min(ay2 , by2) - max(by1,ay1);
            CA = cl*cb;
        }
        return A1+A2-CA;
    }
};