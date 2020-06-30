// 替换空格为%20
#include <stdio.h>
#include <assert.h>
#include <string.h>
void replace(char *str,int length){
    if(str == nullptr)return;
    int spacecount = 0;
    int reallength = 0;
    for(int i=0;i<length;i++){
        
        if(str[i] == '\0')break;
        reallength++;
        if(str[i] == ' ')spacecount++;
    }

    int length2 = reallength + spacecount*2;
    assert(length2 < length);
    int p1 = reallength - 1;
    int p2 = length2 - 1;
    for(;p1 >= 0;p1--){
        if(str[p1] != ' '){
            str[p2] = str[p1];
            p2--;
        }else{
            str[p2] = '0';
            str[p2-1] = '2';
            str[p2-2] = '%';
            p2 -= 3;
        }
    }
    return ;
}
void test1(){
    char str[100] = "we a a";
    replace(str,sizeof(str)/sizeof(str[0]));
    assert(strcmp(str,"we%20a%20a") == 0);
}
void test2(){
    char str[100] = " we a a";
    replace(str,sizeof(str)/sizeof(str[0]));
    assert(strcmp(str,"%20we%20a%20a") == 0);
}
void test3(){
    char str[100] = "we a a ";
    replace(str,sizeof(str)/sizeof(str[0]));
    assert(strcmp(str,"we%20a%20a%20") == 0);
}
void test4(){
    char str[100] = "weaa";
    replace(str,sizeof(str)/sizeof(str[0]));
    assert(strcmp(str,"weaa") == 0);
}
void test5(){
    char str[100] = "";
    replace(str,sizeof(str)/sizeof(str[0]));
    assert(strcmp(str,"") == 0);
}
void test6(){
    char str[100] = " ";
    replace(str,sizeof(str)/sizeof(str[0]));
    assert(strcmp(str,"%20") == 0);
}
void test7(){
    char str[100] = "we  aaa a";
    replace(str,sizeof(str)/sizeof(str[0]));
    assert(strcmp(str,"we%20%20aaa%20a") == 0);
}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}