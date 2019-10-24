#include<cstdio>  
#include<cstdlib>  
using namespace std;  
int main(){  
    for(int i=1;i<=1e5;i++){  
        #ifdef __linux  
        printf("You are on Linux!\n#####################\n");  
        system("./gen && ./sol && ./bf");  
        if(!system("diff tmpSol.out tmpBf.out"))  
        #endif  
        #ifdef _WIN32  
        printf("You are on Windows!\n#####################\n");  
        system("gen && sol && bf");  
        if(!system("fc tmpSol.out tmpBf.out"))  
        #endif  
        {  
            printf("Point #%d:\nAC~~ Ni GuoAK le~\n",i);  
        }  
        else{  
            printf("Point #%d:\nWA!! Ni Hoi U Jok Ba~\n",i);  
            break;  
        }  
    }  
    return 0;  
}  