#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    double data;
    struct node *right, *down;
} node;
//Function prototypes
double** createmat(double v1, double v2,double v3);
node* constructLinkedMatrix(double** mat, int m, int n);
double** createMatrix(double v1, double v2, double v3);
void printLinkedMatrix(node* head);
void scalarProduct(node* head, double scalar);
void matSum(node* h1, node* h2);
double vectorNorm(node* head);
void createDatMat(char* filename, node* head);
node* newNode(double d) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->right = NULL;
    temp->down = NULL;
    return temp;
}
  //Function to construct a linked matrix from a 2D array.	 
node* constructLinkedMatrix(double** mat, int m, int n) {
    node* mainHead = NULL;
    node* rowHead[m];
    node* rightTemp = NULL;
  
    for (int i = 0; i < m; i++) {
        rowHead[i] = NULL;
        for (int j = 0; j < n; j++) {
            node* newPtr = newNode(mat[i][j]);
            if (!mainHead) {
                mainHead = newPtr;
            }
            if (!rowHead[i]) {
                rowHead[i] = newPtr;
            } else {
                rightTemp->right = newPtr;
            }
            rightTemp = newPtr;
        }
    }
  
    for (int i = 0; i < m - 1; i++) {
        node* temp1 = rowHead[i];
        node* temp2 = rowHead[i + 1];
  
        while (temp1 && temp2) {
            temp1->down = temp2;
            temp1 = temp1->right;
            temp2 = temp2->right;
        }
    }
  
    return mainHead;
}
// function to create the matrix 
double** createmat(double v1, double v2,double v3) {
    double** vector = (double**)malloc(2 * sizeof(*vector));
    for(int i = 0; i < 3; i++)
        vector[i] = (double*)malloc(2 * sizeof(vector));

    vector[0][0] = v1;
    vector[1][0] = v2;
    vector[2][0] = v3;
    return vector;
}


double** createMatrix(double v1, double v2, double v3) {
    double** matrix = (double**)malloc(2 * sizeof(*matrix));
    for (int i = 0; i < 3; i++) 
        matrix[i] = (double*)malloc(2 * sizeof(matrix));

    matrix[0][0] = v1;
    matrix[1][0] = v2;
    matrix[2][0] = v3;


    return matrix;
}
void printLinkedMatrix(node* head) {
    node* rowPtr = head;
    node* colPtr = NULL;

    while (rowPtr) {
        colPtr = rowPtr;
        while (colPtr) {
            printf("%.6lf ", colPtr->data);
            colPtr = colPtr->right;
        }
        printf("\n");
        rowPtr = rowPtr->down;
    }
}
// function for finding scalar product
void scalarProduct(node* head, double scalar) {
    node* rowPtr = head;
    node* colPtr = NULL;

    while (rowPtr) {
        colPtr = rowPtr;
        while (colPtr) {
            colPtr->data *= scalar;
            colPtr = colPtr->right;
        }
        rowPtr = rowPtr->down;
    }
}
// function for finding the matrix sum
void matSum(node* h1, node* h2) {
    node *rp1, *rp2, *dp1 = h1, *dp2 = h2;
    
    while(dp1 && dp2) {
        rp1 = dp1;
        rp2 = dp2;
        while(rp1 && rp2) {
            rp1->data = rp1->data + rp2->data;    
            rp1 = rp1->right;
            rp2 = rp2->right;
        }
        dp1 = dp1->down;
        dp2 = dp2->down;
    }
}
// function  for finding the norm
double vectorNorm(node* head) {
    node* rowPtr = head;
    node* colPtr = NULL;
    double norm = 0.0;

    while (rowPtr) {
        colPtr = rowPtr;
        while (colPtr) {
            norm += colPtr->data * colPtr->data;
            colPtr = colPtr->right;
        }
        rowPtr = rowPtr->down;
    }

    return sqrt(norm);
}
// function for writing of matrix in dat file
void createDatMat(char* filename, node* head) {
    FILE *fp = fopen(filename, "w");
    node *rp, *dp = head;
    
    while (dp) {
        rp = dp;       
        while (rp) {
            fprintf(fp, "%lf" ,rp->data);
            rp = rp->right;
        }
        fprintf(fp, "\n");
        dp = dp->down;
    }
}
