//https://leetcode.com/problems/word-ladder/
//https://www.youtube.com/watch?v=tRPda0rcf8E

class Solution {
public:
    
    //TC: N* word.length()*26
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Doing BFS
        unordered_set<string> st(wordList.begin(),wordList.end() );
        queue<pair<string,int> > qu;
        
        qu.push({beginWord,1});
        
        st.erase(beginWord);
        //removing values which are being used because second time if we got that string it will give us larger route i.e. ans 
        
        while(qu.size()){
           
            auto frontVal = qu.front();
            qu.pop();
            string str = frontVal.first;
            
            int len = str.length();
            int dis = frontVal.second;
            
            //if we got endWord it means we got our shortest path!!!
            if(str==endWord){
                return dis;
            }
            
            //travelling to all characters of string
            for(int i=0;i<len;i++){
                char ch = str[i];
                //changing every single characters from a to z and checking whether it is present in our set or not
                for(char alpha='a'; alpha<='z'; alpha++){
                    
                    if(alpha != ch){    //it should not be equal to our original character
                        str[i]=alpha;
                        if(st.find(str) != st.end()){
                            qu.push({str,dis+1});
                            st.erase(str);      //it is visited so just remove it from set
                        }
                    }
                }
                str[i] = ch;       
                //back to original str
            }
            
        }
        
        return 0;  
        //no path is there
    }
};
