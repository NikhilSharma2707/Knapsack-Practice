#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct item{

double weight;
double value;
double ratio;
};

bool compare(item A, item B){

    return A.ratio>B.ratio;

}

double Knapsack(vector<item>& items, double capacity){

sort(items.begin(),items.end(),compare);

double total_value=0.0;

for(size_t i=0;i<items.size();++i){

    if(capacity>=items[i].weight){

        capacity=capacity - items[i].weight;
        total_value= total_value + items[i].value;
    }

    else{

            total_value=total_value+(items[i].ratio)*capacity;


    }

}

return total_value;

}

int main(){
double n;
double capacity;

cout<<"THIS IS KNAPSACK ALGORITHM"<<endl;
cout<<"Enter The Number Of Elements:-"<<endl;
cin>>n;

vector<item> items(n);
cout<<"Enter the capacity of knapsack:-"<<endl;
cin>>capacity;
cout<<"Enter The Weights and Values Of Each Element:-"<<endl;

for(int i=0;i<n;i++){

    cout<<"Enter the weight of the element"<<i+1<<":";
    cin>>items[i].weight;
    cout<<"Enter the value of the element"<<i+1<<":";
    cin>>items[i].value;

    items[i].ratio= static_cast <double>(items[i].value/items[i].weight);


}

double knap_ans=Knapsack(items,capacity);
cout<<"The Total Value Is:-"<<knap_ans;

return 0;


}
