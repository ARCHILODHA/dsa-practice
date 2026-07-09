// Flood Fill Algorithm

#include<iostream>
#include<vector>
using namespace std;

void fill(vector<vector<int>>& image,int x,int y,int old,int color){

    if(x<0||y<0||x>=image.size()||y>=image[0].size())
        return;

    if(image[x][y]!=old)
        return;

    image[x][y]=color;

    fill(image,x+1,y,old,color);
    fill(image,x-1,y,old,color);
    fill(image,x,y+1,old,color);
    fill(image,x,y-1,old,color);

}

int main(){

    vector<vector<int>> image={{1,1,1},{1,1,0},{1,0,1}};

    fill(image,1,1,1,2);

    cout<<"Flood Fill Completed";

}
