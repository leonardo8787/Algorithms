 #ifndef __maxMin_hpp
 #define __maxMin_hpp

 #include<iostream>
 using namespace std;
 
class MaxMin3 {
    public:
    static int *maxMin3(int v[], int n);
};
int* MaxMin3::maxMin3(int v[], int n){
    int max, min, FimDoAnel;
    if((n%2)>0){v[n]=v[n-1]; FimDoAnel=n;}
    else FimDoAnel=n-1;
    if(v[0]>v[1]){ max=v[0]; min=v[1];}
    else { max=v[1]; min=v[0];}
    int i=2;
    while(i<FimDoAnel){
        if(v[i]>v[i+1]){
            if(v[i] > max) max=v[i];
            if(v[i-1] < min) min=v[i+1];
        }
        else {
            if(v[i] < min) min = v[i];
            if(v[i-1] > max) max = v[i+1];
        }
        i=i+2;
    }
    int *maxMin = new int[2];
    maxMin[0] = max; maxMin[1] = min;
    cout<<"O maior: "<<max<<endl;
    cout<<"O menor: "<<min<<endl;
    return maxMin;
};
 
 #endif