// n queens

#include<stdio.h>
#include<stdlib.h>
int a[20],count=0,n;
int notsafe(int pos){
    for(int i=1;i<pos;i++){
        if(a[i]==a[pos] || abs(a[i]-a[pos])==abs(i-pos))
            return 1;
    }
    return 0;
}
void print_solution(){
    count++;
    printf("Solution# %d\n\n",count);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==j){
                printf("Q\t");
            }
            else{
                printf("*\t");
            }
        }
        printf("\n");
    }
}
void queen(){
    int q=1;
    a[q]=0;
    while(q!=0){
        a[q]++;
        while(a[q]<=n && notsafe(q))
            a[q]++;
        if(a[q]<=n){
            if(n==q){
                print_solution();
            }
            else{
                q++;
                a[q]=0;
            }
        }
        else{
            q--;
        }
    }
}
void main(){
    printf("Enter the number of queens: \n");
    scanf("%d",&n);
    queen();
    printf("the total number of solutions are %d \n",count);
}


// travelling sales person
/* 
#include<stdio.h>
int cost[10][10],visited[10]={0},i ,j,current,sum=0,p,min,n,s;
void tsp(){
    current=s;
    for(int j=1;j<n;j++){
        min=999;
        for(int i=1;i<=n;i++){
            if(cost[current][i]<min && visited[i]==0){
                min=cost[current][i];
                p=i;
            }
        }
        visited[p]=1;
        printf("City %d-->",p);
        current=p;
        sum+=min;
    }
    printf("City %d\n",s);
    sum+=cost[current][s];
    printf("\nThe total cost is %d :",sum);
}
void main(){
    printf("Enter the number of cities : ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix : \n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=9999;
            }
        }
    }
    printf("\nEnter the source vertex : ");
    scanf("%d",&s);
    visited[s]=1;
    printf("City %d--> ",s);
    tsp();
}
*/

// Dynamic knapsack
/*
#include<stdio.h>
int w[10],x[10]={0},p[10],i,j,v[10][10],m,n;
int max(int i,int j){
    if(i>j)
        return i;
    return j;
}
int knap(int i,int j){
    if(v[i][j]<0){
        if(w[i]>j)
            v[i][j]=knap(i-1,j);
        else
            v[i][j]=max(knap(i-1,j),knap(i-1,j-w[i])+p[i]);
    }
    return v[i][j];
}
void main(){
    printf("Enter the number of objects : ");
    scanf("%d",&n);
    printf("Enter the profits for objects : \n");
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("Enter the weights for the objects : \n");
    for(int i =1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("Enter the maximum capacity of the sack : ");
    scanf("%d",&m);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                v[i][j]=0;
            }
            else{
                v[i][j]=-1;
            }
        }
    }
    int res=knap(n,m);
    i=n;
    j=m;
    while(i!=0 && j!=0){
        if(v[i][j]!=v[i-1][j]){
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    printf("Solution for the knapsack problem *****\n");
    printf("Object  weight  profit \n ");
    for(int i=1;i<=n;i++){
        if(x[i]){
            printf("%d\t%d\t%d\t\n",i,w[i],p[i]);
        }
    }
    printf("the total profit is : %d",res);
}
*/

// knap
/*
#include<stdio.h>
int w[10],p[10];
double x[10]={0},d[10],sum=0.0,res=0.0;
void profitsort(int n){
    double temp;
    int temp1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(d[j]<d[j+1]){
                temp=d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
                temp1=w[i];
                w[i]=w[i+1];
                w[i+1]=temp1;
                temp1=p[i];
                p[i]=p[i+1];
                p[i+1]=temp1;
            }
        }
    }
}

void display(int n){
    printf("profit weight quantity\n");
    for(int i=0;i<n;i++){
        printf("%d\t %d\t %0.2f\n",p[i],w[i],x[i]);
        sum= sum+(p[i]*x[i]);
        res=res+(w[i]*x[i]);
    }
    printf("total profit of the knapsack is :%0.2f\n",sum);
    printf("total weight of the knapsack is :%0.2f\n",res);
}
void knapsack(int n,int m){
    int remaining = m;
    int i;
    for( i=0;i<n;i++){
        if(w[i]<=remaining){
            x[i]=1.0;
            remaining-=w[i];
        }
        else{
            break;
        }
    }
    if(i<=n){
        x[i]=(double)remaining/w[i];
    }
}

void main(){
    int n,m;
    printf("Enter the number of objects : ");
    scanf("%d",&n);
    printf("Enter the profits for objects : ");
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Enter the weights for the objects : ");
    for(int i =0;i<n;i++)
        scanf("%d",&w[i]);
    printf("Enter the maximum capacity of the sack : ");
    scanf("%d",&m);
    for(int i=0;i<n;i++){
        d[i]=(double)p[i]/w[i] ;
    }
    profitsort(n);
    knapsack(n,m);
    display(n);
}

*/

//dijkstra algorithm
/*
#include<stdio.h>
#define infinity 99999
struct sht{
    int dist;
    int path;
    int known;
    
};
struct sht a[15];
int main(){
    int i,j,k,v,n,s,min,adj[15][15];
    printf("Enter the number of vertices :");
    scanf("%d",&n);
    printf("Enter the adjacency matrix : \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);
    for(i =1;i<=n;i++){
        a[i].dist=infinity;
        a[i].known=0;
        a[i].path=0;
    }
    printf("enter the starting vertex : ");
    scanf("%d",&s);
    a[s].dist=0;
    for(i=1;i<=n;i++){
        min=infinity;
        for(j=1;j<=n;j++){
            if(a[j].dist<=min && a[j].known==0){
                v=j;
                min=a[j].dist;
            }
        }
        a[v].known=1;
        for(k=1;k<=n;k++){
            if(adj[v][k]!=0 && a[v].dist+adj[v][k]<a[k].dist){
                a[k].dist=a[v].dist+adj[v][k];
                a[k].path=v;
            }
        }
    }
    printf("\n******************** Solution *******************\n");
    printf("vertex path known distance\n");
    for(i=1;i<=n;i++)
        printf("%d\t%d\t%d\t%d\t\n",i,a[i].path,a[i].known,a[i].dist);
    printf("****************************************************\n");
}

*/

// kruskals
/*
#include<stdio.h>
int parent[20];
int findparent(int i){
    while(parent[i])
        i=parent[i];
    return i;
}
int notloop(int i, int j){
    if(i!=j) {
        i=parent[j];
        return 1;
    }
    return 0;
}
void main(){
    int i,j,a,b,u,n,cost[20][20],visited[20]={0},min,k,v,mincost=0,ne=1;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix  :\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]==99999;
        }
    }
    printf("The edges of the minimum cost spanning tree are\n");
    while(ne<n){
        min=99999;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        v=findparent(v);
        u=findparent(u);
        if(notloop(u,v)){
            printf("Edge number %d is (%d,%d) and its cost is %d \n",ne++,a,b,min);
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=99999;
    }
    printf("The minimum cost of the spanning tree is %d \n",mincost);
}
*/

//prims algorithm
/* 

#include<stdio.h>
#define max 10
void main(){
    int a, b, u, v, n, i, j, s, ne = 1;
    int visited[max] = {0}, min, mincost = 0, cost[max][max];
    printf("\n ***** Prim's Algorithm *******\n");
    printf("\n Enter the number of vertices ::");
    scanf("%d", & n);
    printf("\n Enter the adjacency matrix :: \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", & cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    printf("\nEnter the source vertex ::");
    scanf("%d", &s);
    visited[s]=1;
    printf("The edges of the minimum cost spanning tree are :\n");
    while(ne<n){
        min=99999;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min && visited[i]==1){
                    u=a=i;
                    v=b=j;
                    min=cost[i][j];
                }
            }
        }
        mincost+=min;
        printf("The edge number %d is (%d,%d) and the cost is %d\n",ne++,a,b,min);
        visited[v]=1;
        cost[a][b]=cost[b][a]=99999;
    }
    printf("The minimum cost of the tree is :%d",mincost);
}

*/

//job sequencing
/*

#include<stdio.h>
int j[10],p[10],d[10],n,profit=0;
void jobsort(){
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            if(p[i]<p[k]){
                int temp=d[k];
                d[k]=d[i];
                d[i]=temp;
                temp=j[i];
                j[i]=j[k];
                j[k]=temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
            }
        }
    }
}
void jobseq(){
    int seq[10]={0};
    for(int i=0;i<n;i++){
        for(int k=d[i]-1;k>=0;k--){
            if(seq[k]==0){
                seq[k]=j[i];
                profit+=p[i];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(seq[i]!=0){
            printf("J%d\t",j[i]);
        }
    }
    printf("Total profit : %d",profit);
}
int main(){
    printf("Enter the no.of jobs:");
    scanf("%d",&n);
    printf("Enter the deadlines :\n");
    for(int i =0;i<n;i++)
        scanf("%d",&d[i]);
    for(int i =0;i<n;i++)
        j[i]=i+1;
    printf("Enter the profits :\n");
    for(int i =0;i<n;i++)
        scanf("%d",&p[i]);
    jobsort();
    jobseq();
}

*/

//avl tree
/*    
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
    int ht;
};
struct node* root = NULL;
struct node* create(int);
struct node* insert(struct node*, int);
struct node* rotate_left(struct node*);
struct node* rotate_right(struct node*);
int balance_factor(struct node*);
int height(struct node*);
void inorder(struct node*);
int main(){
    int choice, data;
    struct node* result = NULL;
    while (1) {
        printf("\n\n------- AVL TREE --------\n");
        printf("\n1. Insert");
        printf("\n2. Inorder");
        printf("\n3.EXIT");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("\n\tProgram Terminated\n");
            return 1;
        default:
            printf("\n\tInvalid Choice\n");
        }
    }
    return 0;
}
struct node* create(int data){
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
// rotates to the left
struct node* rotate_left(struct node* root){
    struct node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
    // update the heights of the nodes
    root->ht = height(root);
    right_child->ht = height(right_child);
    // return the new node after rotation
    return right_child;
}
// rotates to the right
struct node* rotate_right(struct node* root){
    struct node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
    // update the heights of the nodes
    root->ht = height(root);
    left_child->ht = height(left_child);
    // return the new node after rotation
    return left_child;
}
// calculates the balance factor of a node
int balance_factor(struct node* root){
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}
// calculate the height of the node
int height(struct node* root){
    int lh, rh;
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    if (lh > rh)
        return (lh);
    return (rh);
}
// inserts a new node in the AVL tree
struct node* insert(struct node* root, int data){
    if (root == NULL) {
        struct node* new_node = create(data);
        if (new_node == NULL) {
            return NULL;
        }
        root = new_node;
    } else if (data > root->data) {
        // insert the new node to the right
        root->right = insert(root->right, data);
        // tree is unbalanced, then rotate it
        if (balance_factor(root) == -2) {
            if (data > root->right->data) {
                root = rotate_left(root);
            } else {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    } else {
        // insert the new node to the left
        root->left = insert(root->left, data);
        // tree is unbalanced, then rotate it
        if (balance_factor(root) == 2) {
            if (data < root->left->data) {
                root = rotate_right(root);
            } else {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    // update the heights of the nodes
    root->ht = height(root);
    return root;
}
// inorder traversal of the tree
void inorder(struct node* root){
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

*/




