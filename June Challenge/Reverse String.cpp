void reverseString(vector<char>& s) {
        int n = s.size(),i;
        for(i=0;i<n/2;i++)
            swap(s[i],s[n-i-1]);
    }
