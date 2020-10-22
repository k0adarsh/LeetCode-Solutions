class Solution {
public:

    typedef long long int ll;
    bool doIntersect(int A,int B,int C,int D,int E,int F,int G,int H){

        if(C<=E || G<=A || B>=H || F>=D)
            return false;
        return true;
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        int X1,Y1,X2,Y2;
        if(!doIntersect(A,B,C,D,E,F,G,H)){
            return abs(C-A)*abs(D-B) + abs(H-F)*(G-E);
        }
        if(A < E)
            X1 = E;
        else
            X1 = A;
        if(B > F)
            Y1 = B;
        else
            Y1 = F;
        if(G < C)
            X2 = G;
        else
            X2 = C;
        if(H < D)
            Y2 = H;
        else
            Y2 = D;
        ll ans = (ll)abs(C-A)*abs(D-B) + (ll)abs(H-F)*abs(G-E) - (ll)abs(Y2-Y1)*abs(X2-X1);
        return (int)ans;
    }
};
