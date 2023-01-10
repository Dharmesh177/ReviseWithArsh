class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
//         vector<string> name,city;
//         vector<int> amt,time;
//         for(auto x : transactions)
//         {
//             string temp="";
//             int i=0;
//          while(x[i]!=','){
//              temp+=x[i];
//              i++;
//          }
//             name.push_back(temp);
//               temp="";i++;
//              while(x[i]!=','){
//              temp+=x[i];
//              i++;
//          }
//             time.push_back(stoi(temp));
//              temp="";i++;
//              while(x[i]!=','){
//              temp+=x[i];
//              i++;
//          }
//             amt.push_back(stoi(temp));
//              temp="";i++;
//              while(x[i]!=','){
//              temp+=x[i];
//              i++;
//          }
//             city.push_back(temp);    
//         } 
        
//        vector<int> ind;
//         for(int i=0; i<transactions.size(); i++){
//             if(time[i]>1000){
//                 ind.push_back(i);
//             }
//         }
        
//         for(int i=0; i<transactions.size()-1; i++){
//            if(name[i]==name[i+1]){
//                if(city[i]==city[i+1]){
//                    if(time[i+1]-time[i]<60){
//                        ind.push_back(i);
//                    }
//                }
//            }
//         }
//         vector<string> ans;
//          for(int i=0; i<ind.size(); i++){
//           ans.push_back(transactions[ind[i]]);
//         }
        
        
        
//         return ans;
        //variables and vectors
        int flag=0;
        vector<string>name;
        vector<int>time;
        vector<int>amount;
        vector<string>city;
        vector<string>res;
        
		//iterating over transactions vector
        for(auto str:transactions){
            stringstream ss(str);
            string st;
            
			//splitting components of transactions vector based on the delimiter
            while(getline(ss,st,',')){
                if(flag==0){
                    name.emplace_back(st);
                    flag=1;
                }
                else if(flag==1){
                    time.emplace_back(stoi(st));
                    flag=2;
                }
                else if(flag==2){
                    amount.emplace_back(stoi(st));
                    flag=3;                    
                }
                else if(flag==3){
                    city.emplace_back(st);
                    flag=0;                    
                }
            }                    
        }
        
		
		//traversing for invalid transactions where amount>1000
        int j=0;
        for(auto it:amount){
            if(it>1000){
                res.emplace_back(transactions[j]);                
            }
            j++;
        }
        
		//traversing for invalid transactions with same name and different cities
        for(int i=0;i<transactions.size();i++){
            for(int j=0;j<transactions.size();j++){
                if(name[i]==name[j] && city[i]!=city[j]){
                    if(abs(time[i]-time[j])<=60){
                        if(amount[i]<=1000){
                            res.emplace_back(transactions[i]);
                            break;
                        }
                    }
                }
            }
        }
		
		//returning final vector containing result
        return res;
    }
};