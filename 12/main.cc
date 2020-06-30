// 矩阵中的路径
// 回溯法
#include <stdio.h>
#include <assert.h>

int findPath(char *array,int rows,int cols,char *path,int pathlength,int row,int col,int *visited){
    //判断是否越界，是否已访问
    if(row >= rows || row <0 || col >= cols || col < 0 || (visited[row*cols+col] == 1)){
        return 0;
    }
     
    if(array[row*cols+col] == path[0]){
        visited[row*cols + col] = 1;
        if(pathlength == 1){
            return 1;
        }
        // 回溯，四个可选项
        int res = findPath(array,rows,cols,path+1,pathlength-1,row-1,col,visited);//up
        if(res == 1)return 1;
        res = findPath(array,rows,cols,path+1,pathlength-1,row+1,col,visited);//down
        if(res == 1)return 1;
        res = findPath(array,rows,cols,path+1,pathlength-1,row,col-1,visited);//left
        if(res == 1)return 1;
        res = findPath(array,rows,cols,path+1,pathlength-1,row,col+1,visited);//right
        if(res == 1)return 1;
    }
    return 0;
}
int findPath(char *array,int rows,int cols,char *path,int pathLength,int *visited){
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(findPath(array,rows,cols,path,pathLength,i,j,visited) == 1){
                return 1;
            }
        }
    }
    return 0;
}
void test1(){
    char array[] = {'a','b','t','g',
                    'c','f','c','s',
                    'j','d','e','h'
                    };
    int row = 3,col = 4;
    char path[] = "abtc";
    int visited[row*col] ;
    for(int i = 0;i<row*col;i++){
        visited[i] = 0;
    }
    int res = findPath(array,row,col,path,sizeof(path)/sizeof(path[0])-1,visited); 
    assert(res == 1);
}
void test2(){
    char array[] = {'a','b','t','g',
                    'c','f','c','s',
                    'j','d','e','h'
                    };
    int row = 3,col = 4;
    char path[] = "abtb";
    int visited[row*col] ;
    for(int i = 0;i<row*col;i++){
        visited[i] = 0;
    }
    int res = findPath(array,row,col,path,sizeof(path)/sizeof(path[0])-1,visited); 
    assert(res == 0);
}
void test3(){
    char array[] = {'a','b','t','g',
                    'c','f','c','s',
                    'j','d','e','h'
                    };
    int row = 3,col = 4;
    char path[] = "bss";
    int visited[row*col] ;
    for(int i = 0;i<row*col;i++){
        visited[i] = 0;
    }
    int res = findPath(array,row,col,path,sizeof(path)/sizeof(path[0])-1,visited); 
    assert(res == 0);
}
void test4(){
    char array[] = {'a','b','t','g',
                    'c','s','c','s',
                    'j','d','e','h'
                    };
    int row = 3,col = 4;
    char path[] = "cshe";
    int visited[row*col] ;
    for(int i = 0;i<row*col;i++){
        visited[i] = 0;
    }
    int res = findPath(array,row,col,path,sizeof(path)/sizeof(path[0])-1,visited); 
    assert(res == 1);
}
void test5(){
    char array[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    int row = 5,col = 8;
    char path[] = "SGGFIECVAASABCEEJIGOEM";
    int visited[row*col] ;
    for(int i = 0;i<row*col;i++){
        visited[i] = 0;
    }
    int res = findPath(array,row,col,path,sizeof(path)/sizeof(path[0])-1,visited); 
    assert(res == 0);    
}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
}