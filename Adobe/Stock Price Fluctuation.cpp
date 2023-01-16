class StockPrice {
public:
    StockPrice() {     
    }
    
    void update(int timestamp, int price) {
        auto itr = tToP.find(timestamp);
        if(itr != tToP.end()) {
            pToT[itr->second]--; // delete old price
            if(pToT[itr->second] == 0) pToT.erase(itr->second);
            itr->second = price; // update new price 
            pToT[price]++;  
        } else {
          tToP[timestamp] = price;
          pToT[price]++;
        }
    }
    
    int current() {
        return tToP.rbegin()->second;
    }
    
    int maximum() {
        return pToT.rbegin()->first;
    }
    
    int minimum() {
        return pToT.begin()->first;
    }
 
private:
    //Two ordered maps should do the trick, I guess
    std::map<int, int> tToP; // TimeStamp to Price
    std::map<int,int> pToT; // Price to Count
};
