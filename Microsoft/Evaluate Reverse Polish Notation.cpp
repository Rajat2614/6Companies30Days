int evalRPN(vector<string>& tok) {
        stack<long long> st;
        long long val;
        for(int i=0;i<tok.size();i++){
            if(tok[i]=="+" || tok[i]=="-" || tok[i]=="*" || tok[i]=="/"){
                long long sec = st.top();
                st.pop();
                long long fir = st.top();
                st.pop();
                
                if(tok[i] =="+")
                    val = fir+sec;
                
                else if(tok[i]=="-")
                    val = fir-sec;
                
                else if(tok[i]=="*")
                    val = fir*sec;
                
                else if(tok[i]=="/")
                    val = fir/sec;
            }
            else{
                val = stoi(tok[i]);
            }
            st.push(val);
        }
        
     return (int)st.top();
}
